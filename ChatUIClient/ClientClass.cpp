#include "ClientClass.h"

std::vector<std::string> messageArray;
SOCKET Connection;

const char* toCChar(System::String^ str) {
    char* result_str = new char[str->Length + 1];
    for (int i = 0; i < str->Length; i++) {
        result_str[i] = str[i];
    }
    result_str[str->Length] = '\0';
    return result_str;
}

ClientClass::ClientClass()
{
    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2, 1);
    if (WSAStartup(DllVersion, &wsaData) != 0) {
        exit(1);
    }

    addr = new SOCKADDR_IN;
    addr->sin_addr.s_addr = inet_addr("127.0.0.1");
    addr->sin_port = htons(1111);
    addr->sin_family = AF_INET;
    addr_size = sizeof(*addr);

    Connection = socket(AF_INET, SOCK_STREAM, NULL);

}


ClientClass::~ClientClass()
{
    delete addr;
}

bool ClientClass::CtrlHandler(DWORD fdwCtrlType)
{
	return false;
}

void ClientClass::EmitEvent() {
    ClientClass::eventReciveMessage();
}

void ClientClass::MessageHandler()
{
    char message[128];
    while (true) {
        recv(Connection, message, sizeof(message), NULL);
        messageArray.push_back(std::string(message));
        //EmitEvent();
        eventReciveMessage();
    }
}

std::vector<std::string>* ClientClass::GetMessageArrayPtr() {
    return &messageArray;
}

bool ClientClass::ConnectClient()
{
    if (connect(Connection, (SOCKADDR*)addr, addr_size)) {
        return false;
    }
	return true;
}

void ClientClass::DisconnectClient()
{
    const char* msg = "0";
    send(Connection, msg, sizeof(msg), NULL);
}

void ClientClass::SendMessage(System::String^ message)
{
    const char* msg = toCChar(message);
    send(Connection, msg, sizeof(msg), NULL);
}

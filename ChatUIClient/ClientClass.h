#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <Windows.h>
#include <thread>
#include <vector>
#include <string>

delegate System::Void Event();

ref class ClientClass
{
public:
	ClientClass();
	~ClientClass();

	bool CtrlHandler(DWORD fdwCtrlType);
	bool ConnectClient();
	void DisconnectClient();
	void SendMessage(System::String^ message);
	std::vector<std::string>* GetMessageArrayPtr();
	static void MessageHandler();
	
	static event Event^ eventReciveMessage;
	static void EmitEvent();


private:
	//SOCKET Connection;
	SOCKADDR_IN* addr;
	int addr_size;
};


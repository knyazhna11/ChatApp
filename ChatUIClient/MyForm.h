#pragma once
#include "ClientClass.h"

namespace ChatUIClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		//ClientClass ClClient;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxChat;
	private: System::Windows::Forms::TextBox^ textBoxMessage;
	private: System::Windows::Forms::Button^ buttonSend;
	private: System::Windows::Forms::Button^ buttonClose;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker;
	private: ClientClass^ client;

		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxChat = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->client = (gcnew ClientClass());
			this->client->eventReciveMessage += gcnew Event(this, &MyForm::MessageReciver);
			this->SuspendLayout();
			// 
			// textBoxChat
			// 
			this->textBoxChat->BackColor = System::Drawing::Color::Silver;
			this->textBoxChat->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxChat->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBoxChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxChat->Location = System::Drawing::Point(0, 30);
			this->textBoxChat->Margin = System::Windows::Forms::Padding(2);
			this->textBoxChat->Multiline = true;
			this->textBoxChat->Name = L"textBoxChat";
			this->textBoxChat->ReadOnly = true;
			this->textBoxChat->Size = System::Drawing::Size(450, 500);
			this->textBoxChat->TabIndex = 1;
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->BackColor = System::Drawing::Color::White;
			this->textBoxMessage->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxMessage->ForeColor = System::Drawing::Color::Black;
			this->textBoxMessage->Location = System::Drawing::Point(0, 532);
			this->textBoxMessage->Margin = System::Windows::Forms::Padding(2);
			this->textBoxMessage->Multiline = true;
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->ReadOnly = true;
			this->textBoxMessage->Size = System::Drawing::Size(450, 100);
			this->textBoxMessage->TabIndex = 1;
			this->textBoxMessage->Text = L"Disconnected";
			// 
			// buttonSend
			// 
			this->buttonSend->BackColor = System::Drawing::Color::DimGray;
			this->buttonSend->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSend->ForeColor = System::Drawing::Color::White;
			this->buttonSend->Location = System::Drawing::Point(370, 600);
			this->buttonSend->Margin = System::Windows::Forms::Padding(2);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(80, 30);
			this->buttonSend->TabIndex = 4;
			this->buttonSend->Text = L"Send";
			this->buttonSend->UseVisualStyleBackColor = false;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MyForm::ButtonSendClick);
			// 
			// buttonClose
			// 
			this->buttonClose->BackColor = System::Drawing::Color::White;
			this->buttonClose->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonClose->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->buttonClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClose->ForeColor = System::Drawing::SystemColors::ControlText;
			this->buttonClose->Location = System::Drawing::Point(420, 0);
			this->buttonClose->Margin = System::Windows::Forms::Padding(2);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(30, 30);
			this->buttonClose->TabIndex = 5;
			this->buttonClose->Text = L"X";
			this->buttonClose->UseVisualStyleBackColor = false;
			this->buttonClose->Click += gcnew System::EventHandler(this, &MyForm::ButtonCloseClick);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(545, 799);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->textBoxMessage);
			this->Controls->Add(this->textBoxChat);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Chat";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->backgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::BW_MessageHandler);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		textBoxMessage->Text = "Connection...";
		if (client->ConnectClient()) {
			textBoxMessage->Text = "";
			textBoxMessage->ReadOnly = false;
			this->backgroundWorker->RunWorkerAsync();
		}
	}
	private: System::Void MessageReciver() {
		while (!client->GetMessageArrayPtr()->empty()) {
			textBoxChat->Text += gcnew System::String(client->GetMessageArrayPtr()->at(0).c_str());
			//client->GetMessageArrayPtr()->erase(client->GetMessageArrayPtr()->begin(), client->GetMessageArrayPtr()->begin() + 1);
			client->GetMessageArrayPtr()->pop_back();
		}
	}
	private: System::Void BW_MessageHandler(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		ClientClass::MessageHandler();
	}
	private: System::Void ButtonSendClick(System::Object^ sender, System::EventArgs^ e) {
		client->SendMessage(textBoxMessage->Text);

		textBoxChat->Text += "You: " + textBoxMessage->Text + "\r\n";
		textBoxMessage->Text = "";
	}
	private: System::Void ButtonCloseClick(System::Object^ sender, System::EventArgs^ e) {
		client->DisconnectClient();
		Close();
	}
};
}
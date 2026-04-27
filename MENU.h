#pragma once
#include "Karatsuba.h"				// 2001230994 - Phạm Thanh Trúc 
#include "Greedy.h"					// 2001230264 - Nguyễn Huy Hoàng
#include "Dynamic_Programming.h"	// 2001230325 - Vũ Duy Hưng
namespace Nhom13BaoCaoHocPhan {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MENU
	/// </summary>
	public ref class MENU : public System::Windows::Forms::Form
	{
	public:
		MENU(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MENU()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnKaratsuba;
	private: System::Windows::Forms::Button^ btnGreedy;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btnDP;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnKaratsuba = (gcnew System::Windows::Forms::Button());
			this->btnGreedy = (gcnew System::Windows::Forms::Button());
			this->btnDP = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnKaratsuba
			// 
			this->btnKaratsuba->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnKaratsuba->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnKaratsuba->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnKaratsuba->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->btnKaratsuba->Location = System::Drawing::Point(15, 15);
			this->btnKaratsuba->Margin = System::Windows::Forms::Padding(10);
			this->btnKaratsuba->Name = L"btnKaratsuba";
			this->btnKaratsuba->Padding = System::Windows::Forms::Padding(20);
			this->btnKaratsuba->Size = System::Drawing::Size(274, 70);
			this->btnKaratsuba->TabIndex = 0;
			this->btnKaratsuba->Text = L"KARATSUBA";
			this->btnKaratsuba->UseVisualStyleBackColor = true;
			this->btnKaratsuba->Click += gcnew System::EventHandler(this, &MENU::btnKaratsuba_Click);
			// 
			// btnGreedy
			// 
			this->btnGreedy->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnGreedy->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnGreedy->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnGreedy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->btnGreedy->Location = System::Drawing::Point(309, 15);
			this->btnGreedy->Margin = System::Windows::Forms::Padding(10);
			this->btnGreedy->Name = L"btnGreedy";
			this->btnGreedy->Padding = System::Windows::Forms::Padding(20);
			this->btnGreedy->Size = System::Drawing::Size(274, 70);
			this->btnGreedy->TabIndex = 1;
			this->btnGreedy->Text = L"GREEDY";
			this->btnGreedy->UseVisualStyleBackColor = true;
			this->btnGreedy->Click += gcnew System::EventHandler(this, &MENU::btnGreedy_Click);
			// 
			// btnDP
			// 
			this->btnDP->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDP->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnDP->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->btnDP->Location = System::Drawing::Point(603, 15);
			this->btnDP->Margin = System::Windows::Forms::Padding(10);
			this->btnDP->Name = L"btnDP";
			this->btnDP->Padding = System::Windows::Forms::Padding(20);
			this->btnDP->Size = System::Drawing::Size(275, 70);
			this->btnDP->TabIndex = 2;
			this->btnDP->Text = L"DYNAMIC PROGRAMMING";
			this->btnDP->UseVisualStyleBackColor = true;
			this->btnDP->Click += gcnew System::EventHandler(this, &MENU::btnDP_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->Controls->Add(this->btnKaratsuba, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnDP, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnGreedy, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tableLayoutPanel1->Location = System::Drawing::Point(50, 391);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(5);
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(893, 100);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// MENU
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(993, 541);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MENU";
			this->Padding = System::Windows::Forms::Padding(50);
			this->Text = L"MENU";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MENU::MENU_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MENU_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void btnKaratsuba_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Karatsuba^ karatsubaForm = gcnew Karatsuba();
		karatsubaForm->ShowDialog();
		this->Show();
	}
	private: System::Void btnGreedy_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Greedy^ greedyForm = gcnew Greedy();
		greedyForm->ShowDialog();
		this->Show();
	}

	private: System::Void btnDP_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Dynamic_Programming^ dpForm = gcnew Dynamic_Programming();
		dpForm->ShowDialog();
		this->Show();
	}
};
}

#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>

namespace Nhom13BaoCaoHocPhan {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Karatsuba
	/// </summary>
	public ref class Karatsuba : public System::Windows::Forms::Form
	{
	public:
		Karatsuba(void)
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
		~Karatsuba()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^ txtKetQua;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtNhapX;
	private: System::Windows::Forms::TextBox^ txtNhapY;
	private: System::Windows::Forms::Button^ btnThucHien;
	private: System::Windows::Forms::Button^ btnLoadFile;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;



	protected:

	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Karatsuba::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtNhapX = (gcnew System::Windows::Forms::TextBox());
			this->txtNhapY = (gcnew System::Windows::Forms::TextBox());
			this->btnThucHien = (gcnew System::Windows::Forms::Button());
			this->btnLoadFile = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtKetQua = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1309, 102);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Thuật toán Karatsuba";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Karatsuba::label1_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 102);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(10);
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1309, 334);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(10);
			this->groupBox1->Size = System::Drawing::Size(638, 308);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Them thong tin";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnThucHien, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->btnLoadFile, 0, 2);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(10, 37);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->Padding = System::Windows::Forms::Padding(10);
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(618, 261);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->txtNhapX, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->txtNhapY, 1, 1);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(592, 138);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(230, 69);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Nhập số X";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(3, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(230, 69);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Nhập số Y";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtNhapX
			// 
			this->txtNhapX->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtNhapX->Location = System::Drawing::Point(239, 3);
			this->txtNhapX->Name = L"txtNhapX";
			this->txtNhapX->Size = System::Drawing::Size(350, 34);
			this->txtNhapX->TabIndex = 2;
			this->txtNhapX->TextChanged += gcnew System::EventHandler(this, &Karatsuba::txtNhapX_TextChanged);
			this->txtNhapX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Karatsuba::txtNhapX_KeyPress);
			// 
			// txtNhapY
			// 
			this->txtNhapY->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtNhapY->Location = System::Drawing::Point(239, 72);
			this->txtNhapY->Name = L"txtNhapY";
			this->txtNhapY->Size = System::Drawing::Size(350, 34);
			this->txtNhapY->TabIndex = 3;
			this->txtNhapY->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Karatsuba::txtNhapY_KeyPress);
			// 
			// btnThucHien
			// 
			this->btnThucHien->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnThucHien->Location = System::Drawing::Point(13, 157);
			this->btnThucHien->Name = L"btnThucHien";
			this->btnThucHien->Size = System::Drawing::Size(592, 42);
			this->btnThucHien->TabIndex = 1;
			this->btnThucHien->Text = L"Thực hiện thuật toán";
			this->btnThucHien->UseVisualStyleBackColor = true;
			this->btnThucHien->Click += gcnew System::EventHandler(this, &Karatsuba::btnThucHien_Click);
			// 
			// btnLoadFile
			// 
			this->btnLoadFile->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnLoadFile->Location = System::Drawing::Point(13, 205);
			this->btnLoadFile->Name = L"btnLoadFile";
			this->btnLoadFile->Size = System::Drawing::Size(592, 43);
			this->btnLoadFile->TabIndex = 2;
			this->btnLoadFile->Text = L"Đọc dữ liệu từ .txt";
			this->btnLoadFile->UseVisualStyleBackColor = true;
			this->btnLoadFile->Click += gcnew System::EventHandler(this, &Karatsuba::btnLoadFile_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txtKetQua);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->groupBox2->Location = System::Drawing::Point(657, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(639, 308);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ket qua";
			// 
			// txtKetQua
			// 
			this->txtKetQua->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtKetQua->Location = System::Drawing::Point(3, 30);
			this->txtKetQua->Multiline = true;
			this->txtKetQua->Name = L"txtKetQua";
			this->txtKetQua->ReadOnly = true;
			this->txtKetQua->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtKetQua->Size = System::Drawing::Size(633, 275);
			this->txtKetQua->TabIndex = 0;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Karatsuba
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1309, 654);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Karatsuba";
			this->Text = L"Karatsuba";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		std::string trimZeros(const std::string& s);
		std::string addString(const std::string& a, const std::string& b);
		std::string subString(const std::string& a, const std::string& b);
		std::string shiftString(const std::string& a, int n);
		std::string karatsuba(const std::string& x, const std::string& y, TextBox^ output);


	private: System::Void txtNhapX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
		{
			e->Handled = true;
		}
	}
	private: System::Void txtNhapY_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
		{
			e->Handled = true;
		}
	}
	private: System::Void btnThucHien_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ sX = txtNhapX->Text;
		String^ sY = txtNhapY->Text;

		if (String::IsNullOrWhiteSpace(sX) || String::IsNullOrWhiteSpace(sY))
		{
			MessageBox::Show("Vui long nhap so!", "Thong bao");
			return;
		}

		std::string X = msclr::interop::marshal_as<std::string>(sX);
		std::string Y = msclr::interop::marshal_as<std::string>(sY);

		txtKetQua->Clear();

		X = trimZeros(X);
		Y = trimZeros(Y);

		int n = (std::max)((X.size()), (Y.size()));
		while (X.size() < n) X = "0" + X;
		while (Y.size() < n) Y = "0" + Y;

		std::string result = karatsuba(X, Y, txtKetQua);

		txtKetQua->AppendText("\r\n============================\r\n");
		txtKetQua->AppendText("KET QUA CUOI DUNG: " + gcnew String(result.c_str()));
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txtNhapX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnLoadFile_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ dlg = gcnew OpenFileDialog();

		dlg->Filter = "Text files (*.txt)|*.txt";
		dlg->Title = "Chon file";

		// mở hộp thoại
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			// đọc toàn bộ dòng file
			array<String^>^ lines = System::IO::File::ReadAllLines(dlg->FileName);

			if (lines->Length < 2)
			{
				MessageBox::Show("File phai co it nhat 2 dong!");
				return;
			}

			// gán vào 2 textbox
			txtNhapX->Text = lines[0];
			txtNhapY->Text = lines[1];

			MessageBox::Show("Doc file thanh cong");
		}
	}
};
}

#pragma once

namespace Nhom13BaoCaoHocPhan {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Greedy
	/// </summary>
	public ref class Greedy : public System::Windows::Forms::Form
	{
	public:
		Greedy(void)
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
		~Greedy()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::DataGridView^ dataMatrix;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::RadioButton^ rdoInput;
	private: System::Windows::Forms::RadioButton^ rdoReadFile;




	private: System::Windows::Forms::Button^ btnRun;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ btnLoadFile;


	private: System::Windows::Forms::Button^ btnRun_File;

	private: System::Windows::Forms::DataGridView^ dataPlace;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDiemGiao;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Button^ btnBuildMatrix;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtResult;
	private: System::Windows::Forms::TextBox^ txtCost;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ txtDetail;
	private: System::Windows::Forms::ComboBox^ cbbStart;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label3;



























	protected:

	protected:
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataPlace = (gcnew System::Windows::Forms::DataGridView());
			this->colDiemGiao = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnBuildMatrix = (gcnew System::Windows::Forms::Button());
			this->cbbStart = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->rdoInput = (gcnew System::Windows::Forms::RadioButton());
			this->rdoReadFile = (gcnew System::Windows::Forms::RadioButton());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnLoadFile = (gcnew System::Windows::Forms::Button());
			this->btnRun_File = (gcnew System::Windows::Forms::Button());
			this->dataMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->txtCost = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtDetail = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataPlace))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataMatrix))->BeginInit();
			this->tableLayoutPanel5->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(924, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Thuật toán tham lam (Greedy )";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->dataMatrix, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 60);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(924, 275);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->dataPlace, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->btnBuildMatrix, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->cbbStart, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(2, 2);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 4;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 48)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(180, 271);
			this->tableLayoutPanel4->TabIndex = 3;
			// 
			// dataPlace
			// 
			this->dataPlace->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataPlace->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataPlace->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataPlace->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->colDiemGiao });
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataPlace->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataPlace->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataPlace->Location = System::Drawing::Point(2, 2);
			this->dataPlace->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataPlace->Name = L"dataPlace";
			this->dataPlace->RowHeadersWidth = 51;
			this->dataPlace->RowTemplate->Height = 24;
			this->dataPlace->Size = System::Drawing::Size(176, 107);
			this->dataPlace->TabIndex = 2;
			// 
			// colDiemGiao
			// 
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->colDiemGiao->DefaultCellStyle = dataGridViewCellStyle1;
			this->colDiemGiao->HeaderText = L"Điểm giao hàng";
			this->colDiemGiao->MinimumWidth = 6;
			this->colDiemGiao->Name = L"colDiemGiao";
			// 
			// btnBuildMatrix
			// 
			this->btnBuildMatrix->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnBuildMatrix->Location = System::Drawing::Point(2, 113);
			this->btnBuildMatrix->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnBuildMatrix->Name = L"btnBuildMatrix";
			this->btnBuildMatrix->Size = System::Drawing::Size(176, 62);
			this->btnBuildMatrix->TabIndex = 3;
			this->btnBuildMatrix->Text = L"Ma trận hóa";
			this->btnBuildMatrix->UseVisualStyleBackColor = true;
			this->btnBuildMatrix->Click += gcnew System::EventHandler(this, &Greedy::btnBuildMatrix_Click);
			// 
			// cbbStart
			// 
			this->cbbStart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cbbStart->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbbStart->FormattingEnabled = true;
			this->cbbStart->Location = System::Drawing::Point(2, 223);
			this->cbbStart->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->cbbStart->Name = L"cbbStart";
			this->cbbStart->Size = System::Drawing::Size(176, 33);
			this->cbbStart->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(2, 177);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 44);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Chọn điểm xuất phát";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->rdoInput, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->rdoReadFile, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnRun, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(555, 2);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 16)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(367, 271);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// rdoInput
			// 
			this->rdoInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->rdoInput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->rdoInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->rdoInput->Location = System::Drawing::Point(2, 2);
			this->rdoInput->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rdoInput->Name = L"rdoInput";
			this->rdoInput->Padding = System::Windows::Forms::Padding(15, 16, 15, 16);
			this->rdoInput->Size = System::Drawing::Size(179, 131);
			this->rdoInput->TabIndex = 2;
			this->rdoInput->TabStop = true;
			this->rdoInput->Text = L"Nhập thủ công";
			this->rdoInput->UseVisualStyleBackColor = false;
			this->rdoInput->CheckedChanged += gcnew System::EventHandler(this, &Greedy::rdoInput_CheckedChanged);
			// 
			// rdoReadFile
			// 
			this->rdoReadFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->rdoReadFile->Dock = System::Windows::Forms::DockStyle::Fill;
			this->rdoReadFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->rdoReadFile->Location = System::Drawing::Point(185, 2);
			this->rdoReadFile->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->rdoReadFile->Name = L"rdoReadFile";
			this->rdoReadFile->Padding = System::Windows::Forms::Padding(15, 16, 15, 16);
			this->rdoReadFile->Size = System::Drawing::Size(180, 131);
			this->rdoReadFile->TabIndex = 3;
			this->rdoReadFile->TabStop = true;
			this->rdoReadFile->Text = L"Tải từ file ( .txt )\r\n";
			this->rdoReadFile->UseVisualStyleBackColor = false;
			this->rdoReadFile->CheckedChanged += gcnew System::EventHandler(this, &Greedy::rdoReadFile_CheckedChanged);
			// 
			// btnRun
			// 
			this->btnRun->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnRun->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnRun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->btnRun->Location = System::Drawing::Point(2, 137);
			this->btnRun->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(179, 132);
			this->btnRun->TabIndex = 4;
			this->btnRun->Text = L"Thực hiện thuật toán";
			this->btnRun->UseVisualStyleBackColor = false;
			this->btnRun->Click += gcnew System::EventHandler(this, &Greedy::btnRun_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->BackColor = System::Drawing::Color::White;
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->btnLoadFile, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btnRun_File, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(185, 137);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(180, 132);
			this->tableLayoutPanel3->TabIndex = 5;
			// 
			// btnLoadFile
			// 
			this->btnLoadFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnLoadFile->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnLoadFile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLoadFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->btnLoadFile->Location = System::Drawing::Point(2, 2);
			this->btnLoadFile->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnLoadFile->Name = L"btnLoadFile";
			this->btnLoadFile->Size = System::Drawing::Size(86, 128);
			this->btnLoadFile->TabIndex = 0;
			this->btnLoadFile->Text = L"Tải từ file";
			this->btnLoadFile->UseVisualStyleBackColor = false;
			this->btnLoadFile->Click += gcnew System::EventHandler(this, &Greedy::btnLoadFile_Click);
			// 
			// btnRun_File
			// 
			this->btnRun_File->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnRun_File->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnRun_File->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRun_File->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->btnRun_File->Location = System::Drawing::Point(92, 2);
			this->btnRun_File->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnRun_File->Name = L"btnRun_File";
			this->btnRun_File->Size = System::Drawing::Size(86, 128);
			this->btnRun_File->TabIndex = 1;
			this->btnRun_File->Text = L"Thực hiện";
			this->btnRun_File->UseVisualStyleBackColor = false;
			this->btnRun_File->Click += gcnew System::EventHandler(this, &Greedy::btnRun_File_Click);
			// 
			// dataMatrix
			// 
			this->dataMatrix->AllowUserToAddRows = false;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataMatrix->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataMatrix->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataMatrix->Location = System::Drawing::Point(187, 3);
			this->dataMatrix->Name = L"dataMatrix";
			this->dataMatrix->RowHeadersWidth = 51;
			this->dataMatrix->Size = System::Drawing::Size(363, 269);
			this->dataMatrix->TabIndex = 0;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel5->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->txtResult, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->txtCost, 2, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel5->Location = System::Drawing::Point(0, 335);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(924, 63);
			this->tableLayoutPanel5->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->label2->Location = System::Drawing::Point(10, 8);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(268, 47);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Kết quả hành trình tối ưu";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtResult
			// 
			this->txtResult->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->txtResult->Location = System::Drawing::Point(282, 10);
			this->txtResult->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtResult->Multiline = true;
			this->txtResult->Name = L"txtResult";
			this->txtResult->ReadOnly = true;
			this->txtResult->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtResult->Size = System::Drawing::Size(450, 43);
			this->txtResult->TabIndex = 1;
			// 
			// txtCost
			// 
			this->txtCost->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtCost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->txtCost->Location = System::Drawing::Point(736, 10);
			this->txtCost->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtCost->Multiline = true;
			this->txtCost->Name = L"txtCost";
			this->txtCost->ReadOnly = true;
			this->txtCost->Size = System::Drawing::Size(178, 43);
			this->txtCost->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 398);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
			this->panel1->Size = System::Drawing::Size(924, 202);
			this->panel1->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtDetail);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(163)));
			this->groupBox1->Location = System::Drawing::Point(8, 8);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
			this->groupBox1->Size = System::Drawing::Size(908, 186);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Chi tiết hành trình";
			// 
			// txtDetail
			// 
			this->txtDetail->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtDetail->Location = System::Drawing::Point(8, 35);
			this->txtDetail->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtDetail->Multiline = true;
			this->txtDetail->Name = L"txtDetail";
			this->txtDetail->ReadOnly = true;
			this->txtDetail->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtDetail->Size = System::Drawing::Size(892, 143);
			this->txtDetail->TabIndex = 0;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Greedy
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(924, 600);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tableLayoutPanel5);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Name = L"Greedy";
			this->Text = L"Greedy";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Greedy::Greedy_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataPlace))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataMatrix))->EndInit();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void buildMatrix();
		void GreedyAlgorithm(int start);
		void Run_Greedy();
		void LoadMatrix_FromTxt(String^ filePath);


	private: System::Void numSoLuong_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Greedy_Load(System::Object^ sender, System::EventArgs^ e) {
		btnRun_File->Enabled = false;
		btnRun->Enabled = false;
		dataPlace->Enabled = false;
		btnBuildMatrix->Enabled = false;
		btnLoadFile->Enabled = false;
	}
	private: System::Void btnBuildMatrix_Click(System::Object^ sender, System::EventArgs^ e) {
		buildMatrix();
	}
	private: System::Void btnRun_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataMatrix->Rows->Count == 0)
		{
			MessageBox::Show("ban chua xay dung ma tran!",
				"Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (cbbStart->SelectedIndex == -1)
		{
			MessageBox::Show("ban chua chon diem bat dau",
				"Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		cbbStart->Focus();
		Run_Greedy();
	}

	private: System::Void rdoInput_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		btnRun_File->Enabled = false;
		btnLoadFile->Enabled = false;
		btnRun->Enabled = true;
		dataPlace->Enabled = true;
		btnBuildMatrix->Enabled = true;
		dataMatrix->Rows->Clear();
		dataPlace->Rows->Clear();
		cbbStart->Items->Clear();
		dataPlace->Focus();
		rdoReadFile->Checked = !rdoInput->Checked;
	}
	private: System::Void rdoReadFile_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		btnRun->Enabled = false;
		btnRun_File->Enabled = true;
		btnLoadFile->Enabled = true;
		dataPlace->Enabled = false;
		btnRun->Enabled = false;
		dataMatrix->Rows->Clear();
		dataMatrix->Columns->Clear();
		dataPlace->Rows->Clear();
		cbbStart->Items->Clear();
		rdoInput->Checked = !rdoReadFile->Checked;
	}
	private: System::Void btnRun_File_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataMatrix->Rows->Count == 0)
		{
			MessageBox::Show("ban chua xay dung ma tran!",
				"Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (cbbStart->SelectedIndex == -1)
		{
			MessageBox::Show("ban chua chon diem bat dau",
				"Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		Run_Greedy();
	}
	private: System::Void btnLoadFile_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Text Files (*.txt)|*.txt";

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			LoadMatrix_FromTxt(ofd->FileName);
		}
		cbbStart->Enabled = true;
		cbbStart->Items->Clear();
		// load lai combobox
		for (int i = 0; i < dataMatrix->Columns->Count; i++)
		{
			cbbStart->Items->Add(dataMatrix->Rows[i]->HeaderCell->Value->ToString());
		}
	}
};
}

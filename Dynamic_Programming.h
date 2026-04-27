#pragma once
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <string.h>
#include <iostream>
#include <WebView2.h>
#include <vector>
#include <map>
#include <cmath>
#include "Karatsuba.h"				// 2001230994 - Phạm Thanh Trúc 
#include "Greedy.h"					// 2001230264 - Nguyễn Huy Hoàng
#include "Dynamic_Programming.h"	// 2001230325 - Vũ Duy Hưng


#define EPS 1e-4 // chuẩn hóa sai số tọa độ chiếu 

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Microsoft::Web::WebView2::WinForms;
using namespace Microsoft::Web::WebView2::Core;


// cấu trúc lưu trữ thông tin thành phố
struct City {
	std::string name;
	double lat;// vi do
	double lng;// kinh do
	long long x;
	long long y;
};

// ====== TSP Data ======
extern std::vector<std::vector<double>> dist;
extern std::map<std::pair<int, int>, double> dp;
extern std::map<std::pair<int, int>, int> parent;
extern std::string bottomUpLog;
extern std::vector<int> path_BottomUp;
extern double bestCost_BottomUp;
extern std::vector<std::vector<double>> dpBottomUp;
extern std::vector<std::vector<double>> realDist;
extern std::vector<std::vector<double>> dist_real;
extern std::vector<std::vector<double>> dp_real;
extern std::vector<std::vector<int>> parent_real;
extern std::vector<City> cities_real;


// danh sách thành phố
extern std::vector<City> cities;
public ref class Dynamic_Programming : public System::Windows::Forms::Form
{
private: System::Windows::Forms::TabControl^ tabControl1;
private: System::Windows::Forms::TabPage^ EulideanTab;
private: System::Windows::Forms::TabPage^ RealDistance;
private: Microsoft::Web::WebView2::WinForms::WebView2^ WebView_Map_Tab1;




private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
private: System::Windows::Forms::ListView^ listView1;
private: System::Windows::Forms::ColumnHeader^ name_col;
private: System::Windows::Forms::ColumnHeader^ X;
private: System::Windows::Forms::ColumnHeader^ Y;
private: System::Windows::Forms::ListView^ listView2;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
private: System::Windows::Forms::ComboBox^ StartCity;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Button^ btnRun;
private: System::Windows::Forms::Label^ label1;


private: System::Windows::Forms::TabControl^ tabControl2;
private: System::Windows::Forms::TabPage^ tabTopDown;
private: System::Windows::Forms::TabPage^ tabBottomUp;
private: System::Windows::Forms::ErrorProvider^ errorProvider1;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::ListView^ listViewMemo;

private: System::Windows::Forms::ColumnHeader^ columnHeader1;
private: System::Windows::Forms::ColumnHeader^ columnHeader2;
private: System::Windows::Forms::TextBox^ textBoxTour;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TextBox^ textBoxResult;


private: Microsoft::Web::WebView2::WinForms::WebView2^ WebView_Map_Tab2;
private: System::Windows::Forms::TextBox^ textBoxCost;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
private: System::Windows::Forms::Button^ btnExit;
private: System::Windows::Forms::Button^ btnClear;
private: System::Windows::Forms::Button^ btnGreedy;
private: System::Windows::Forms::Button^ btnKaratsuba;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::TextBox^ textTour_BottomUp;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel7;
private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::ListView^ listViewBottomUp;

private: System::Windows::Forms::ColumnHeader^ columnHeader3;
private: System::Windows::Forms::ColumnHeader^ columnHeader4;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel8;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::TextBox^ textBoxBU_result;
private: System::Windows::Forms::TextBox^ textBoxBU_Cost;


private: System::Windows::Forms::Button^ btnBU_Exit;
private: System::Windows::Forms::Button^ btnBU_Clear;
private: System::Windows::Forms::Button^ btnBU_Greedy;
private: System::Windows::Forms::Button^ btnBU_Karat;

private: System::Windows::Forms::BindingSource^ bindingSource1;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel9;


private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel10;
private: System::Windows::Forms::ComboBox^ cbbSelectCity;

private: System::Windows::Forms::Button^ btnReal_Run;

private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::ListView^ lstMatrix_RealCost;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel11;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TextBox^ textBox_FinalResult;
private: System::Windows::Forms::TextBox^ textBox_FinalCost;


private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel12;
private: System::Windows::Forms::GroupBox^ groupBox5;
private: System::Windows::Forms::GroupBox^ groupBox6;
private: System::Windows::Forms::TextBox^ txtReal_DetailTour;
private: System::Windows::Forms::ListView^ lstReal_SaveTour;
private: System::Windows::Forms::ColumnHeader^ columnHeader5;
private: System::Windows::Forms::ColumnHeader^ columnHeader6;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel13;
private: System::Windows::Forms::Button^ btnKarat;
private: System::Windows::Forms::Button^ btnGreedy2;
private: System::Windows::Forms::Button^ btnXoa;
private: System::Windows::Forms::Button^ btnThoat;



private:
	System::Text::StringBuilder^ recursionLog;

public:
	Dynamic_Programming(void)
	{
		InitializeComponent();
		recursionLog = gcnew System::Text::StringBuilder();
	}

protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~Dynamic_Programming()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::ComponentModel::IContainer^ components;
private:

	Microsoft::Web::WebView2::WinForms::WebView2^ webView21;
	Microsoft::Web::WebView2::WinForms::WebView2^ web;


	   void InitializeComponent(void)
	   {
		   this->components = (gcnew System::ComponentModel::Container());
		   this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
		   this->EulideanTab = (gcnew System::Windows::Forms::TabPage());
		   this->panel1 = (gcnew System::Windows::Forms::Panel());
		   this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
		   this->tabTopDown = (gcnew System::Windows::Forms::TabPage());
		   this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->btnExit = (gcnew System::Windows::Forms::Button());
		   this->btnClear = (gcnew System::Windows::Forms::Button());
		   this->btnGreedy = (gcnew System::Windows::Forms::Button());
		   this->btnKaratsuba = (gcnew System::Windows::Forms::Button());
		   this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->label3 = (gcnew System::Windows::Forms::Label());
		   this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
		   this->textBoxCost = (gcnew System::Windows::Forms::TextBox());
		   this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		   this->textBoxTour = (gcnew System::Windows::Forms::TextBox());
		   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		   this->listViewMemo = (gcnew System::Windows::Forms::ListView());
		   this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
		   this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
		   this->tabBottomUp = (gcnew System::Windows::Forms::TabPage());
		   this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->btnBU_Exit = (gcnew System::Windows::Forms::Button());
		   this->btnBU_Clear = (gcnew System::Windows::Forms::Button());
		   this->btnBU_Greedy = (gcnew System::Windows::Forms::Button());
		   this->btnBU_Karat = (gcnew System::Windows::Forms::Button());
		   this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->label4 = (gcnew System::Windows::Forms::Label());
		   this->textBoxBU_result = (gcnew System::Windows::Forms::TextBox());
		   this->textBoxBU_Cost = (gcnew System::Windows::Forms::TextBox());
		   this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
		   this->textTour_BottomUp = (gcnew System::Windows::Forms::TextBox());
		   this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
		   this->listViewBottomUp = (gcnew System::Windows::Forms::ListView());
		   this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
		   this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
		   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->listView1 = (gcnew System::Windows::Forms::ListView());
		   this->name_col = (gcnew System::Windows::Forms::ColumnHeader());
		   this->X = (gcnew System::Windows::Forms::ColumnHeader());
		   this->Y = (gcnew System::Windows::Forms::ColumnHeader());
		   this->listView2 = (gcnew System::Windows::Forms::ListView());
		   this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->StartCity = (gcnew System::Windows::Forms::ComboBox());
		   this->label2 = (gcnew System::Windows::Forms::Label());
		   this->btnRun = (gcnew System::Windows::Forms::Button());
		   this->label1 = (gcnew System::Windows::Forms::Label());
		   this->WebView_Map_Tab1 = (gcnew Microsoft::Web::WebView2::WinForms::WebView2());
		   this->RealDistance = (gcnew System::Windows::Forms::TabPage());
		   this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->btnKarat = (gcnew System::Windows::Forms::Button());
		   this->btnGreedy2 = (gcnew System::Windows::Forms::Button());
		   this->btnXoa = (gcnew System::Windows::Forms::Button());
		   this->btnThoat = (gcnew System::Windows::Forms::Button());
		   this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
		   this->txtReal_DetailTour = (gcnew System::Windows::Forms::TextBox());
		   this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
		   this->lstReal_SaveTour = (gcnew System::Windows::Forms::ListView());
		   this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
		   this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
		   this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->label6 = (gcnew System::Windows::Forms::Label());
		   this->textBox_FinalResult = (gcnew System::Windows::Forms::TextBox());
		   this->textBox_FinalCost = (gcnew System::Windows::Forms::TextBox());
		   this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->lstMatrix_RealCost = (gcnew System::Windows::Forms::ListView());
		   this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
		   this->cbbSelectCity = (gcnew System::Windows::Forms::ComboBox());
		   this->btnReal_Run = (gcnew System::Windows::Forms::Button());
		   this->label5 = (gcnew System::Windows::Forms::Label());
		   this->WebView_Map_Tab2 = (gcnew Microsoft::Web::WebView2::WinForms::WebView2());
		   this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
		   this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
		   this->tabControl1->SuspendLayout();
		   this->EulideanTab->SuspendLayout();
		   this->panel1->SuspendLayout();
		   this->tabControl2->SuspendLayout();
		   this->tabTopDown->SuspendLayout();
		   this->tableLayoutPanel5->SuspendLayout();
		   this->tableLayoutPanel4->SuspendLayout();
		   this->tableLayoutPanel3->SuspendLayout();
		   this->groupBox1->SuspendLayout();
		   this->groupBox2->SuspendLayout();
		   this->tabBottomUp->SuspendLayout();
		   this->tableLayoutPanel8->SuspendLayout();
		   this->tableLayoutPanel7->SuspendLayout();
		   this->tableLayoutPanel6->SuspendLayout();
		   this->groupBox3->SuspendLayout();
		   this->groupBox4->SuspendLayout();
		   this->tableLayoutPanel1->SuspendLayout();
		   this->tableLayoutPanel2->SuspendLayout();
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WebView_Map_Tab1))->BeginInit();
		   this->RealDistance->SuspendLayout();
		   this->tableLayoutPanel13->SuspendLayout();
		   this->tableLayoutPanel12->SuspendLayout();
		   this->groupBox5->SuspendLayout();
		   this->groupBox6->SuspendLayout();
		   this->tableLayoutPanel11->SuspendLayout();
		   this->tableLayoutPanel9->SuspendLayout();
		   this->tableLayoutPanel10->SuspendLayout();
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WebView_Map_Tab2))->BeginInit();
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
		   this->SuspendLayout();
		   // 
		   // tabControl1
		   // 
		   this->tabControl1->Controls->Add(this->EulideanTab);
		   this->tabControl1->Controls->Add(this->RealDistance);
		   this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(163)));
		   this->tabControl1->Location = System::Drawing::Point(0, 0);
		   this->tabControl1->Name = L"tabControl1";
		   this->tabControl1->SelectedIndex = 0;
		   this->tabControl1->Size = System::Drawing::Size(1440, 854);
		   this->tabControl1->TabIndex = 0;
		   // 
		   // EulideanTab
		   // 
		   this->EulideanTab->Controls->Add(this->panel1);
		   this->EulideanTab->Controls->Add(this->WebView_Map_Tab1);
		   this->EulideanTab->Location = System::Drawing::Point(4, 34);
		   this->EulideanTab->Name = L"EulideanTab";
		   this->EulideanTab->Padding = System::Windows::Forms::Padding(3);
		   this->EulideanTab->Size = System::Drawing::Size(1432, 816);
		   this->EulideanTab->TabIndex = 0;
		   this->EulideanTab->Text = L"Mô hình lý tưởng";
		   this->EulideanTab->UseVisualStyleBackColor = true;
		   // 
		   // panel1
		   // 
		   this->panel1->Controls->Add(this->tabControl2);
		   this->panel1->Controls->Add(this->tableLayoutPanel1);
		   this->panel1->Controls->Add(this->label1);
		   this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->panel1->Location = System::Drawing::Point(614, 3);
		   this->panel1->Name = L"panel1";
		   this->panel1->Size = System::Drawing::Size(815, 810);
		   this->panel1->TabIndex = 1;
		   // 
		   // tabControl2
		   // 
		   this->tabControl2->Controls->Add(this->tabTopDown);
		   this->tabControl2->Controls->Add(this->tabBottomUp);
		   this->tabControl2->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->tabControl2->Location = System::Drawing::Point(0, 205);
		   this->tabControl2->Name = L"tabControl2";
		   this->tabControl2->SelectedIndex = 0;
		   this->tabControl2->Size = System::Drawing::Size(815, 605);
		   this->tabControl2->TabIndex = 10;
		   // 
		   // tabTopDown
		   // 
		   this->tabTopDown->Controls->Add(this->tableLayoutPanel5);
		   this->tabTopDown->Controls->Add(this->tableLayoutPanel4);
		   this->tabTopDown->Controls->Add(this->tableLayoutPanel3);
		   this->tabTopDown->Location = System::Drawing::Point(4, 34);
		   this->tabTopDown->Name = L"tabTopDown";
		   this->tabTopDown->Padding = System::Windows::Forms::Padding(3);
		   this->tabTopDown->Size = System::Drawing::Size(807, 567);
		   this->tabTopDown->TabIndex = 0;
		   this->tabTopDown->Text = L"TopDown";
		   this->tabTopDown->UseVisualStyleBackColor = true;
		   // 
		   // tableLayoutPanel5
		   // 
		   this->tableLayoutPanel5->ColumnCount = 4;
		   this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel5->Controls->Add(this->btnExit, 3, 0);
		   this->tableLayoutPanel5->Controls->Add(this->btnClear, 2, 0);
		   this->tableLayoutPanel5->Controls->Add(this->btnGreedy, 1, 0);
		   this->tableLayoutPanel5->Controls->Add(this->btnKaratsuba, 0, 0);
		   this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Bottom;
		   this->tableLayoutPanel5->Location = System::Drawing::Point(3, 494);
		   this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
		   this->tableLayoutPanel5->RowCount = 1;
		   this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel5->Size = System::Drawing::Size(801, 70);
		   this->tableLayoutPanel5->TabIndex = 2;
		   // 
		   // btnExit
		   // 
		   this->btnExit->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnExit->Location = System::Drawing::Point(603, 3);
		   this->btnExit->Name = L"btnExit";
		   this->btnExit->Size = System::Drawing::Size(195, 64);
		   this->btnExit->TabIndex = 0;
		   this->btnExit->Text = L"Thoát";
		   this->btnExit->UseVisualStyleBackColor = true;
		   this->btnExit->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnExit_Click);
		   // 
		   // btnClear
		   // 
		   this->btnClear->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnClear->Location = System::Drawing::Point(403, 3);
		   this->btnClear->Name = L"btnClear";
		   this->btnClear->Size = System::Drawing::Size(194, 64);
		   this->btnClear->TabIndex = 1;
		   this->btnClear->Text = L"Xóa";
		   this->btnClear->UseVisualStyleBackColor = true;
		   this->btnClear->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnClear_Click);
		   // 
		   // btnGreedy
		   // 
		   this->btnGreedy->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnGreedy->Location = System::Drawing::Point(203, 3);
		   this->btnGreedy->Name = L"btnGreedy";
		   this->btnGreedy->Size = System::Drawing::Size(194, 64);
		   this->btnGreedy->TabIndex = 2;
		   this->btnGreedy->Text = L"Bài toán ban lo";
		   this->btnGreedy->UseVisualStyleBackColor = true;
		   this->btnGreedy->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnGreedy_Click);
		   // 
		   // btnKaratsuba
		   // 
		   this->btnKaratsuba->Dock = System::Windows::Forms::DockStyle::Bottom;
		   this->btnKaratsuba->Location = System::Drawing::Point(3, 3);
		   this->btnKaratsuba->Name = L"btnKaratsuba";
		   this->btnKaratsuba->Size = System::Drawing::Size(194, 64);
		   this->btnKaratsuba->TabIndex = 3;
		   this->btnKaratsuba->Text = L"Karatsuba";
		   this->btnKaratsuba->UseVisualStyleBackColor = true;
		   this->btnKaratsuba->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnKaratsuba_Click);
		   // 
		   // tableLayoutPanel4
		   // 
		   this->tableLayoutPanel4->ColumnCount = 3;
		   this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   20)));
		   this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   40)));
		   this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   40)));
		   this->tableLayoutPanel4->Controls->Add(this->label3, 0, 0);
		   this->tableLayoutPanel4->Controls->Add(this->textBoxResult, 1, 0);
		   this->tableLayoutPanel4->Controls->Add(this->textBoxCost, 2, 0);
		   this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel4->Location = System::Drawing::Point(3, 326);
		   this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
		   this->tableLayoutPanel4->RowCount = 1;
		   this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel4->Size = System::Drawing::Size(801, 56);
		   this->tableLayoutPanel4->TabIndex = 1;
		   // 
		   // label3
		   // 
		   this->label3->AutoSize = true;
		   this->label3->BackColor = System::Drawing::Color::LemonChiffon;
		   this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->label3->Location = System::Drawing::Point(3, 0);
		   this->label3->Name = L"label3";
		   this->label3->Size = System::Drawing::Size(154, 56);
		   this->label3->TabIndex = 0;
		   this->label3->Text = L"Hành trình tối ưu";
		   this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		   // 
		   // textBoxResult
		   // 
		   this->textBoxResult->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textBoxResult->Location = System::Drawing::Point(163, 3);
		   this->textBoxResult->Multiline = true;
		   this->textBoxResult->Name = L"textBoxResult";
		   this->textBoxResult->ReadOnly = true;
		   this->textBoxResult->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		   this->textBoxResult->Size = System::Drawing::Size(314, 50);
		   this->textBoxResult->TabIndex = 1;
		   // 
		   // textBoxCost
		   // 
		   this->textBoxCost->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textBoxCost->Enabled = false;
		   this->textBoxCost->Location = System::Drawing::Point(483, 3);
		   this->textBoxCost->Multiline = true;
		   this->textBoxCost->Name = L"textBoxCost";
		   this->textBoxCost->Size = System::Drawing::Size(315, 50);
		   this->textBoxCost->TabIndex = 2;
		   // 
		   // tableLayoutPanel3
		   // 
		   this->tableLayoutPanel3->ColumnCount = 2;
		   this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   49.30468F)));
		   this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   50.69532F)));
		   this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
		   this->tableLayoutPanel3->Controls->Add(this->groupBox2, 1, 0);
		   this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
		   this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
		   this->tableLayoutPanel3->Padding = System::Windows::Forms::Padding(5);
		   this->tableLayoutPanel3->RowCount = 1;
		   this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel3->Size = System::Drawing::Size(801, 323);
		   this->tableLayoutPanel3->TabIndex = 0;
		   // 
		   // groupBox1
		   // 
		   this->groupBox1->Controls->Add(this->textBoxTour);
		   this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->groupBox1->Location = System::Drawing::Point(8, 8);
		   this->groupBox1->Name = L"groupBox1";
		   this->groupBox1->Size = System::Drawing::Size(384, 307);
		   this->groupBox1->TabIndex = 0;
		   this->groupBox1->TabStop = false;
		   this->groupBox1->Text = L"Thông tin hành tình";
		   // 
		   // textBoxTour
		   // 
		   this->textBoxTour->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textBoxTour->Location = System::Drawing::Point(3, 26);
		   this->textBoxTour->Multiline = true;
		   this->textBoxTour->Name = L"textBoxTour";
		   this->textBoxTour->ReadOnly = true;
		   this->textBoxTour->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		   this->textBoxTour->Size = System::Drawing::Size(378, 278);
		   this->textBoxTour->TabIndex = 0;
		   // 
		   // groupBox2
		   // 
		   this->groupBox2->Controls->Add(this->listViewMemo);
		   this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->groupBox2->Location = System::Drawing::Point(398, 8);
		   this->groupBox2->Name = L"groupBox2";
		   this->groupBox2->Size = System::Drawing::Size(395, 307);
		   this->groupBox2->TabIndex = 1;
		   this->groupBox2->TabStop = false;
		   this->groupBox2->Text = L"Bộ nhớ lưu trữ";
		   // 
		   // listViewMemo
		   // 
		   this->listViewMemo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
			   this->columnHeader1,
				   this->columnHeader2
		   });
		   this->listViewMemo->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->listViewMemo->FullRowSelect = true;
		   this->listViewMemo->GridLines = true;
		   this->listViewMemo->HideSelection = false;
		   this->listViewMemo->Location = System::Drawing::Point(3, 26);
		   this->listViewMemo->Name = L"listViewMemo";
		   this->listViewMemo->Size = System::Drawing::Size(389, 278);
		   this->listViewMemo->TabIndex = 0;
		   this->listViewMemo->UseCompatibleStateImageBehavior = false;
		   this->listViewMemo->View = System::Windows::Forms::View::Details;
		   // 
		   // columnHeader1
		   // 
		   this->columnHeader1->Text = L"Hành trình";
		   this->columnHeader1->Width = 201;
		   // 
		   // columnHeader2
		   // 
		   this->columnHeader2->Text = L"Chi Phí";
		   this->columnHeader2->Width = 259;
		   // 
		   // tabBottomUp
		   // 
		   this->tabBottomUp->Controls->Add(this->tableLayoutPanel8);
		   this->tabBottomUp->Controls->Add(this->tableLayoutPanel7);
		   this->tabBottomUp->Controls->Add(this->tableLayoutPanel6);
		   this->tabBottomUp->Location = System::Drawing::Point(4, 34);
		   this->tabBottomUp->Name = L"tabBottomUp";
		   this->tabBottomUp->Padding = System::Windows::Forms::Padding(3);
		   this->tabBottomUp->Size = System::Drawing::Size(807, 521);
		   this->tabBottomUp->TabIndex = 1;
		   this->tabBottomUp->Text = L"BottomUp ( Held - Karp)";
		   this->tabBottomUp->UseVisualStyleBackColor = true;
		   // 
		   // tableLayoutPanel8
		   // 
		   this->tableLayoutPanel8->ColumnCount = 4;
		   this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel8->Controls->Add(this->btnBU_Exit, 3, 0);
		   this->tableLayoutPanel8->Controls->Add(this->btnBU_Clear, 2, 0);
		   this->tableLayoutPanel8->Controls->Add(this->btnBU_Greedy, 1, 0);
		   this->tableLayoutPanel8->Controls->Add(this->btnBU_Karat, 0, 0);
		   this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Bottom;
		   this->tableLayoutPanel8->Location = System::Drawing::Point(3, 465);
		   this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
		   this->tableLayoutPanel8->RowCount = 1;
		   this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel8->Size = System::Drawing::Size(801, 53);
		   this->tableLayoutPanel8->TabIndex = 2;
		   // 
		   // btnBU_Exit
		   // 
		   this->btnBU_Exit->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnBU_Exit->Location = System::Drawing::Point(603, 3);
		   this->btnBU_Exit->Name = L"btnBU_Exit";
		   this->btnBU_Exit->Size = System::Drawing::Size(195, 47);
		   this->btnBU_Exit->TabIndex = 0;
		   this->btnBU_Exit->Text = L"Thoat";
		   this->btnBU_Exit->UseVisualStyleBackColor = true;
		   // 
		   // btnBU_Clear
		   // 
		   this->btnBU_Clear->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnBU_Clear->Location = System::Drawing::Point(403, 3);
		   this->btnBU_Clear->Name = L"btnBU_Clear";
		   this->btnBU_Clear->Size = System::Drawing::Size(194, 47);
		   this->btnBU_Clear->TabIndex = 1;
		   this->btnBU_Clear->Text = L"Xoa";
		   this->btnBU_Clear->UseVisualStyleBackColor = true;
		   this->btnBU_Clear->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnBU_Clear_Click);
		   // 
		   // btnBU_Greedy
		   // 
		   this->btnBU_Greedy->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnBU_Greedy->Location = System::Drawing::Point(203, 3);
		   this->btnBU_Greedy->Name = L"btnBU_Greedy";
		   this->btnBU_Greedy->Size = System::Drawing::Size(194, 47);
		   this->btnBU_Greedy->TabIndex = 2;
		   this->btnBU_Greedy->Text = L"Bai toan Balo";
		   this->btnBU_Greedy->UseVisualStyleBackColor = true;
		   // 
		   // btnBU_Karat
		   // 
		   this->btnBU_Karat->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnBU_Karat->Location = System::Drawing::Point(3, 3);
		   this->btnBU_Karat->Name = L"btnBU_Karat";
		   this->btnBU_Karat->Size = System::Drawing::Size(194, 47);
		   this->btnBU_Karat->TabIndex = 3;
		   this->btnBU_Karat->Text = L"Karatsuba";
		   this->btnBU_Karat->UseVisualStyleBackColor = true;
		   // 
		   // tableLayoutPanel7
		   // 
		   this->tableLayoutPanel7->ColumnCount = 3;
		   this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   20)));
		   this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   40)));
		   this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   40)));
		   this->tableLayoutPanel7->Controls->Add(this->label4, 0, 0);
		   this->tableLayoutPanel7->Controls->Add(this->textBoxBU_result, 1, 0);
		   this->tableLayoutPanel7->Controls->Add(this->textBoxBU_Cost, 2, 0);
		   this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel7->Location = System::Drawing::Point(3, 378);
		   this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
		   this->tableLayoutPanel7->RowCount = 1;
		   this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel7->Size = System::Drawing::Size(801, 48);
		   this->tableLayoutPanel7->TabIndex = 1;
		   // 
		   // label4
		   // 
		   this->label4->AutoSize = true;
		   this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->label4->Location = System::Drawing::Point(3, 0);
		   this->label4->Name = L"label4";
		   this->label4->Size = System::Drawing::Size(154, 48);
		   this->label4->TabIndex = 0;
		   this->label4->Text = L"Hanh trinh toi uu";
		   this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		   // 
		   // textBoxBU_result
		   // 
		   this->textBoxBU_result->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textBoxBU_result->Location = System::Drawing::Point(163, 3);
		   this->textBoxBU_result->Multiline = true;
		   this->textBoxBU_result->Name = L"textBoxBU_result";
		   this->textBoxBU_result->ReadOnly = true;
		   this->textBoxBU_result->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		   this->textBoxBU_result->Size = System::Drawing::Size(314, 42);
		   this->textBoxBU_result->TabIndex = 1;
		   // 
		   // textBoxBU_Cost
		   // 
		   this->textBoxBU_Cost->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textBoxBU_Cost->Location = System::Drawing::Point(483, 3);
		   this->textBoxBU_Cost->Multiline = true;
		   this->textBoxBU_Cost->Name = L"textBoxBU_Cost";
		   this->textBoxBU_Cost->ReadOnly = true;
		   this->textBoxBU_Cost->Size = System::Drawing::Size(315, 42);
		   this->textBoxBU_Cost->TabIndex = 2;
		   // 
		   // tableLayoutPanel6
		   // 
		   this->tableLayoutPanel6->ColumnCount = 2;
		   this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   50)));
		   this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   50)));
		   this->tableLayoutPanel6->Controls->Add(this->groupBox3, 0, 0);
		   this->tableLayoutPanel6->Controls->Add(this->groupBox4, 1, 0);
		   this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel6->Location = System::Drawing::Point(3, 3);
		   this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
		   this->tableLayoutPanel6->RowCount = 1;
		   this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel6->Size = System::Drawing::Size(801, 375);
		   this->tableLayoutPanel6->TabIndex = 0;
		   // 
		   // groupBox3
		   // 
		   this->groupBox3->Controls->Add(this->textTour_BottomUp);
		   this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->groupBox3->Location = System::Drawing::Point(3, 3);
		   this->groupBox3->Name = L"groupBox3";
		   this->groupBox3->Size = System::Drawing::Size(394, 369);
		   this->groupBox3->TabIndex = 0;
		   this->groupBox3->TabStop = false;
		   this->groupBox3->Text = L"Cac tap dinh co chua diem xuat phat";
		   // 
		   // textTour_BottomUp
		   // 
		   this->textTour_BottomUp->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textTour_BottomUp->Location = System::Drawing::Point(3, 26);
		   this->textTour_BottomUp->Multiline = true;
		   this->textTour_BottomUp->Name = L"textTour_BottomUp";
		   this->textTour_BottomUp->ReadOnly = true;
		   this->textTour_BottomUp->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		   this->textTour_BottomUp->Size = System::Drawing::Size(388, 340);
		   this->textTour_BottomUp->TabIndex = 0;
		   // 
		   // groupBox4
		   // 
		   this->groupBox4->Controls->Add(this->listViewBottomUp);
		   this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->groupBox4->Location = System::Drawing::Point(403, 3);
		   this->groupBox4->Name = L"groupBox4";
		   this->groupBox4->Size = System::Drawing::Size(395, 369);
		   this->groupBox4->TabIndex = 1;
		   this->groupBox4->TabStop = false;
		   this->groupBox4->Text = L"Luu thong tin hanh trinh";
		   // 
		   // listViewBottomUp
		   // 
		   this->listViewBottomUp->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
			   this->columnHeader3,
				   this->columnHeader4
		   });
		   this->listViewBottomUp->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->listViewBottomUp->GridLines = true;
		   this->listViewBottomUp->HideSelection = false;
		   this->listViewBottomUp->Location = System::Drawing::Point(3, 26);
		   this->listViewBottomUp->Name = L"listViewBottomUp";
		   this->listViewBottomUp->Size = System::Drawing::Size(389, 340);
		   this->listViewBottomUp->TabIndex = 0;
		   this->listViewBottomUp->UseCompatibleStateImageBehavior = false;
		   this->listViewBottomUp->View = System::Windows::Forms::View::Details;
		   // 
		   // columnHeader3
		   // 
		   this->columnHeader3->Text = L"Tap dinh";
		   this->columnHeader3->Width = 222;
		   // 
		   // columnHeader4
		   // 
		   this->columnHeader4->Text = L"chi phi";
		   this->columnHeader4->Width = 172;
		   // 
		   // tableLayoutPanel1
		   // 
		   this->tableLayoutPanel1->ColumnCount = 3;
		   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   40)));
		   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   20)));
		   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   40)));
		   this->tableLayoutPanel1->Controls->Add(this->listView1, 0, 0);
		   this->tableLayoutPanel1->Controls->Add(this->listView2, 2, 0);
		   this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
		   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 39);
		   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
		   this->tableLayoutPanel1->RowCount = 1;
		   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel1->Size = System::Drawing::Size(815, 166);
		   this->tableLayoutPanel1->TabIndex = 8;
		   // 
		   // listView1
		   // 
		   this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
			   this->name_col, this->X,
				   this->Y
		   });
		   this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->listView1->GridLines = true;
		   this->listView1->HideSelection = false;
		   this->listView1->Location = System::Drawing::Point(3, 3);
		   this->listView1->Name = L"listView1";
		   this->listView1->ShowItemToolTips = true;
		   this->listView1->Size = System::Drawing::Size(320, 160);
		   this->listView1->TabIndex = 5;
		   this->listView1->UseCompatibleStateImageBehavior = false;
		   this->listView1->View = System::Windows::Forms::View::Details;
		   // 
		   // name_col
		   // 
		   this->name_col->Text = L"Ten diem den";
		   this->name_col->Width = 132;
		   // 
		   // X
		   // 
		   this->X->Text = L"Toa do X";
		   this->X->Width = 104;
		   // 
		   // Y
		   // 
		   this->Y->Text = L"Toa do Y";
		   this->Y->Width = 412;
		   // 
		   // listView2
		   // 
		   this->listView2->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->listView2->GridLines = true;
		   this->listView2->HideSelection = false;
		   this->listView2->Location = System::Drawing::Point(492, 3);
		   this->listView2->Name = L"listView2";
		   this->listView2->Size = System::Drawing::Size(320, 160);
		   this->listView2->TabIndex = 7;
		   this->listView2->UseCompatibleStateImageBehavior = false;
		   this->listView2->View = System::Windows::Forms::View::Details;
		   // 
		   // tableLayoutPanel2
		   // 
		   this->tableLayoutPanel2->ColumnCount = 1;
		   this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   50)));
		   this->tableLayoutPanel2->Controls->Add(this->StartCity, 0, 1);
		   this->tableLayoutPanel2->Controls->Add(this->label2, 0, 0);
		   this->tableLayoutPanel2->Controls->Add(this->btnRun, 0, 2);
		   this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->tableLayoutPanel2->Location = System::Drawing::Point(329, 3);
		   this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
		   this->tableLayoutPanel2->RowCount = 3;
		   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50.84746F)));
		   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 49.15254F)));
		   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 41)));
		   this->tableLayoutPanel2->Size = System::Drawing::Size(157, 160);
		   this->tableLayoutPanel2->TabIndex = 8;
		   // 
		   // StartCity
		   // 
		   this->StartCity->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->StartCity->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		   this->StartCity->FormattingEnabled = true;
		   this->StartCity->Location = System::Drawing::Point(3, 63);
		   this->StartCity->Name = L"StartCity";
		   this->StartCity->Size = System::Drawing::Size(151, 33);
		   this->StartCity->TabIndex = 7;
		   // 
		   // label2
		   // 
		   this->label2->BackColor = System::Drawing::Color::PaleTurquoise;
		   this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(163)));
		   this->label2->Location = System::Drawing::Point(3, 0);
		   this->label2->Name = L"label2";
		   this->label2->Size = System::Drawing::Size(151, 60);
		   this->label2->TabIndex = 8;
		   this->label2->Text = L"chọn điểm xuất phát";
		   this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		   // 
		   // btnRun
		   // 
		   this->btnRun->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnRun->Location = System::Drawing::Point(3, 121);
		   this->btnRun->Name = L"btnRun";
		   this->btnRun->Size = System::Drawing::Size(151, 36);
		   this->btnRun->TabIndex = 9;
		   this->btnRun->Text = L"Bắt đầu";
		   this->btnRun->UseVisualStyleBackColor = true;
		   this->btnRun->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnRun_Click);
		   // 
		   // label1
		   // 
		   this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			   static_cast<System::Int32>(static_cast<System::Byte>(192)));
		   this->label1->Dock = System::Windows::Forms::DockStyle::Top;
		   this->label1->Location = System::Drawing::Point(0, 0);
		   this->label1->Name = L"label1";
		   this->label1->Padding = System::Windows::Forms::Padding(5);
		   this->label1->Size = System::Drawing::Size(815, 39);
		   this->label1->TabIndex = 0;
		   this->label1->Text = L"Travling Salesman Problem";
		   this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		   // 
		   // WebView_Map_Tab1
		   // 
		   this->WebView_Map_Tab1->AllowExternalDrop = true;
		   this->WebView_Map_Tab1->CreationProperties = nullptr;
		   this->WebView_Map_Tab1->DefaultBackgroundColor = System::Drawing::Color::White;
		   this->WebView_Map_Tab1->Dock = System::Windows::Forms::DockStyle::Left;
		   this->WebView_Map_Tab1->Location = System::Drawing::Point(3, 3);
		   this->WebView_Map_Tab1->Name = L"WebView_Map_Tab1";
		   this->WebView_Map_Tab1->Size = System::Drawing::Size(611, 810);
		   this->WebView_Map_Tab1->TabIndex = 0;
		   this->WebView_Map_Tab1->ZoomFactor = 1;
		   // 
		   // RealDistance
		   // 
		   this->RealDistance->Controls->Add(this->tableLayoutPanel13);
		   this->RealDistance->Controls->Add(this->tableLayoutPanel12);
		   this->RealDistance->Controls->Add(this->tableLayoutPanel11);
		   this->RealDistance->Controls->Add(this->tableLayoutPanel9);
		   this->RealDistance->Controls->Add(this->label5);
		   this->RealDistance->Controls->Add(this->WebView_Map_Tab2);
		   this->RealDistance->Location = System::Drawing::Point(4, 34);
		   this->RealDistance->Name = L"RealDistance";
		   this->RealDistance->Padding = System::Windows::Forms::Padding(3);
		   this->RealDistance->Size = System::Drawing::Size(1432, 816);
		   this->RealDistance->TabIndex = 1;
		   this->RealDistance->Text = L"Mô hình thực tế";
		   this->RealDistance->UseVisualStyleBackColor = true;
		   // 
		   // tableLayoutPanel13
		   // 
		   this->tableLayoutPanel13->ColumnCount = 4;
		   this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   25)));
		   this->tableLayoutPanel13->Controls->Add(this->btnKarat, 0, 0);
		   this->tableLayoutPanel13->Controls->Add(this->btnGreedy2, 1, 0);
		   this->tableLayoutPanel13->Controls->Add(this->btnXoa, 2, 0);
		   this->tableLayoutPanel13->Controls->Add(this->btnThoat, 3, 0);
		   this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Bottom;
		   this->tableLayoutPanel13->Location = System::Drawing::Point(786, 748);
		   this->tableLayoutPanel13->Margin = System::Windows::Forms::Padding(2);
		   this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
		   this->tableLayoutPanel13->RowCount = 1;
		   this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel13->Size = System::Drawing::Size(643, 65);
		   this->tableLayoutPanel13->TabIndex = 5;
		   // 
		   // btnKarat
		   // 
		   this->btnKarat->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnKarat->Location = System::Drawing::Point(2, 2);
		   this->btnKarat->Margin = System::Windows::Forms::Padding(2);
		   this->btnKarat->Name = L"btnKarat";
		   this->btnKarat->Size = System::Drawing::Size(156, 61);
		   this->btnKarat->TabIndex = 0;
		   this->btnKarat->Text = L"Karatsuba";
		   this->btnKarat->UseVisualStyleBackColor = true;
		   // 
		   // btnGreedy2
		   // 
		   this->btnGreedy2->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnGreedy2->Location = System::Drawing::Point(162, 2);
		   this->btnGreedy2->Margin = System::Windows::Forms::Padding(2);
		   this->btnGreedy2->Name = L"btnGreedy2";
		   this->btnGreedy2->Size = System::Drawing::Size(156, 61);
		   this->btnGreedy2->TabIndex = 1;
		   this->btnGreedy2->Text = L"Greedy";
		   this->btnGreedy2->UseVisualStyleBackColor = true;
		   // 
		   // btnXoa
		   // 
		   this->btnXoa->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnXoa->Location = System::Drawing::Point(322, 2);
		   this->btnXoa->Margin = System::Windows::Forms::Padding(2);
		   this->btnXoa->Name = L"btnXoa";
		   this->btnXoa->Size = System::Drawing::Size(156, 61);
		   this->btnXoa->TabIndex = 2;
		   this->btnXoa->Text = L"Xóa";
		   this->btnXoa->UseVisualStyleBackColor = true;
		   this->btnXoa->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnXoa_Click);
		   // 
		   // btnThoat
		   // 
		   this->btnThoat->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnThoat->Location = System::Drawing::Point(482, 2);
		   this->btnThoat->Margin = System::Windows::Forms::Padding(2);
		   this->btnThoat->Name = L"btnThoat";
		   this->btnThoat->Size = System::Drawing::Size(159, 61);
		   this->btnThoat->TabIndex = 3;
		   this->btnThoat->Text = L"Thoát";
		   this->btnThoat->UseVisualStyleBackColor = true;
		   this->btnThoat->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnThoat_Click);
		   // 
		   // tableLayoutPanel12
		   // 
		   this->tableLayoutPanel12->ColumnCount = 2;
		   this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   50)));
		   this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   50)));
		   this->tableLayoutPanel12->Controls->Add(this->groupBox5, 0, 0);
		   this->tableLayoutPanel12->Controls->Add(this->groupBox6, 1, 0);
		   this->tableLayoutPanel12->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel12->Location = System::Drawing::Point(786, 326);
		   this->tableLayoutPanel12->Name = L"tableLayoutPanel12";
		   this->tableLayoutPanel12->RowCount = 1;
		   this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		   this->tableLayoutPanel12->Size = System::Drawing::Size(643, 371);
		   this->tableLayoutPanel12->TabIndex = 4;
		   // 
		   // groupBox5
		   // 
		   this->groupBox5->Controls->Add(this->txtReal_DetailTour);
		   this->groupBox5->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->groupBox5->Location = System::Drawing::Point(3, 3);
		   this->groupBox5->Name = L"groupBox5";
		   this->groupBox5->Size = System::Drawing::Size(315, 365);
		   this->groupBox5->TabIndex = 0;
		   this->groupBox5->TabStop = false;
		   this->groupBox5->Text = L"Thông tin hành trình";
		   // 
		   // txtReal_DetailTour
		   // 
		   this->txtReal_DetailTour->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->txtReal_DetailTour->Location = System::Drawing::Point(3, 26);
		   this->txtReal_DetailTour->Multiline = true;
		   this->txtReal_DetailTour->Name = L"txtReal_DetailTour";
		   this->txtReal_DetailTour->ReadOnly = true;
		   this->txtReal_DetailTour->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		   this->txtReal_DetailTour->Size = System::Drawing::Size(309, 336);
		   this->txtReal_DetailTour->TabIndex = 0;
		   // 
		   // groupBox6
		   // 
		   this->groupBox6->Controls->Add(this->lstReal_SaveTour);
		   this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->groupBox6->Location = System::Drawing::Point(324, 3);
		   this->groupBox6->Name = L"groupBox6";
		   this->groupBox6->Size = System::Drawing::Size(316, 365);
		   this->groupBox6->TabIndex = 1;
		   this->groupBox6->TabStop = false;
		   this->groupBox6->Text = L"Tập  các hành trình từ điểm xuất phát";
		   // 
		   // lstReal_SaveTour
		   // 
		   this->lstReal_SaveTour->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
			   this->columnHeader5,
				   this->columnHeader6
		   });
		   this->lstReal_SaveTour->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->lstReal_SaveTour->HideSelection = false;
		   this->lstReal_SaveTour->Location = System::Drawing::Point(3, 26);
		   this->lstReal_SaveTour->Name = L"lstReal_SaveTour";
		   this->lstReal_SaveTour->Size = System::Drawing::Size(310, 336);
		   this->lstReal_SaveTour->TabIndex = 0;
		   this->lstReal_SaveTour->UseCompatibleStateImageBehavior = false;
		   this->lstReal_SaveTour->View = System::Windows::Forms::View::Details;
		   // 
		   // columnHeader5
		   // 
		   this->columnHeader5->Text = L"Hành trình";
		   this->columnHeader5->Width = 168;
		   // 
		   // columnHeader6
		   // 
		   this->columnHeader6->Text = L"Chi phí";
		   this->columnHeader6->Width = 155;
		   // 
		   // tableLayoutPanel11
		   // 
		   this->tableLayoutPanel11->ColumnCount = 3;
		   this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   20)));
		   this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   60)));
		   this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   20)));
		   this->tableLayoutPanel11->Controls->Add(this->label6, 0, 0);
		   this->tableLayoutPanel11->Controls->Add(this->textBox_FinalResult, 1, 0);
		   this->tableLayoutPanel11->Controls->Add(this->textBox_FinalCost, 2, 0);
		   this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel11->Location = System::Drawing::Point(786, 265);
		   this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
		   this->tableLayoutPanel11->RowCount = 1;
		   this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel11->Size = System::Drawing::Size(643, 61);
		   this->tableLayoutPanel11->TabIndex = 3;
		   // 
		   // label6
		   // 
		   this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(163)));
		   this->label6->Location = System::Drawing::Point(3, 0);
		   this->label6->Name = L"label6";
		   this->label6->Size = System::Drawing::Size(122, 61);
		   this->label6->TabIndex = 0;
		   this->label6->Text = L"Chu trình tối ưu";
		   this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		   // 
		   // textBox_FinalResult
		   // 
		   this->textBox_FinalResult->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textBox_FinalResult->Location = System::Drawing::Point(131, 3);
		   this->textBox_FinalResult->Multiline = true;
		   this->textBox_FinalResult->Name = L"textBox_FinalResult";
		   this->textBox_FinalResult->ReadOnly = true;
		   this->textBox_FinalResult->Size = System::Drawing::Size(379, 55);
		   this->textBox_FinalResult->TabIndex = 1;
		   // 
		   // textBox_FinalCost
		   // 
		   this->textBox_FinalCost->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->textBox_FinalCost->Location = System::Drawing::Point(516, 3);
		   this->textBox_FinalCost->Multiline = true;
		   this->textBox_FinalCost->Name = L"textBox_FinalCost";
		   this->textBox_FinalCost->ReadOnly = true;
		   this->textBox_FinalCost->Size = System::Drawing::Size(124, 55);
		   this->textBox_FinalCost->TabIndex = 2;
		   // 
		   // tableLayoutPanel9
		   // 
		   this->tableLayoutPanel9->ColumnCount = 2;
		   this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   60)));
		   this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   40)));
		   this->tableLayoutPanel9->Controls->Add(this->lstMatrix_RealCost, 0, 0);
		   this->tableLayoutPanel9->Controls->Add(this->tableLayoutPanel10, 1, 0);
		   this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Top;
		   this->tableLayoutPanel9->Location = System::Drawing::Point(786, 56);
		   this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
		   this->tableLayoutPanel9->RowCount = 1;
		   this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		   this->tableLayoutPanel9->Size = System::Drawing::Size(643, 209);
		   this->tableLayoutPanel9->TabIndex = 2;
		   // 
		   // lstMatrix_RealCost
		   // 
		   this->lstMatrix_RealCost->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->lstMatrix_RealCost->GridLines = true;
		   this->lstMatrix_RealCost->HideSelection = false;
		   this->lstMatrix_RealCost->Location = System::Drawing::Point(3, 3);
		   this->lstMatrix_RealCost->Name = L"lstMatrix_RealCost";
		   this->lstMatrix_RealCost->Size = System::Drawing::Size(379, 203);
		   this->lstMatrix_RealCost->TabIndex = 0;
		   this->lstMatrix_RealCost->UseCompatibleStateImageBehavior = false;
		   // 
		   // tableLayoutPanel10
		   // 
		   this->tableLayoutPanel10->ColumnCount = 1;
		   this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			   50)));
		   this->tableLayoutPanel10->Controls->Add(this->cbbSelectCity, 0, 0);
		   this->tableLayoutPanel10->Controls->Add(this->btnReal_Run, 0, 1);
		   this->tableLayoutPanel10->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->tableLayoutPanel10->Location = System::Drawing::Point(388, 3);
		   this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
		   this->tableLayoutPanel10->RowCount = 2;
		   this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		   this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
			   62)));
		   this->tableLayoutPanel10->Size = System::Drawing::Size(252, 203);
		   this->tableLayoutPanel10->TabIndex = 2;
		   // 
		   // cbbSelectCity
		   // 
		   this->cbbSelectCity->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->cbbSelectCity->FormattingEnabled = true;
		   this->cbbSelectCity->Location = System::Drawing::Point(3, 3);
		   this->cbbSelectCity->Name = L"cbbSelectCity";
		   this->cbbSelectCity->Size = System::Drawing::Size(246, 33);
		   this->cbbSelectCity->TabIndex = 0;
		   // 
		   // btnReal_Run
		   // 
		   this->btnReal_Run->Dock = System::Windows::Forms::DockStyle::Fill;
		   this->btnReal_Run->Location = System::Drawing::Point(3, 144);
		   this->btnReal_Run->Name = L"btnReal_Run";
		   this->btnReal_Run->Size = System::Drawing::Size(246, 56);
		   this->btnReal_Run->TabIndex = 1;
		   this->btnReal_Run->Text = L"Thực hiện";
		   this->btnReal_Run->UseVisualStyleBackColor = true;
		   this->btnReal_Run->Click += gcnew System::EventHandler(this, &Dynamic_Programming::btnReal_Run_Click);
		   // 
		   // label5
		   // 
		   this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			   static_cast<System::Int32>(static_cast<System::Byte>(192)));
		   this->label5->Dock = System::Windows::Forms::DockStyle::Top;
		   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			   static_cast<System::Byte>(163)));
		   this->label5->Location = System::Drawing::Point(786, 3);
		   this->label5->Name = L"label5";
		   this->label5->Padding = System::Windows::Forms::Padding(10);
		   this->label5->Size = System::Drawing::Size(643, 53);
		   this->label5->TabIndex = 1;
		   this->label5->Text = L"Travling Salesman Problem ( Held - Karp)";
		   this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		   // 
		   // WebView_Map_Tab2
		   // 
		   this->WebView_Map_Tab2->AllowExternalDrop = true;
		   this->WebView_Map_Tab2->CreationProperties = nullptr;
		   this->WebView_Map_Tab2->DefaultBackgroundColor = System::Drawing::Color::White;
		   this->WebView_Map_Tab2->Dock = System::Windows::Forms::DockStyle::Left;
		   this->WebView_Map_Tab2->Location = System::Drawing::Point(3, 3);
		   this->WebView_Map_Tab2->Name = L"WebView_Map_Tab2";
		   this->WebView_Map_Tab2->Size = System::Drawing::Size(783, 810);
		   this->WebView_Map_Tab2->TabIndex = 0;
		   this->WebView_Map_Tab2->ZoomFactor = 1;
		   // 
		   // errorProvider1
		   // 
		   this->errorProvider1->ContainerControl = this;
		   // 
		   // Dynamic_Programming
		   // 
		   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		   this->ClientSize = System::Drawing::Size(1440, 854);
		   this->Controls->Add(this->tabControl1);
		   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
		   this->Name = L"Dynamic_Programming";
		   this->Text = L"Dynamic_Programming";
		   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
		   this->Load += gcnew System::EventHandler(this, &Dynamic_Programming::Dynamic_Programming_Load);
		   this->tabControl1->ResumeLayout(false);
		   this->EulideanTab->ResumeLayout(false);
		   this->panel1->ResumeLayout(false);
		   this->tabControl2->ResumeLayout(false);
		   this->tabTopDown->ResumeLayout(false);
		   this->tableLayoutPanel5->ResumeLayout(false);
		   this->tableLayoutPanel4->ResumeLayout(false);
		   this->tableLayoutPanel4->PerformLayout();
		   this->tableLayoutPanel3->ResumeLayout(false);
		   this->groupBox1->ResumeLayout(false);
		   this->groupBox1->PerformLayout();
		   this->groupBox2->ResumeLayout(false);
		   this->tabBottomUp->ResumeLayout(false);
		   this->tableLayoutPanel8->ResumeLayout(false);
		   this->tableLayoutPanel7->ResumeLayout(false);
		   this->tableLayoutPanel7->PerformLayout();
		   this->tableLayoutPanel6->ResumeLayout(false);
		   this->groupBox3->ResumeLayout(false);
		   this->groupBox3->PerformLayout();
		   this->groupBox4->ResumeLayout(false);
		   this->tableLayoutPanel1->ResumeLayout(false);
		   this->tableLayoutPanel2->ResumeLayout(false);
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WebView_Map_Tab1))->EndInit();
		   this->RealDistance->ResumeLayout(false);
		   this->tableLayoutPanel13->ResumeLayout(false);
		   this->tableLayoutPanel12->ResumeLayout(false);
		   this->groupBox5->ResumeLayout(false);
		   this->groupBox5->PerformLayout();
		   this->groupBox6->ResumeLayout(false);
		   this->tableLayoutPanel11->ResumeLayout(false);
		   this->tableLayoutPanel11->PerformLayout();
		   this->tableLayoutPanel9->ResumeLayout(false);
		   this->tableLayoutPanel10->ResumeLayout(false);
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WebView_Map_Tab2))->EndInit();
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
		   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
		   this->ResumeLayout(false);

	   }
#pragma endregion
	   // load form hiển thị bản đồ
private: System::Void Dynamic_Programming_Load(System::Object^ sender, System::EventArgs^ e)
{
	cities.clear();
	listView1->Items->Clear();
	WebView_Map_Tab1->Source = gcnew Uri(Application::StartupPath + "\\map\\map.html");
	WebView_Map_Tab2->Source = gcnew Uri(Application::StartupPath + "\\map\\map_real.html");
	// bắt các địa điểm marker từ bản đồ
	WebView_Map_Tab1->CoreWebView2InitializationCompleted +=
		gcnew EventHandler<CoreWebView2InitializationCompletedEventArgs^>(
			this, &Dynamic_Programming::Hook_MarkerFromMap);
	WebView_Map_Tab2->CoreWebView2InitializationCompleted +=
		gcnew EventHandler<CoreWebView2InitializationCompletedEventArgs^>(
			this, &Dynamic_Programming::Hook_MarkerFromMap_Real);


}

#define EPS 1e-4
private: 
	void InputCities(System::Object^ sender, Microsoft::Web::WebView2::Core::CoreWebView2WebMessageReceivedEventArgs^ e);
	void RemoveCity(double lat, double lng);
	void UpdateListView();
	void Build_Matrix_Euclide();
	void Hook_MarkerFromMap(System::Object^ sender, CoreWebView2InitializationCompletedEventArgs^ e);
	void Load_StartPoint_CBB();
	double TSP_TopDown(int u, int mask, int start);
	void Run_TSP_TopDown();
	std::string maskToString(int mask);
	std::string MaskToNameList(int mask);
	void LogState(int u, int mask, double cost);
	void DrawOptimalRoute(const std::vector<int>& path);
	void TSP_BottomUp_HeldKarp();
	double Run_TSP_BottomUp();
	// tab2
	void Hook_MarkerFromMap_Real(System::Object^ sender, CoreWebView2InitializationCompletedEventArgs^ e);
	void InputCities_Real(System::Object^ sender, Microsoft::Web::WebView2::Core::CoreWebView2WebMessageReceivedEventArgs^ e);
	void RemoveCity_ByName(const std::string& name);
	void UpdateRealMatrix(const std::string& a, const std::string& b, double dist);
	int FindCityIndex(const std::string& name);
	void UpdateListViewRealMatrix();
	void Run_TSP_Real_BottomUp();
	void Show_Real_Path_Info(const std::vector<int>& path, double cost);
	void SendPathToJS(const std::vector<int>& path);
	void Print_Real_Final_Result(const std::vector<int>& path, double cost);
	std::string ConvertMaskToString(int mask);
	void SendOptimalForReal(const std::vector<int>& path);
	// doc file txt
private: System::Void btnRun_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listView1->Items->Count == 0||StartCity->SelectedIndex==-1)
	{
		MessageBox::Show("Vui long them cac diem den va chon diem xuat phat truoc khi chay thuat toan!","Thong bao",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		return;
	}
	else if (tabControl2->SelectedIndex == 0)
	{		
		Run_TSP_TopDown();
	}
	else 
	{
		Run_TSP_BottomUp();
	}
}

private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	cities.clear();
	listView1->Items->Clear();
	listView2->Items->Clear();
	textBoxTour->Clear();
	textBoxCost->Clear();
	textBoxResult->Clear();
	listViewMemo->Items->Clear();
	StartCity->Items->Clear();
	WebView_Map_Tab1->ExecuteScriptAsync("clearAll();");
}
private: System::Void btnBU_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
	cities.clear();
	listView1->Items->Clear();
	listView2->Items->Clear();
	textBoxTour->Clear();
	textBoxCost->Clear();
	textTour_BottomUp->Clear();
	listViewBottomUp->Clear();
	textBoxBU_result->Clear();
	textBoxBU_Cost->Clear();
	StartCity->Items->Clear();
	WebView_Map_Tab1->ExecuteScriptAsync("clearAll();");
}
private: System::Void btnGreedy_Click(System::Object^ sender, System::EventArgs^ e) {
	Nhom13BaoCaoHocPhan::Greedy^ g = gcnew Nhom13BaoCaoHocPhan::Greedy();
	g->ShowDialog();

}
private: System::Void btnKaratsuba_Click(System::Object^ sender, System::EventArgs^ e) {
	Nhom13BaoCaoHocPhan::Karatsuba^ k = gcnew Nhom13BaoCaoHocPhan::Karatsuba();
	k->ShowDialog();
}
private: System::Void btnReal_Run_Click(System::Object^ sender, System::EventArgs^ e) {
	Run_TSP_Real_BottomUp();
}

private: System::Void btnThoat_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnXoa_Click(System::Object^ sender, System::EventArgs^ e) {
	cities_real.clear();
	listView2->Items->Clear();
	lstMatrix_RealCost->Columns->Clear();
	lstMatrix_RealCost->Items->Clear();
	txtReal_DetailTour->Clear();
	lstReal_SaveTour->Items->Clear();
	textBox_FinalResult->Clear();
	textBox_FinalCost->Clear();
	cbbSelectCity->Items->Clear();
	WebView_Map_Tab2->ExecuteScriptAsync("clearAll();");
}
private: System::Void btnLoadFileTxt_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "Text files (*.txt)|*.txt";

}
};

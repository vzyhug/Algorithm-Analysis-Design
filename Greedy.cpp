#include "Greedy.h"
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace Nhom13BaoCaoHocPhan;

// ----------------------------------------------------- load ma tran 
void Greedy::buildMatrix()
{
	if (dataPlace->Rows->Count - 1 == 0)
	{
		MessageBox::Show("Vui lòng nhập điểm giao hàng trước khi xây dựng ma trận!",
			"Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	// lấy số dòng của điểm giao hàng
	int rowCount = dataPlace->Rows->Count;
	if (dataPlace->AllowUserToAddRows == true) rowCount--;
	// xây dựng ma trận
	dataMatrix->ColumnCount = rowCount;
	dataMatrix->RowCount = rowCount;
	// đặt tên cột
	for (int j = 0; j < rowCount; j++)
	{
		dataMatrix->Columns[j]->HeaderText =
			dataPlace->Rows[j]->Cells[0]->Value->ToString();
	}

	for (int i = 0; i < rowCount; i++)
	{
		// đặt tên hàng và gán giá trị 0 cho các ô trên đường chéo chính
		dataMatrix->Rows[i]->HeaderCell->Value =
			dataPlace->Rows[i]->Cells[0]->Value->ToString();
		for (int j = 0; j < rowCount; j++)
		{
			if (i == j)
			{
				dataMatrix->Rows[i]->Cells[j]->Value = 0;
				// vô hiệu hóa ô trên đường chéo chính , màu hồng
				dataMatrix->Rows[i]->Cells[j]->ReadOnly = true;
				dataMatrix->Rows[i]->Cells[j]->Style->BackColor = Color::LightPink;
			}
		}
		cbbStart->Items->Add(dataMatrix->Rows[i]->HeaderCell->Value);
	}
}

// ----------------------------------------------------- thuật toán tham lam 
void Greedy::GreedyAlgorithm(int start)
{
    int n = dataMatrix->Rows->Count;
    if (n == 0) return;

    std::vector<bool> visited(n, false);
    visited[start] = true;

    int current = start;
    std::vector<int> path;
    path.push_back(current);

    int totalCost = 0;

    // Lưu giải thích chi tiết cho từng bước
    std::string detail;

    // ==============================
    // VÒNG LẶP THAM LAM
    // ==============================
    for (int step = 1; step < n; step++)
    {
        int next = -1;
        int minCost = INT_MAX;

        // Chuỗi tạm để ghi lại các lựa chọn ở bước này
        std::string stepDetail;

        // Tên điểm hiện tại
        System::String^ curNameManaged =
            dataMatrix->Rows[current]->HeaderCell->Value->ToString();
        std::string curName =
            msclr::interop::marshal_as<std::string>(curNameManaged);

        stepDetail += "Buoc " + std::to_string(step) +
            ": dang dung tai " + curName + ".\r\n";
        stepDetail += "  Xet cac diem chua tham:\r\n";

        // Duyệt tất cả điểm chưa thăm
        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                System::Object^ cellVal =
                    dataMatrix->Rows[current]->Cells[j]->Value;

                // Bảo vệ: nếu ô trống thì bỏ qua
                if (cellVal == nullptr || cellVal == System::DBNull::Value)
                    continue;

                int cost = Convert::ToInt32(cellVal);

                // Lấy tên điểm j
                System::String^ nameManaged =
                    dataMatrix->Rows[j]->HeaderCell->Value->ToString();
                std::string name =
                    msclr::interop::marshal_as<std::string>(nameManaged);

                // Ghi vào danh sách ứng viên
                stepDetail += "    - Di den " + name +
                    " co chi phi " + std::to_string(cost) + "\r\n";

                // Cập nhật min
                if (cost < minCost)
                {
                    minCost = cost;
                    next = j;
                }
            }
        }

        if (next != -1)
        {
            visited[next] = true;
            path.push_back(next);
            totalCost += minCost;

            // Tên điểm được chọn
            System::String^ nextNameManaged =
                dataMatrix->Rows[next]->HeaderCell->Value->ToString();
            std::string nextName =
                msclr::interop::marshal_as<std::string>(nextNameManaged);

            // Giải thích vì sao chọn điểm này
            stepDetail += "  => Chon di den " + nextName +
                " vi co chi phi nho nhat tai buoc nay = " +
                std::to_string(minCost) + ".\r\n\r\n";

            detail += stepDetail;

            current = next;
        }
    }

    // ===================================
    // TRỞ VỀ ĐIỂM XUẤT PHÁT
    // ===================================
    System::Object^ backVal =
        dataMatrix->Rows[current]->Cells[start]->Value;
    int backCost = 0;
    if (backVal != nullptr && backVal != System::DBNull::Value)
        backCost = Convert::ToInt32(backVal);

    totalCost += backCost;
    path.push_back(start);

    // Giải thích bước quay về
    System::String^ lastNameManaged =
        dataMatrix->Rows[current]->HeaderCell->Value->ToString();
    System::String^ startNameManaged =
        dataMatrix->Rows[start]->HeaderCell->Value->ToString();
    std::string lastName =
        msclr::interop::marshal_as<std::string>(lastNameManaged);
    std::string startName =
        msclr::interop::marshal_as<std::string>(startNameManaged);

    detail += "Buoc cuoi: tu " + lastName +
        " quay ve " + startName +
        " voi chi phi " + std::to_string(backCost) + ".\r\n";
    detail += "=> Tong chi phi cua chu trinh tham lam = " +
        std::to_string(totalCost) + ".\r\n";

    // ===================================
    // HIỂN THỊ ĐƯỜNG ĐI
    // ===================================
    std::string result;
    for (size_t i = 0; i < path.size(); i++)
    {
        System::String^ nameManaged =
            dataMatrix->Rows[path[i]]->HeaderCell->Value->ToString();
        std::string name =
            msclr::interop::marshal_as<std::string>(nameManaged);

        result += name;
        if (i != path.size() - 1)
            result += " -> ";
    }

    txtResult->Text = gcnew System::String(result.c_str());
    txtCost->Text = "Tong chi phi: " + totalCost.ToString();
    txtDetail->Text = gcnew System::String(detail.c_str());
}
void Greedy::LoadMatrix_FromTxt(String^ filePath)
{
    try
    {
        // ===== CLEAR BẢNG =====
        dataMatrix->Columns->Clear();
        dataMatrix->Rows->Clear();

        array<String^>^ lines = System::IO::File::ReadAllLines(filePath);
        if (lines->Length < 2)
            throw gcnew Exception("File quá ngắn, không đủ dữ liệu.");

        // ===== HEADER =====
        array<String^>^ headers = lines[0]->Split(' ');
        int n = headers->Length;

        if (n < 2)
            throw gcnew Exception("Header không hợp lệ.");

        // Tạo cột
        for (int i = 0; i < n; i++)
        {
            DataGridViewTextBoxColumn^ col = gcnew DataGridViewTextBoxColumn();
            col->HeaderText = headers[i];
            dataMatrix->Columns->Add(col);
        }

        // ===== KIỂM TRA SỐ DÒNG =====
        int dataLines = lines->Length - 1;
        if (dataLines < n)
            throw gcnew Exception("Số dòng dữ liệu ít hơn số điểm.");
        if (dataLines > n)
            throw gcnew Exception("Số dòng dữ liệu nhiều hơn số điểm.");

        // ===== LOAD MA TRẬN =====
        for (int i = 1; i <= n; i++)
        {
            array<String^>^ parts = lines[i]->Split(' ');

            if (parts->Length < n)
                throw gcnew Exception("Dòng " + i + " thiếu cột.");
            if (parts->Length > n)
                throw gcnew Exception("Dòng " + i + " dư cột.");

            int rowIdx = dataMatrix->Rows->Add();
            DataGridViewRow^ row = dataMatrix->Rows[rowIdx];
            row->HeaderCell->Value = headers[i - 1];

            for (int j = 0; j < n; j++)
            {
                // parse
                int value = 0;
                if (!Int32::TryParse(parts[j], value))
                    throw gcnew Exception("Giá trị không phải số tại dòng " + i);

                // fix đường chéo chính
                if ((i - 1) == j)
                    value = 0;

                row->Cells[j]->Value = value;
            }
        }
    }
    catch (Exception^ ex)
    {
        // CLEAR lại bảng để tránh dữ liệu lỗi còn sót
        dataMatrix->Columns->Clear();
        dataMatrix->Rows->Clear();

        MessageBox::Show("Lỗi khi đọc file:\n" + ex->Message,
            "Lỗi", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
}


// ----------------------------------------------------- chuẩn bị & chạy thuật toán
// ----------------------------------------------------- khóa đường chéo chính và chặn nhập khác số

void Greedy::Run_Greedy()
{
	// thuc hien thuat toan
	int startIndex = cbbStart->SelectedIndex;
	GreedyAlgorithm(startIndex);
}

#include "Karatsuba.h"
#include <string>
#include <algorithm>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace Nhom13BaoCaoHocPhan;

std::string Karatsuba::trimZeros(const std::string& s)
{
    size_t pos = s.find_first_not_of('0');
    if (pos == std::string::npos) return "0";
    return s.substr(pos);
}

std::string Karatsuba::addString(const std::string& a, const std::string& b)
{
    std::string A = a, B = b;
    int carry = 0;
    int i = A.size() - 1, j = B.size() - 1;
    std::string r = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int x = (i >= 0 ? A[i] - '0' : 0);
        int y = (j >= 0 ? B[j] - '0' : 0);

        int sum = x + y + carry;
        r.push_back(char(sum % 10 + '0'));
        carry = sum / 10;

        i--; j--;
    }

    std::reverse(r.begin(), r.end());
    return trimZeros(r);
}

std::string Karatsuba::subString(const std::string& a, const std::string& b)
{
    std::string A = a, B = b;
    int i = A.size() - 1, j = B.size() - 1;
    int borrow = 0;
    std::string r = "";

    while (i >= 0)
    {
        int x = A[i] - '0' - borrow;
        int y = (j >= 0 ? B[j] - '0' : 0);

        if (x < y)
        {
            x += 10;
            borrow = 1;
        }
        else borrow = 0;

        r.push_back(char(x - y + '0'));
        i--; j--;
    }

    while (r.size() > 1 && r.back() == '0') r.pop_back();

    std::reverse(r.begin(), r.end());
    return trimZeros(r);
}

std::string Karatsuba::shiftString(const std::string& a, int n)
{
    std::string r = a;
    for (int i = 0; i < n; i++) r += "0";
    return r;
}

// -----------------------------------------------------
//  THUẬT TOÁN KARATSUBA (ĐÃ FIX LỖI ĐÓNG NGOẶC)
// -----------------------------------------------------
std::string Karatsuba::karatsuba(const std::string& x, const std::string& y, TextBox^ output)
{
    output->AppendText("Goi Karatsuba(" +
        gcnew String(x.c_str()) + ", " +
        gcnew String(y.c_str()) + ")\r\n");

    size_t n = (std::max)(x.size(), y.size());
    if (n == 1)
    {
        int val = (x[0] - '0') * (y[0] - '0');
        output->AppendText(" --> Base case = " + val.ToString() + "\r\n\r\n");
        return std::to_string(val);
    }

    // === FIX QUAN TRỌNG ===
    // Đây là kết thúc phần xử lý base case
    // Sau đó tiếp tục thuật toán -> KHÔNG BỊ MẤT NGOẶC
    // ========================

    int m = n / 2;

    std::string X = x, Y = y;
    while (X.size() < n) X = "0" + X;
    while (Y.size() < n) Y = "0" + Y;

    std::string Xl = X.substr(0, X.size() - m);
    std::string Xr = X.substr(X.size() - m);
    std::string Yl = Y.substr(0, Y.size() - m);
    std::string Yr = Y.substr(Y.size() - m);

    output->AppendText("Chia X --> (" + gcnew String(Xl.c_str()) +
        ", " + gcnew String(Xr.c_str()) + ")\r\n");
    output->AppendText("Chia Y --> (" + gcnew String(Yl.c_str()) +
        ", " + gcnew String(Yr.c_str()) + ")\r\n\r\n");

    std::string P1 = karatsuba(Xl, Yl, output);
    std::string P2 = karatsuba(Xr, Yr, output);
    std::string P3 = karatsuba(addString(Xl, Xr), addString(Yl, Yr), output);

    std::string mid = subString(subString(P3, P1), P2);

    std::string result =
        addString(
            addString(shiftString(P1, 2 * m), shiftString(mid, m)),
            P2
        );

    output->AppendText("Ket hop --> " + gcnew String(result.c_str()) + "\r\n\r\n");
    return result;
}

// -----------------------------------------------------
//  BUTTON CLICK
// -----------------------------------------------------

#include "Dynamic_Programming.h"
#include <cmath>
#include <vector>
#include <cstring>
#include <map>

std::vector<std::vector<double>> dist;
std::map<std::pair<int, int>, double> dp;
std::map<std::pair<int, int>, int> parent;
std::string bottomUpLog;
std::vector<int> path_BottomUp;
double bestCost_BottomUp;
std::vector<std::vector<double>> dpBottomUp;
std::vector<std::vector<double>> realDist;
std::vector<City> cities_real;
std::vector<std::vector<double>> dist_real;
std::vector<std::vector<double>> dp_real;
std::vector<std::vector<int>> parent_real;

using namespace System::Globalization;
using namespace System::Text;

std::vector<City> cities;
// them cac diem
void Dynamic_Programming::InputCities(System::Object^ sender, Microsoft::Web::WebView2::Core::CoreWebView2WebMessageReceivedEventArgs^ e)
{
	String^ msg = e->TryGetWebMessageAsString();
	array<String^>^ parts = msg->Split('|');
	// message format:  name | lat | lng | X | Y
	if (parts->Length == 5 && !parts[0]->ToUpper()->Equals("DELETE"))
	{
		City city;

		msclr::interop::marshal_context ctx;

		city.name = ctx.marshal_as<std::string>(parts[0]);

		city.lat = System::Double::Parse(parts[1],
			System::Globalization::CultureInfo::InvariantCulture);

		city.lng = System::Double::Parse(parts[2],
			System::Globalization::CultureInfo::InvariantCulture);


		city.x = (long long)Math::Round(Convert::ToDouble(parts[3]));  // pixel X
		city.y = (long long)Math::Round(Convert::ToDouble(parts[4]));  // pixel Y


		if (cities.size() >= 12)
		{
			MessageBox::Show("so luong qua 12 se anh huong toc do", "Thong bao", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		cities.push_back(city);
		Load_StartPoint_CBB();
		UpdateListView();
		return;

	}
	// Xoá địa điểm 
	if (parts->Length >= 3 && parts[0]->ToUpper()->Equals("DELETE"))
	{
		using namespace System::Globalization;

		double lat = System::Double::Parse(parts[1], CultureInfo::InvariantCulture);
		double lng = System::Double::Parse(parts[2], CultureInfo::InvariantCulture);

		RemoveCity(lat, lng);
		return;
	}
	if (msg == "CLEAR_ALL")
	{
		cities.clear();
		Load_StartPoint_CBB();
		UpdateListView();

		return;
	}


}

/// xoá địa điểm khỏi danh sách
void Dynamic_Programming:: RemoveCity(double lat, double lng)
{
	for (int i = 0; i < (int)cities.size(); i++)
	{
		if (fabs(cities[i].lat - lat) < EPS && fabs(cities[i].lng - lng) < EPS)
		{
			double X = cities[i].x;
			double Y = cities[i].y;

			// Xóa khỏi vector
			cities.erase(cities.begin() + i);

			// Xóa khỏi ListView theo X,Y
			for (int j = listView1->Items->Count - 1; j >= 0; j--)
			{
				double listX = Convert::ToDouble(listView1->Items[j]->SubItems[1]->Text);
				double listY = Convert::ToDouble(listView1->Items[j]->SubItems[2]->Text);

				if (fabs(listX - X) < EPS && fabs(listY - Y) < EPS)
				{
					listView1->Items->RemoveAt(j);
					break;
				}
			}

			break;
		}
	}
	UpdateListView();   
	Load_StartPoint_CBB();

}
// bắt thông tin marker từ bản đồ
void Dynamic_Programming:: Hook_MarkerFromMap(System::Object^ sender, CoreWebView2InitializationCompletedEventArgs^ e)
{
	if (tabControl1->SelectedIndex==0 &&WebView_Map_Tab1->CoreWebView2 != nullptr)
	{
		WebView_Map_Tab1->CoreWebView2->WebMessageReceived +=
			gcnew EventHandler<CoreWebView2WebMessageReceivedEventArgs^>(
				this, &Dynamic_Programming::InputCities);
	}
	else if (tabControl1->SelectedIndex == 1 && WebView_Map_Tab2->CoreWebView2 != nullptr)
	{
		WebView_Map_Tab2->CoreWebView2->WebMessageReceived +=
		 gcnew EventHandler<CoreWebView2WebMessageReceivedEventArgs^>(
			 this, &Dynamic_Programming::InputCities);
	}
	else
	{
		return;
	}
}

	   // cập nhật danh sách các địa điểm vào ListView
void Dynamic_Programming:: UpdateListView()
{
	listView1->Items->Clear();
	for (const City& city : cities)
	{
		ListViewItem^ item = gcnew ListViewItem(gcnew String(city.name.c_str()));
		item->SubItems->Add(city.x.ToString());
		item->SubItems->Add(city.y.ToString());
		listView1->Items->Add(item);
	}
	Build_Matrix_Euclide();
	
}

void Dynamic_Programming::Load_StartPoint_CBB()
{
	StartCity->Items->Clear();
	for (const City& city : cities)
	{
		String^ cityName = gcnew String(city.name.c_str());
		StartCity->Items->Add(cityName);
	}
}

// tạo ma trận trọng số từ khoảng cách Euclide giữa các thành phố 
void Dynamic_Programming::Build_Matrix_Euclide()
{
	int n = listView1->Items->Count;
	if (n == 0) return;

	// ====== CẤP PHÁT MA TRẬN KHOẢNG CÁCH ======
	dist.assign(n, std::vector<double>(n, 0));

	listView2->Clear();
	listView2->Columns->Add(" ", 50);

	// ====== TẠO TIÊU ĐỀ CỘT ======
	for (int j = 0; j < n; j++)
	{
		String^ name = listView1->Items[j]->SubItems[0]->Text;
		listView2->Columns->Add(name, 80);
	}

	// ====== TÍNH TOÁN MA TRẬN KHOẢNG CÁCH ======
	for (int i = 0; i < n; i++)
	{
		String^ row_name = listView1->Items[i]->SubItems[0]->Text;
		double x_i = Convert::ToDouble(listView1->Items[i]->SubItems[1]->Text);
		double y_i = Convert::ToDouble(listView1->Items[i]->SubItems[2]->Text);

		ListViewItem^ item = gcnew ListViewItem(row_name);

		for (int j = 0; j < n; j++)
		{
			double x_j = Convert::ToDouble(listView1->Items[j]->SubItems[1]->Text);
			double y_j = Convert::ToDouble(listView1->Items[j]->SubItems[2]->Text);

			double dx = x_i - x_j;
			double dy = y_i - y_j;
			double d = Math::Sqrt(dx * dx + dy * dy);

			// LƯU VÀO MA TRẬN dist (DÙNG CHO TSP)
			dist[i][j] = d;

			// HIỂN THỊ LÊN LISTVIEW (Làm tròn 2 chữ số)
			item->SubItems->Add(d.ToString("F2"));
		}

		listView2->Items->Add(item);
	}

}

// ================================================== TSP ========================================

// TOP-DOWN với memoization
double Dynamic_Programming::TSP_TopDown(int u, int mask, int start)
{
	std::string setS = maskToString(mask);
	std::string cityU = cities[u].name;

	recursionLog->Append(
		gcnew String(("Goi dp(" + setS + "," + cityU + ")\r\n").c_str())
	);

	auto key = std::make_pair(u, mask);

	if (dp.count(key))
	{
		recursionLog->Append(
			"  -->lay tu  memo = " + dp[key].ToString("F2") + "\r\n"
		);
		return dp[key];
	}

	int FULL = (1 << cities.size()) - 1;

	if (mask == FULL)
	{
		double cost = dist[u][start];
		dp[key] = cost;

		recursionLog->Append(
			gcnew String(("  --> Base: quay ve " + cities[start].name +
				", cost = " + std::to_string(cost) + "\r\n").c_str())
		);

		return cost;
	}

	double best = 1e18;
	int bestV = -1;

	for (int v = 0; v < cities.size(); v++)
	{
		if (!(mask & (1 << v)))
		{
			double cost = dist[u][v] +
				TSP_TopDown(v, mask | (1 << v), start);

			recursionLog->Append(
				gcnew String(("   Thu di --> " + cities[v].name +
					": cost = " + std::to_string(cost) + "\r\n").c_str())
			);

			if (cost < best)
			{
				best = cost;
				bestV = v;
			}
		}
	}

	dp[key] = best;
	parent[key] = bestV;

	recursionLog->Append(
		"  -->Chon " + gcnew String(cities[bestV].name.c_str()) +
		", Tong = " + best.ToString("F2") + "\r\n\r\n"
	);

	return best;
}

void Dynamic_Programming::Run_TSP_TopDown()
{
	int n = cities.size();
	if (n < 2) return;

	recursionLog->Clear();
	dp.clear();
	parent.clear();

	int start = StartCity->SelectedIndex;
	int mask = (1 << start);   // chỉ chọn điểm start

	double bestCost = TSP_TopDown(start, mask, start);

	// ===== TRUY VẾT =====
	std::vector<int> path;
	int u = start;
	int curMask = mask;

	while (true)
	{
		path.push_back(u);
		auto key = std::make_pair(u, curMask);

		if (!parent.count(key)) break;

		int v = parent[key];
		curMask |= (1 << v);
		u = v;

		if (v == start) break;
	}

	// quay về điểm đầu
	if (path.back() != start)
		path.push_back(start);

	// ================= HIỂN THỊ LOG =================
	textBoxTour->Text = recursionLog->ToString();

	// ================= HIỂN THỊ BẢNG MEMO ===============
	listViewMemo->Items->Clear();

	for (auto& it : dp)
	{
		int u = it.first.first;
		int mask = it.first.second;
		double val = it.second;

		// tạo chuỗi hành trình: {a,b,c} , a
		String^ route = gcnew String(maskToString(mask).c_str());
		route += " , ";
		route += gcnew String(cities[u].name.c_str());

		// thêm vào listview: cột 0 = hành trình
		ListViewItem^ item = gcnew ListViewItem(route);

		// cột 1 = chi phí
		item->SubItems->Add(val.ToString("F2"));

		listViewMemo->Items->Add(item);
	}


	// ================= HIỂN THỊ KẾT QUẢ ==================
	String^ result = "Chu trinh toi uu:\r\n";

	for (int i = 0; i < path.size(); i++)
	{
		result += gcnew String(cities[path[i]].name.c_str());
		if (i + 1 < path.size()) result += " --> ";
	}

	result += "\r\n\r\nTong chi phi = " + bestCost.ToString("F2");

	MessageBox::Show(result, "Ket qua TSP Top-Down");
	textBoxResult->Text = result;
	textBoxCost->Text = "chi phi toi uu :\n" + bestCost.ToString("F2");
	// vẽ đường đi tối ưu trên bản đồ
	DrawOptimalRoute(path);
}

// Hiển thị 
std::string Dynamic_Programming::maskToString(int mask)
{
	std::string s = "{";
	for (int i = 0; i < cities.size(); i++)
		if (mask & (1 << i))
			s += cities[i].name + ",";

	if (s.size() > 1) s.pop_back();
	s += "}";
	return s;
}

// ve duong toi uu
void Dynamic_Programming::DrawOptimalRoute(const std::vector<int>& path)
{
	if (WebView_Map_Tab1->CoreWebView2 == nullptr) return;

	System::Text::StringBuilder^ js = gcnew System::Text::StringBuilder("drawOptimalPath([");

	for (int i = 0; i < path.size(); i++)
	{
		int idx = path[i];
		auto& c = cities[idx];

		js->AppendFormat(
			System::Globalization::CultureInfo::InvariantCulture,
			"{{lat:{0}, lng:{1}}}",
			c.lat,   // 
			c.lng    // 
		);

		if (i + 1 < path.size()) js->Append(",");
	}

	js->Append("]);");

	WebView_Map_Tab1->CoreWebView2->ExecuteScriptAsync(js->ToString());
}

// BOTTOM-UP với bảng dp (Held-Karp Algorithm)

// chuyển mã bit thành danh sách tên thành phố
std::string Dynamic_Programming::MaskToNameList(int mask)
{
	std::string s = "{";

	for (int i = 0; i < (int)cities.size(); i++)
	{
		if (mask & (1 << i))
		{
			s += cities[i].name; 
			s += ",";
		}
	}
	s += "}";
	return s;
}

// trang thai
void Dynamic_Programming::LogState(int i, int mask, double curCost)
{
	bottomUpLog += "--------------------------------------------------\r\n";
	bottomUpLog += "Tap S = " + MaskToNameList(mask) + "\r\n";
	bottomUpLog += "Diem cuoi (End): " + cities[i].name + "\r\n";

	char buff[128];
	sprintf_s(buff, "dp[%s][S] = %.4f\r\n\n",
		cities[i].name.c_str(),
		curCost);

	bottomUpLog += buff;
}


// thuat toan TSP Bottom-Up (Held-Karp)
void Dynamic_Programming::TSP_BottomUp_HeldKarp()
{
	int n = (int)cities.size();
	if (n < 2)
	{
		bestCost_BottomUp = 0;
		path_BottomUp.clear();
		bottomUpLog.clear();
		return;
	}

	int start = StartCity->SelectedIndex;

	bottomUpLog.clear();
	parent.clear();

	// nếu có ListView lưu hành trình thì clear luôn
	// giả sử tên là listViewHanhTrinh_BottomUp
	listViewBottomUp->Items->Clear();

	int FULL = 1 << n;

	// ====== KHỞI TẠO BẢNG DP ======
	dpBottomUp.assign(n, std::vector<double>(FULL, 1e18));
	dpBottomUp[start][1 << start] = 0.0;

	// ====== HELD–KARP BOTTOM-UP ======
	for (int mask = 0; mask < FULL; mask++)
	{
		for (int i = 0; i < n; i++)
		{
			if (!(mask & (1 << i))) continue;          // i không thuộc S

			double curCost = dpBottomUp[i][mask];
			if (curCost >= 1e18) continue;             // trạng thái chưa được set

			// log trạng thái hiện tại
			LogState(i, mask, curCost);

			// thử đi đến các đỉnh j
			for (int j = 0; j < n; j++)
			{
				if (mask & (1 << j)) continue;         // j đã ở trong S

				int nextMask = mask | (1 << j);
				double newCost = curCost + dist[i][j];

				// log chi tiết quá trình mở rộng
				char buff[256];
				sprintf_s(buff,
					"    Mo rong: %s --> %s\r\n"
					"        dp[%s][%s] + dist(%s,%s)\r\n"
					"        = %.4f + %.4f = %.4f\r\n",
					cities[i].name.c_str(),
					cities[j].name.c_str(),
					cities[i].name.c_str(),
					MaskToNameList(mask).c_str(),
					cities[i].name.c_str(),
					cities[j].name.c_str(),
					curCost,
					dist[i][j],
					newCost
				);
				bottomUpLog += buff;

				// ===== CẬP NHẬT DP + PARENT + LISTVIEW =====
				if (newCost < dpBottomUp[j][nextMask])
				{
					dpBottomUp[j][nextMask] = newCost;
					parent[std::make_pair(j, nextMask)] = i;

					bottomUpLog += "         Cap nhat dp["
						+ MaskToNameList(nextMask) + "]["
						+ cities[j].name
						+ "] = ";

					char buff2[64];
					sprintf_s(buff2, "%.4f\r\n\n", newCost);
					bottomUpLog += buff2;

					// lưu vào ListView hành trình
					ListViewItem^ row = gcnew ListViewItem(
						gcnew String(MaskToNameList(nextMask).c_str())
					);
					row->SubItems->Add(newCost.ToString("F4"));
					listViewBottomUp->Items->Add(row);
				}
				else
				{
					bottomUpLog += "\r\n";
				}
			}
		}
	}

	// ====== TÌM CHI PHÍ TỐI ƯU ======
	int finalMask = FULL - 1;
	double best = 1e18;
	int last = -1;

	for (int i = 0; i < n; i++)
	{
		if (i == start) continue;
		double cost = dpBottomUp[i][finalMask] + dist[i][start];
		if (cost < best)
		{
			best = cost;
			last = i;
		}
	}
	bestCost_BottomUp = best;

	// ====== TRUY VẾT ĐƯỜNG ĐI ======
	path_BottomUp.clear();

	int mask = finalMask;
	int u = last;

	// bắt đầu bằng đỉnh xuất phát
	path_BottomUp.push_back(start);

	// lần lượt truy vết ngược lại
	while (u != start)
	{
		path_BottomUp.push_back(u);
		int prev = parent[std::make_pair(u, mask)];
		mask ^= (1 << u);
		u = prev;
	}

	// thêm lại điểm xuất phát ở cuối để tạo chu trình
	path_BottomUp.push_back(start);
}

// chay thuat toan
double Dynamic_Programming::Run_TSP_BottomUp()
{
	TSP_BottomUp_HeldKarp();

	// Log chi tiết lên textbox
	textTour_BottomUp->Text = gcnew String(bottomUpLog.c_str());

	// Hiển thị hành trình tối ưu (chu trình + chi phí)
	// textbox tối ưu : textBoxBU_result, textBoxBU_Cost
	String^ route = "";

	for (int i = 0; i < (int)path_BottomUp.size(); i++)
	{
		int u = path_BottomUp[i];
		route += gcnew String(cities[u].name.c_str());

		if (i + 1 < (int)path_BottomUp.size())
			route += " --> ";
	}
	textBoxBU_result->Text = route;
	textBoxBU_Cost->Text = bestCost_BottomUp.ToString("F2");

	// vẽ đường đi tối ưu (đường xanh) – DrawOptimalRoute sử dụng path_BottomUp
	DrawOptimalRoute(path_BottomUp);
	return bestCost_BottomUp;
}

//===================================================================================== khoảng cách thực tế =========================================================================
void Dynamic_Programming::Hook_MarkerFromMap_Real(Object^ sender,
	CoreWebView2InitializationCompletedEventArgs^ e)
{
	WebView_Map_Tab2->CoreWebView2->WebMessageReceived +=
		gcnew EventHandler<CoreWebView2WebMessageReceivedEventArgs^>(
			this, &Dynamic_Programming::InputCities_Real);
}
void Dynamic_Programming::InputCities_Real(
	Object^ s,
	CoreWebView2WebMessageReceivedEventArgs^ e)
{
	String^ msg = e->TryGetWebMessageAsString();
	array<String^>^ parts = msg->Split('|');

	if (parts->Length == 0) return;

	msclr::interop::marshal_context ctx;

	// ============================
	// THÊM ĐIỂM REAL
	// ============================
	if (parts[0]->Equals("REALPOINT"))
	{
		if (parts->Length < 4)
		{
			MessageBox::Show("Chuỗi lỗi: " + msg);
			return;
		}

		City c;

		c.name = ctx.marshal_as<std::string>(parts[1]);
		c.lat = Double::Parse(parts[2],
			System::Globalization::CultureInfo::InvariantCulture);
		c.lng = Double::Parse(parts[3],
			System::Globalization::CultureInfo::InvariantCulture);

		c.x = 0;
		c.y = 0;

		cities_real.push_back(c);

		// ========== cập nhật combobox ==========
		cbbSelectCity->Items->Clear();
		for (auto& ct : cities_real)
			cbbSelectCity->Items->Add(gcnew String(ct.name.c_str()));

		if (cbbSelectCity->Items->Count > 0)
			cbbSelectCity->SelectedIndex = 0;

		// ========== cập nhật listview ma trận ==========
		UpdateListViewRealMatrix();

		return;
	}
	if (parts[0]->Equals("DELETE"))
	{
		if (parts->Length < 2) return;

		std::string name = ctx.marshal_as<std::string>(parts[1]);

		// Xóa bên C++
		RemoveCity_ByName(name);

		// Cập nhật combobox
		cbbSelectCity->Items->Clear();
		for (auto& ct : cities_real)
			cbbSelectCity->Items->Add(gcnew String(ct.name.c_str()));

		// Nếu vẫn còn điểm → chọn phần tử đầu
		if (cbbSelectCity->Items->Count > 0)
			cbbSelectCity->SelectedIndex = 0;

		// Cập nhật ma trận và listView
		UpdateListViewRealMatrix();

		return;
	}
	// ============================
	// NHẬN KHOẢNG CÁCH THỰC TẾ
	// ============================
	if (parts[0]->Equals("WEIGHT"))
	{
		if (parts->Length < 4) return;

		std::string from = ctx.marshal_as<std::string>(parts[1]);
		std::string to = ctx.marshal_as<std::string>(parts[2]);

		double w = Double::Parse(parts[3],
			System::Globalization::CultureInfo::InvariantCulture);

		UpdateRealMatrix(from, to, w);
		UpdateListViewRealMatrix();
		return;
	}
}
void Dynamic_Programming::RemoveCity_ByName(const std::string& name)
{
	for (auto it = cities_real.begin(); it != cities_real.end(); ++it)
	{
		if (it->name == name)
		{
			cities_real.erase(it);
			break;
		}
	}
}
void Dynamic_Programming::UpdateListViewRealMatrix()
{
	// đảm bảo chế độ hiển thị dạng bảng
	lstMatrix_RealCost->View = View::Details;
	lstMatrix_RealCost->FullRowSelect = true;
	lstMatrix_RealCost->GridLines = true;

	lstMatrix_RealCost->Items->Clear();
	lstMatrix_RealCost->Columns->Clear();

	int n = cities_real.size();
	if (n == 0) return;

	lstMatrix_RealCost->Columns->Add(" ", 50);
	for (int i = 0; i < n; i++)
		lstMatrix_RealCost->Columns->Add(
			gcnew String(cities_real[i].name.c_str()), 80);

	for (int i = 0; i < n; i++)
	{
		ListViewItem^ row =
			gcnew ListViewItem(gcnew String(cities_real[i].name.c_str()));

		for (int j = 0; j < n; j++)
		{
			double d = 0;
			if (i < dist_real.size() && j < dist_real[i].size())
				d = dist_real[i][j];

			row->SubItems->Add(d == 0 ? "-" : d.ToString("F2"));
		}

		lstMatrix_RealCost->Items->Add(row);
	}
}



int Dynamic_Programming::FindCityIndex(const std::string& name)
{
	for (int i = 0; i < cities_real.size(); i++)
		if (cities_real[i].name == name)
			return i;
	return -1;
}
void Dynamic_Programming::UpdateRealMatrix(
	const std::string& from,
	const std::string& to,
	double w)
{
	int n = cities_real.size();
	if (dist_real.size() != n)
		dist_real.assign(n, std::vector<double>(n, 0));

	int i = FindCityIndex(from);
	int j = FindCityIndex(to);

	if (i == -1 || j == -1) return;

	dist_real[i][j] = w;
	dist_real[j][i] = w;
}


void Dynamic_Programming::Run_TSP_Real_BottomUp()
{
	int n = cities_real.size();
	if (n < 2) return;

	int start = cbbSelectCity->SelectedIndex;
	int FULL = 1 << n;

	dp_real.assign(n, std::vector<double>(FULL, 1e18));
	parent_real.assign(n, std::vector<int>(FULL, -1));

	dp_real[start][1 << start] = 0;

	// Xóa log
	txtReal_DetailTour->Clear();
	lstReal_SaveTour->Items->Clear();

	// ===================== DP =======================
	for (int mask = 0; mask < FULL; mask++)
	{
		for (int u = 0; u < n; u++)
		{
			if (!(mask & (1 << u))) continue;

			double curCost = dp_real[u][mask];
			if (curCost >= 1e18) continue;

			for (int v = 0; v < n; v++)
			{
				if (mask & (1 << v)) continue;

				int newMask = mask | (1 << v);
				double newCost = curCost + dist_real[u][v];

				if (newCost < dp_real[v][newMask])
				{
					dp_real[v][newMask] = newCost;
					parent_real[v][newMask] = u;

					// ======= Lưu vào ListView Save =========
					std::string setStr = ConvertMaskToString(newMask);
					ListViewItem^ item = gcnew ListViewItem(
						gcnew String(setStr.c_str()));   // cột "Hanh trinh"

					item->SubItems->Add(newCost.ToString("F4"));  // cột "Chi phi"

					lstReal_SaveTour->Items->Add(item);

					// ======= Lưu log chi tiết (txtReal_DetailTour) =======
					txtReal_DetailTour->AppendText(
						"Mo Rong S=" +
						gcnew String(ConvertMaskToString(mask).c_str()) +
						", Den  " +
						gcnew String(cities_real[v].name.c_str()) +
						", cost = " + newCost.ToString("F4") + "\r\n");
				}
			}
		}
	}

	// ================== CHỌN LAST NODE ===================
	double best = 1e18;
	int last = -1;

	for (int i = 0; i < n; i++)
	{
		if (i == start) continue;

		double cost = dp_real[i][FULL - 1] + dist_real[i][start];
		if (cost < best)
		{
			best = cost;
			last = i;
		}
	}

	// ================== TRUY VẾT ========================
	std::vector<int> path;
	int mask = FULL - 1;

	while (last != -1)
	{
		path.push_back(last);
		int prev = parent_real[last][mask];
		mask ^= (1 << last);
		last = prev;
	}

	// path hiện đang là [last, ..., start]
	// đảo lại cho đúng thứ tự: start -> ... -> last
	std::reverse(path.begin(), path.end());

	// thêm bước quay về điểm xuất phát nếu chưa có
	if (path.back() != start)
		path.push_back(start);

	// ================== IN KẾT QUẢ ======================
	Print_Real_Final_Result(path, best);

	// ================== VẼ TRÊN MAP =====================

	SendOptimalForReal(path);
}
void Dynamic_Programming::Print_Real_Final_Result(
	const std::vector<int>& path, double cost)
{
	textBox_FinalResult->Clear();
	textBox_FinalCost->Clear();

	// Chu trình tối ưu
	for (int i = 0; i < path.size(); i++)
	{
		textBox_FinalResult->AppendText(
			gcnew String(cities_real[path[i]].name.c_str()));

		if (i < path.size() - 1)
			textBox_FinalResult->AppendText(" --> ");
	}

	// Chi phí
	textBox_FinalCost->Text = cost.ToString("F4");
}

void Dynamic_Programming::Show_Real_Path_Info(
	const std::vector<int>& path, double totalCost)
{
	textBox_FinalResult->Clear();

	for (int i = 0; i < path.size(); i++)
	{
		textBox_FinalResult->AppendText(
			gcnew String(cities_real[path[i]].name.c_str())
		);

		if (i < path.size() - 1)
			textBox_FinalResult->AppendText(" --> ");
	}

	textBox_FinalCost->Text = totalCost.ToString("F4");
}

void Dynamic_Programming::SendPathToJS(const std::vector<int>& path)
{
	System::Text::StringBuilder^ js =
		gcnew System::Text::StringBuilder("drawOptimalFromCpp([");

	for (int i = 0; i < path.size(); i++)
	{
		auto& c = cities_real[path[i]];
		js->AppendFormat(
			System::Globalization::CultureInfo::InvariantCulture,
			"{{lat:{0},lng:{1}}}",
			c.lat, c.lng);

		if (i < path.size() - 1)
			js->Append(",");
	}

	js->Append("])");
	WebView_Map_Tab2->ExecuteScriptAsync(js->ToString());
}



std::string Dynamic_Programming::ConvertMaskToString(int mask)
{
	std::string s = "{";

	for (int i = 0; i < cities_real.size(); i++)
	{
		if (mask & (1 << i))
		{
			s += cities_real[i].name + ",";
		}
	}
	if (s.back() == ',') s.pop_back();
	s += "}";
	return s;
}

// ham ve duong di toi uu tren ban do
void Dynamic_Programming::SendOptimalForReal(const std::vector<int>& path)
{
	System::Text::StringBuilder^ js =
		gcnew System::Text::StringBuilder("drawOptimalLoopFromCpp([");

	for (int i = 0; i < path.size(); i++)
	{
		auto& c = cities_real[path[i]];
		js->AppendFormat(
			System::Globalization::CultureInfo::InvariantCulture,
			"{{lat:{0},lng:{1}}}",
			c.lat, c.lng);

		if (i < path.size() - 1)
			js->Append(",");
	}

	js->Append("])");

	WebView_Map_Tab2->ExecuteScriptAsync(js->ToString());
}
// load file


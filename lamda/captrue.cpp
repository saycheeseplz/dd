/*Cách viết	Ý nghĩa	Ghi chú	Ví dụ
[&]	Bắt tất cả biến bên ngoài theo tham chiếu	Có thể thay đổi giá trị của biến gốc bên ngoài	✅
[=]	Bắt tất cả biến bên ngoài theo giá trị (copy)	Không sửa được biến gốc (mặc định là const copy)	✅
[&x]	Chỉ bắt biến x theo tham chiếu	Biến khác không dùng được	✅
[x]	Chỉ bắt biến x theo copy	Biến khác không dùng được	✅
[=, &y]	Bắt toàn bộ bằng copy, riêng y bằng tham chiếu	Linh hoạt khi cần sửa 1 biến	✅
[&x, y]	Bắt x bằng tham chiếu, y bằng copy	Ngược lại với trên
Capture	Sửa được biến gốc?	Có dùng được biến ngoài?
[&]	✅ Có	✅ Có
[=]	❌ Không (copy)	✅ Có (đọc được)
[&x]	✅ x thôi	❌ chỉ x
[x]	❌ x thôi	❌ chỉ x
[=, &y]	✅ y thôi	✅ x (copy), ✅ y (ref)
[&x, y]	✅ x, ❌ y	✅ x (ref), ✅ y (copy)
*/
/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graps(numCourses);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graps[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    vector<int> visited(numCourses, 0);
    function<bool(int)> dfs = [&](int node)
    {
        if (visited[node] == 1)
        {
            return false;
        }
        if (visited[node] == 2)
        {
            return true;
        }
        visited[node] = 1;
        for (auto neighbor : graps[node])
        {
            if (dfs(neighbor))
            {
                return true;
            }
        }
        visited[node] = 2;
        return false;
    };
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i] && dfs(i))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> prerequisites = {
        {1, 0},
        {0, 1}};
    cout << canFinish(2, prerequisites);
    return 0;
}
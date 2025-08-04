#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> w;
    vector<int> v;
    w.push_back(0);
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int weight;
        int value;
        cin >> weight >> value;
        w.push_back(weight);
        v.push_back(value);
    }

    int col;
    cin >> col;
    int a[100][100] = {0};
    for (int i = 1; i < w.size(); i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (j >= w[i])
            {
                a[i][j] = max(a[i - 1][j], a[i - 1][j - w[i]] + v[i]);
            }
            else
                a[i][j] = a[i - 1][j];
        }
    }

    cout << a[w.size() - 1][col];
    return 0;
}
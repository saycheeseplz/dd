#include <iostream>
#include <limits>
#include <cstring>
using namespace std;
#define ll long long
ll a[100][100] = {0};
ll n;
int x[100];
int idx[100];
ll cmin = INT_MAX;
ll value_path = INT_MAX;
void print()
{
    for (int i = 1; i < n; i++)
    {
        cout << a[idx[i]][idx[i + 1]] << " ";
    }
    cout << endl;
}
void path(int start, int value)
{
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 0)
        {
            x[i] = 1;
            idx[start] = i;
            ll next_value = value + a[idx[start - 1]][i];
            if (start == n)
            {
                next_value += a[idx[start]][idx[1]];
                cout << "begin" << endl;
                cout << next_value << endl;
                if (next_value < value_path)
                {
                    value_path = next_value;
                }
                print();
                cout << "------------------" << endl;
            }
            else if (next_value + (n + 1 - start) * cmin < value_path)
            {

                path(start + 1, next_value);
            }
            x[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] < cmin && i != j)
            {
                cmin = a[i][j];
            }
        }
    }
    memset(x, 0, sizeof(x));
    x[1] = 1;
    idx[1] = 1;
    path(2, 0);
    cout << value_path;
    return 0;
}
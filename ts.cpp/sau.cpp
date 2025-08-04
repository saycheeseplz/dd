#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int sum;
    cin >> sum;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int b[n + 1][sum + 1];
    for (int i = 1; i <= sum; i++)
    {
        b[0][i] = 0;
    }
    b[0][0] = 1;
    for (int j = 1; j <= n; j++)
    {
        for (int i = sum; i >= 0; i--)
        {
            if (i >= a[j])
            {
                if (b[j - 1][i - a[j]])
                {
                    b[j][i] = 1;
                }
                else
                {
                    b[j][i] = b[j - 1][i];
                }
            }
            else
            {
                b[j][i] = b[j - 1][i];
            }
        }
    }
    cout << b[n][sum];
    return 0;
}
// #include <iostream>
// #include <cmath>
// using namespace std;
// int a[8][8] = {0};
// int n;
// void sett(int x, int y)
// {
//     for (int i = 1; i <= 8; ++i)
//     {
//         a[x][i] = 1;
//         a[i][y] = 1;
//     }
//     for (int i = 1; i <= 8; ++i)
//         for (int j = 1; j <= 8; ++j)
//             if (abs(x - i) == abs(y - j))
//                 a[i][j] = 1;
// }
// void pathqueen(int k)
// {
//     if (k == 0)
//     {
//         cout << "Yes";
//         cout << endl;
//         return;
//     }
//     for (int i = 1; i <= 8; i++)
//     {
//         for (int j = 1; j <= 8; j++)
//         {
//             if (a[i][j] == 0)
//             {
//                 sett(i, j);
//                 pathqueen(k - 1);
//                 return;
//             }
//         }
//     }
//     cout << "NO";
//     return;
// }
// int main()
// {
//     cin >> n;
//     pathqueen(n);
//     for (int i = 1; i <= 8; i++)
//     {
//         for (int j = 1; j <= 8; j++)
//         {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
int n;
int a[100];
int col[100];
int d1[100];
int d2[100];
void print(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        for (int j = 1; j < x; j++)
        {
            cout << 0 << " ";
        }
        cout << 1 << " ";
        for (int j = x + 1; j <= n; j++)
        {
            cout << 0 << " ";
        }
        cout << endl;
    }
}
void pathqueen(int k)
{
    for (int i = 1; i <= n; i++)
    {

        if (col[i] == 1 && d1[k - i + n] == 1 && d2[i + k - 1] == 1)
        {
            a[k] = i;
            if (k == n)
            {
                print(a, n);
                cout << endl;
            }
            else
            {
                col[i] = d1[k - i + n] = d2[k + i - 1] = 0;

                pathqueen(k + 1);
                col[i] = d1[k - i + n] = d2[k + i - 1] = 1;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= 100; i++)
    {
        col[i] = d1[i] = d2[i] = 1;
    }
    pathqueen(1);
    return 0;
}
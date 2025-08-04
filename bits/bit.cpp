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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    uint64_t a = 8;
    bitset<64> A(a);
    cout << A << endl;
    cout << a;
    uint64_t b = 10;
    cout << (a & b);
    // ^ toán tử xor
    cout << (a ^ b);
    // ~ toán tử not
    cout << (a << 1) << endl;
    cout << (a >> 1) << endl;
    // >> dịch phải  chia 2
    // dịch trái chia 2
    // b&1 kiểm tra phải số lẽ ko
    for (int i = 31; i >= 0; i--)
    {
        if (a & (1 << i))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    int temp[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < (1 << 4); i++)
    {
        cout << "{ ";
        for (int j = 0; j < 5; j++)
        {
            if (i & (1 << j))
            {
                cout << temp[j] << " ";
            }
        }
        cout << "}" << endl;
    }
    return 0;
}
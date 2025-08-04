#include <iostream>
using namespace std;
int main()
{
    string s, s1;
    cin >> s >> s1;
    int a[s.size() + 1][s1.size() + 1];
    for (int i = 0; i <= s.size(); i++)
    {
        a[i][0] = 0;
    }
    for (int i = 0; i <= s1.size(); i++)
    {
        a[0][i] = 0;
    }

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= s1.size(); j++)
        {
            if (s1[j - 1] == s[i - 1])
            {
                a[i][j] = 1 + a[i - 1][j - 1];
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    int max = 0;
    int idx = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= s1.size(); j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                idx = j;
            }
        }
    }
    for (int i = idx - max; i <= idx - 1; i++)
    {
        cout << s1[i];
    }
    return 0;
}
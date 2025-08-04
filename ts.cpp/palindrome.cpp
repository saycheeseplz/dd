// // #include <iostream>
// // #include <string>
// // using namespace std;
// // int main()
// // {
// //     string s;
// //     cin >> s;
// //     string newword;
// //     for (int i = 0; i < s.size() - 1; i++)
// //     {
// //         newword += "#";
// //         newword += s[i];
// //     }
// //     newword += "#";
// //     int start = 0;
// //     int maxx = 1;
// //     for (int i = 1; i <= newword.size() - 1; i++)
// //     {
// //         int j = 1;
// //         int count = 1;
// //         while (i - j >= 0 && j + i < newword.size() && newword[i - j] == newword[j + i])
// //         {
// //             count += 2;
// //             j++;
// //         }
// //         if (count > maxx)
// //         {
// //             maxx = count;
// //             start = i;
// //         }
// //     }
// //     int begin = start - maxx / 2;
// //     int end = start + maxx / 2;
// //     for (int i = begin; i <= end; i++)
// //     {
// //         if (newword[i] != '#')
// //         {
// //             cout << newword[i];
// //         }
// //     }
// //     return 0;
// // }
// #include <iostream>
// #include <string>
// #include <cmath>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     string newword;
//     for (int i = 0; i < s.size(); i++)
//     {
//         newword += "#";
//         newword += s[i];
//     }
//     newword += "#";
//     int center = 0;
//     int length = 0;
//     int c = 0;
//     int r = 0;
//     int p[newword.size() - 1] = {0};
//     for (int i = 1; i < newword.size() - 1; i++)
//     {
//         int j = 0;
//         int mirror = 2 * c - 1;
//         if (i < r)
//         {
//             p[i] = min(p[mirror], r - i);
//             j = r - i;
//         }
//         j++;
//         while (i + j < newword.size() - 1 && i - j >= 0 && newword[i + j] == newword[i - j])
//         {
//             p[i]++;
//             j++;
//         }
//         if (p[i] + j - 1 > r)
//         {
//             r = p[i] + j - 1;
//             c = i;
//         }
//         if (p[i] > length)
//         {
//             length = p[i];
//             center = i;
//         }
//     }
//     int start = (center - length) / 2;
//     cout << s.substr(start, length);
//     return 0;
// }
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a[s.size() + 1][s.size() + 1];
    for (int j = 1; j <= s.size(); j++)
    {
        for (int i = 1; i <= s.size(); i++)
        {
            if (i > j)
                break;

            if (i - j == 0)
            {
                a[i][j] == 1;
            }
            if (j - i == 1)
            {
                if (s[i - 1] == s[j - 1])
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = 0;
                }
            }
            else
            {
                if (a[i + 1][j - 1])
                {
                    if (s[j - 1] == s[i - 1])
                    {
                        a[i][j] = 1;
                    }
                    else
                    {
                        a[i][j] = 0;
                    }
                }
                else
                {
                    a[i][j] = 0;
                }
            }
        }
    }
    int maxx = 0;
    int idx = 0;
    for (int j = 1; j <= s.size(); j++)
    {
        for (int i = 1; i <= s.size(); i++)
        {
            if (i > j)
            {
                break;
            }
            if (a[i][j])
            {
                if (j - i > maxx)
                {
                    maxx = j - i;
                    idx = i;
                }
            }
        }
    }
    for (int i = idx - 1; i <= idx - 1 + maxx; i++)
    {
        cout << s[i];
    }
    return 0;
}

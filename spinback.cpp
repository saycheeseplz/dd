#include <iostream>
using namespace std;
int a[100];
void print(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << " ";
    return;
}
void test(int n, int k, int idx, int l)
{

    for (int i = l; i <= n; i++)
    {
        a[idx] = i;

        if (idx == k)
        {
            print(a, k);
        }
        else
        {
            test(n, k, idx + 1, i + 1);
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    test(n, k, 1, 1);
    return 0;
}
#include <iostream>
using namespace std;
int n;
int a[100] = {0};
void print(int a[], int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << a[i];
    }
    cout << " ";
}
void test(int k, int t)
{
    for (int i = a[t - 1] + 1; i <= n; i++)
    {
        a[t] = i;
        if (t == k)
        {
            print(a, k);
        }
        else
        {
            test(k, t + 1);
        }
    }
}
int main()
{
    cin >> n;
    int k;
    cin >> k;
    test(k, 1);
    return 0;
}
#include <iostream>
using namespace std;
int a[1000];
int b[1000];
void test(int n, int idx)
{
    for (int i = 1; i <= n; i++)
    {
        if (b[i])
        {
            a[idx] = i;
            if (idx == n)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << a[i];
                }
                cout << " ";
            }
            else
            {
                b[i] = false;
                test(n, idx + 1);
                b[i] = true;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        b[i] = 1;
    }
    test(n, 1);
    return 0;
}
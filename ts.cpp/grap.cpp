#include <iostream>
using namespace std;
int a[1000];
int t[1000 * 4];
int sumt = 0;
void grap(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = a[l];
    }
    else
    {
        int m = (l + r) / 2;
        grap(v * 2, l, m);
        grap(v * 2 + 1, m + 1, r);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}
void update(int v, int l, int r, int pos, int value)
{
    if (l == r)
    {
        t[v] = value;
    }
    else
    {
        int m = (l + r) / 2;
        if (pos <= m)
        {
            update(2 * v, l, m, pos, value);
        }
        else
            update(2 * v + 1, m + 1, r, pos, value);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}
int query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return INT_MAX;
    }
    else if (l == tl && r == tr)
    {
        return t[v];
    }
    else
    {
        int mid = (tl + tr) / 2;
        int s1 = query(2 * v, tl, mid, l, min(r, mid));
        int s2 = query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
        return min(s1, s2);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    grap(1, 0, n - 1);
    update(1, 0, n - 1, 4, 10);
    cout << "sum" << query(1, 0, n - 1, 2, 7) << endl;

    for (int i = 1; i <= 15; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}
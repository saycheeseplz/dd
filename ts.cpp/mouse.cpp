#include <iostream>
using namespace std;

char a[100][100];
int n;
bool found = false;

void print(char a[][100], int n)
{
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
}

void backtrack(int x, int y, int x1, int y1)
{
    if (found)
        return; // Đã tìm thấy thì không làm gì nữa

    if (x == x1 && y == y1)
    {
        print(a, n);
        found = true;
        return;
    }

    char temp = a[x][y];
    a[x][y] = ' ';

    if (a[x][y + 1] == 'O')
        backtrack(x, y + 1, x1, y1);

    if (a[x + 1][y] == 'O')
        backtrack(x + 1, y, x1, y1);

    a[x][y] = temp;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
    {
        a[0][i] = 'X';
        a[i][0] = 'X';
        a[n + 1][i] = 'X';
        a[i][n + 1] = 'X';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;

    backtrack(x, y, x1, y1);

    if (!found)
        cout << "No path found.\n";

    return 0;
}

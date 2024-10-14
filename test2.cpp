#include <bits/stdc++.h>
using namespace std;
int n, m, x[101], a[101], b[101], c[101], s[101][101];
void in()
{
    memset(s, 0, sizeof(s));
    for (int i = 1; i < 9; i++)
    {
        s[i][x[i]] = 1;
    }
    if (s[n][m] == 1)
    {
        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (s[i][j] == 0)
                    cout << ".";
                else
                    cout << "w";
            }
            cout << '\n';
        }
        exit(0);
    }
}
void queen(int i)
{
    for (int j = 1; j <= 8; j++)
    {
        if (a[j] == 1 && b[i - j + 8] == 1 && c[i + j - 1] == 1)
        {
            x[i] = j;
            a[j] = b[i - j + 8] = c[j + i - 1] = 0;
            if (i == 8)
                in();
            else
                queen(i + 1);
            a[j] = b[i - j + 8] = c[j + i - 1] = 1;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i < 20; i++)
    {
        // cout << i << '\n';
        a[i] = 1;
        b[i] = 1;
        c[i] = 1;
    }
    queen(1);
}
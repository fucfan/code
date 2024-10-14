#include <bits/stdc++.h>
using namespace std;
long L, R, n, chot, a[1001];
void qs(int l, int r)
{
    int i = l, j = r, x;
    x = a[(i + j) / 2];
    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        qs(l, j);
    if (i < r)
        qs(i, r);
}
int main()
{
	freopen("phuc.inp", "r", stdin);
	freopen("phuc.out", "w", stdout);
	cin >> n;
	for (long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	qs(1 , n );
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
}
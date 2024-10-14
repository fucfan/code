#include <bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n, m, w[1000][1000], u, v, a[N], ans, c, p[5];
vector<pii> q;
void out()
{
    p[0] = 0;
    p[1] = 0;
    for (auto i : q)
    {
        if (a[i.fi] == a[i.se])
        {
            p[a[i.fi]] += w[i.fi][i.se];
        }
    }
    ans = min(ans, abs(p[0] - p[1]));
}
void sol(int i, int cnt)
{
    // cout << 1 ;
    if(n * 2 - i < n - cnt) return;
    if (cnt == n)
    {
    //     for (int i = 1; i <= n * 2; i++)
    //     {
    //         cout << a[i] << ' ';
    //     }
    //     nl;
        out();
    }
    if (i > n * 2)
        return;
    sol(i + 1, cnt);
    a[i] = 1;
    sol(i + 1, cnt + 1);
    a[i] = 0;
}
void inp()
{
    ans = 1000000;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> c;
        q.push_back({u, v});
        w[u][v] = c;
    }
}

void solve()
{
    sol(1, 0);
    cout << ans;
}

void run_with_file()
{
    if (fopen(file ".inp", "r"))
    {
        freopen(file ".inp", "r", stdin);
        freopen(file ".out", "w", stdout);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
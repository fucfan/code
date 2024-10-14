#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "rk"
#define sum(x, y) ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const ll mod = 111539786;
const int N = 5e3 + 5;
const int LOG = 20;

int n , a[N][N] , m;
ll dp[N][N] , row[N][N] , col[N][N];

void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int x , y;
		cin >> x >> y;
		a[x][y] = 1;
	}
}

void solve()
{
	dp[1][1] = 1;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(a[i][j]) continue;
			row[i][j] = sum(row[i - 1][j] , dp[i - 1][j]);
			col[i][j] = sum(col[i][j - 1] , dp[i][j - 1]);
			dp[i][j] = sum(dp[i][j] , sum(row[i][j] , col[i][j]));
		}
	}

	cout << dp[n][n];
}

main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    inp();
    solve();
    Times;
}
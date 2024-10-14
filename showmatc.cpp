#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define turn_on(x , i) ((x) | (1 << (i)))
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
#define file "showmatc"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e2 + 5;
const int LOG = 20;

int n , m , a[N][N] , dp[21][(1 << 20)];
vector <pii> chance[N];

int sol(int j , int mask){
	if(j < 1) return 0;

	if(dp[j][mask] != -1) return dp[j][mask];

	int res = 0;
	for(int i = 1 ; i <= n ; i++){
		if(BIT(mask , i - 1)) continue;
		int tmp = sol(j - 1 , turn_on(mask , i - 1)) + a[i][j];

		for(auto u : chance[j]){
			if(tmp >= u.fi) tmp += u.se;
		}

		res = max(res , tmp);
	}

	return dp[j][mask] = res;
}

void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int k , a , b;
		cin >> k >> a >> b;
		chance[k].pb({a , b});
		sort(all(chance[k]));
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++) cin >> a[i][j];
	}
}

void solve()
{
	mem(dp , -1);
	cout << sol(n , 0);
}

void run_with_file()
{
    if (fopen(file".inp", "r"))
    {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
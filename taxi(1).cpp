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
#define file "test"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 30 + 5;
const int LOG = 20;

int n , adj[N][N] , dp[N][(1 << 13)];

int sol(int i , int mask){
	if(mask == (1 << n) - 1) return adj[i][0];

	if(dp[i][mask] != -1) return dp[i][mask];

	int res = oo;

	for(int j = 1 ; j <= n ; j++){
		if(BIT(mask , j - 1)) continue;
		res = min(res , sol(j + n , mask ^ (1 << (j - 1))) + adj[i][j] + adj[j][j + n]);
	}

	return dp[i][mask] = res;
}

void inp()
{
	cin >> n;
	for(int i = 0 ; i <= 2 * n ; i++){
		for(int j = 0 ; j <= 2 * n ; j++){
			cin >> adj[i][j];
		}
	}
}

void solve()
{
	mem(dp , -1);
	cout << sol(0 , 0);
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
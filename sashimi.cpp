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
#define file "sashimi"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 4e3 + 5;
const int LOG = 20;

int n , opt[N][N];
ll w[N] , pref[N] , dp[N][N];

void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> w[i];
		pref[i] = pref[i - 1] + w[i];
		opt[i][i] = i;
	}
}

void solve()
{
	for(int len = 2 ; len <= n ; len++){
		for(int i = 1 ; i + len - 1 <= n ; i++){
			int j = i + len - 1;
			ll tmp = oo;

			for(int k = opt[i][j - 1] ; k <= min(j - 1 , opt[i + 1][j]) ; k++){
				if(tmp >= dp[i][k] + dp[k + 1][j] + pref[j] - pref[i - 1]){
					tmp = dp[i][k] + dp[k + 1][j] + pref[j] - pref[i - 1];
					opt[i][j] = k;
				}
			}

			dp[i][j] = tmp;
		}
	}

	cout << dp[1][n];
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
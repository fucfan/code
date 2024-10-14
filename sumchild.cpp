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
const int N = 1e6 + 5;
const int LOG = 20;

int n , a[N] , dp[N][LOG + 5];

void inp()
{
	mem(dp , 0);
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		dp[i][0] += a[i];
	}
}

void solve()
{
	for(int i = 1 ; i <= LOG ; i++){
		for(int mask = 0 ; mask < n ; mask++){
			dp[mask][i] = dp[mask][i - 1];
			if(BIT(mask , i - 1)) dp[mask][i] += dp[mask ^ (1 << (i - 1))][i - 1];
		}
	}

	for(int i = 0 ; i < n ; i++) cout << dp[i][LOG] << ' ';
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
    cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
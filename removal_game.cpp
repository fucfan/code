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
const int N = 5e3 + 5;
const int LOG = 20;

int n , a[N];
bool check[N][N];
pair <ll , ll> dp[N][N];

pair<ll , ll> sol(int l , int r , int turn){
	if(l > r){
		return {0 , 0};
	}

	if(check[l][r]) return dp[l][r];

	if(!turn){
		pair<ll , ll> tmp1 = sol(l + 1 , r , 1 - turn);
		pair<ll , ll> tmp2 = sol(l , r - 1 , 1 - turn);

		tmp1.fi += a[l];
		tmp2.fi += a[r];

		check[l][r] = 1;

		if(tmp1.fi > tmp2.fi) return dp[l][r] = tmp1;
		return dp[l][r] = tmp2;
	}
	else{
		pair<ll , ll> tmp1 = sol(l + 1 , r , 1 - turn);
		pair<ll , ll> tmp2 = sol(l , r - 1 , 1 - turn);

		tmp1.se += a[l];
		tmp2.se += a[r];

		check[l][r] = 1;

		if(tmp1.se > tmp2.se) return dp[l][r] = tmp1;
		return dp[l][r] = tmp2;
	}
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve()
{
	cout << sol(1 , n , 0).fi;
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
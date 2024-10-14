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
#define file "sdigit"
#define add(x , y) (x) = ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e4 + 5;
const int LOG = 20;

int d , n;
ll dp[N][3][101];
string k;

ll sol(int i , int check , int m){
	if(i > n){
		if(!m) return 1;
		return 0;
	}
	ll res = 0;

	if(dp[i][check][m] != -1) return dp[i][check][m];

	if(!check){
		for(int j = 0 ; j <= k[i] - '0' ; j++){
			if(j < k[i] - '0') {
				add(res , sol(i + 1 , 1 , (m + j) % d));
			}
			else 
				add(res , sol(i + 1 , 0 , (m + j) % d));
		}
	}
	else{
		for(int j = 0 ; j <= 9 ; j++){
			// cout << j << '\n';
			add(res , sol(i + 1 , check , (m + j) % d));
		}
	}

	return dp[i][check][m] = res;
}

void inp()
{
	cin >> k >> d;
	n = k.size();
	k = " " + k;
}

void solve()
{
	mem(dp , -1);
	cout << (sol(1 , 0 , 0) - 1 + mod) % mod;
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
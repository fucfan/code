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
const int mod = 1e8;
const int N = 2e4 + 2;
const int phi = 4e7;
const int LOG = 20;

int a , b , cnt;
int f[N][300];

ll Pow(ll a , ll b){
	if(!b) return 1;
	b--;
	ll tmp = a;
	while(b){
		if(b & 1) (a *= tmp) %= phi;
		(tmp *= tmp) %= phi;
		b >>= 1;
	}
	return a;
}

ll Pow1(ll a , ll b){
	if(!b) return 1;
	b--;
	ll tmp = a;
	while(b){
		if(b & 1) (a *= tmp) %= mod;
		(tmp *= tmp) %= mod;
		b >>= 1;
	}
	return a;
}

void solve()
{

	ll ans = Pow1(a , f[a][min(20 , b - 1)]);

	if(a % 10 == 0 && b > 1){
		ans = 0;
	}

	string res;

	while(res.size() < 8){
		res = char('0' + (ans % 10)) + res;
		ans /= 10;
	}

	cout << res << '\n';
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
    // int test_case = 1;
    //cin >> test_case;
    for(int i = 1 ; i <= 20000 ; i++){
    	int tmp = 1;
    	f[i][0] = 1;
    	for(int j = 1 ; j <= 20 ; j++){
    		tmp = Pow(i , tmp);
    		// cout << tmp << ' ';
    		f[i][j] = tmp;
    	}
    	// nl;
    }
    while (cin >> a >> b)
    {
        // inp();
        // cnt++;
        solve();
    }
    Times;
}

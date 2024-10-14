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
const int N = 2e6 + 5;
const int LOG = 20;

struct RMQ{
	ll val , Min , Max , minl , minr , maxl , maxr;
} rmq[N][LOG + 5];

int n;
ll a[N] , x , pref[N];

void prepare(){
	for(int j = 1 ; j <= LOG ; j++){
		for(int i = 1 ; i <= n ; i++){
			rmq[i][j].val = rmq[i][j - 1].val + rmq[i + (1 << (j - 1))][j - 1].val;

			rmq[i][j].Min = min(rmq[i][j - 1].Min , rmq[i + (1 << (j - 1))][j - 1].Min);
			rmq[i][j].Max = max(rmq[i][j - 1].Max , rmq[i + (1 << (j - 1))][j - 1].Max);

			rmq[i][j].minl = rmq[i][j - 1].minl;
			rmq[i][j].maxl = rmq[i][j - 1].maxl;

			rmq[i][j].minr = rmq[i + (1 << (j - 1))][j - 1].minr;
			rmq[i][j].maxr = rmq[i + (1 << (j - 1))][j - 1].maxr;

			rmq[i][j].Min = min(rmq[i][j].Min , rmq[i][j - 1].minr + rmq[i + (1 << (j - 1))][j - 1].minl);
			rmq[i][j].Max = max(rmq[i][j].Max , rmq[i][j - 1].maxr + rmq[i + (1 << (j - 1))][j - 1].maxl);
		}
	}
	for(int i = 1 ; i <= n ; i++){
		while((1 << lg2[i]) <= i) lg2[i]++; 
	}
}

void inp()
{
	cin >> n >> x;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		rmq[i][0] = {a[i] , a[i] , a[i] , a[i] * (a[i] < 0) , a[i] * (a[i] < 0) 
										, a[i] * (a[i] > 0) , a[i] * (a[i] > 0)}
	}
}

void solve()
{
	ll ans = -oo;
	ll Min = 0;
	ll Max = 0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			int l = i;
			int r = j;
			for(int k = LOG ; k >= 0 ; k--){
				if(l + (1 << k) <= r)
			}
		}
	}
	cout << ans;
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
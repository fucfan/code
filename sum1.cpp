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
#define file "sum1"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e6 + 5;
const int LOG = 19;
int n , q;
ll a[N] , rmq[N][LOG + 5];
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int l , r , x;
		cin >> l >> r >> x;
		for(int j = LOG ; j >= 0 ; j--){
			if(l + (1 << j) - 1 <= r){
				// cout << l << ' ' << j << '\n';
				rmq[l][j] += x;
				l += (1 << j);
			}
		}
		// if()
	}
	for(int j = LOG ; j >= 1 ; j--){
		for(int i = 1 ; i <= n ; i++){
			// cout << j << ' ' << i << ' ' << i + (1 << (j - 1)) << '\n';
			rmq[i][j - 1] += rmq[i][j];
			rmq[i + (1 << (j - 1))][j - 1] += rmq[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		cout << rmq[i][0] + a[i] << ' ';
	}
}

void solve()
{

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
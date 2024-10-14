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

int n , k , a[N] , up_big , up_small[N] , id[N] , q;

pii query[N];

vector <int> group[N];

void inp()
{
	cin >> n >> k >> q;

	for(int i = 1 ; i <= n ; i++){
		group[i % k].push_back(i);
		id[i] = i;
	}

	for(int i = 1 ; i <= q ; i++){
		cin >> query[i].fi >> query[i].se;
	}

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
}

void solve()
{
	for(int i = q ; i >= 1 ; i--){
		if(query[i].fi == 1){
			up_big -= query[i].se;
		}
		else{
			// cout << query[i].fi << ' ' << query[i].se << '\n';
			// query[i].se = (1ll * query[i].se + 1ll * n * N) % n;
			if(query[i].se < 0){
				query[i].se = (1ll * query[i].se + 1ll * n * N) % n;
			}
			for(int j = (1 + up_big) % k ; j <= k ; j++){
				up_small[j] += abs(query[i].se) / k;
				// cout << j << ' ' << abs(query[i].se) / k << '\n';
			}
			for(int j = (1 + up_big) % k ; j <= abs(query[i].se) % k ; j++){
				up_small[j]++;
			}
			up_big -= query[i].se;
		}
	}

	// cout << up_big << ' ' << up_small << '\n';

	up_big = (1ll * up_big + 1ll * (n / k) * N) % (n / k);

	for(int i = 1 ; i <= k ; i++) cout << up_small[i] << '\n';
	// up_small = (1ll * up_small + 1ll * k * N) % k;

	// cout << up_big << ' ' << up_small << '\n';
	for(int i = 0 ; i < n / k ; i++){
		for(int j = 1 ; j <= k ; j++){
			cout << a[group[(j + up_big) % k][(i + up_small[j]) % (n / k)]] << ' ';
		}
	}
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
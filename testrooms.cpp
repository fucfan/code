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
#define file "testrooms"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
const int LOG = 20;

int n , k , a[N];
ll dp[N][N] , cost[N][N] , pref[N] , suff[N];

void prepare(){
	for(int i = 1 ; i <= n ; i++) pref[i] = pref[i - 1] + a[i];
	for(int i = n ; i >= 1 ; i--) suff[i] = suff[i + 1] + a[n] - a[i];

	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			int mid = (a[i] + a[j]) >> 1;

			int pos = upper_bound(a + 1 , a + 1 + n , mid) - a;

			// cout << i << ' ' << j << ' ' << pos << ' ' << pref[pos - 1] - pref[i] << ' ' << suff[pos] - suff[j] << '\n';

			cost[i][j] = pref[pos - 1] - pref[i] - (pos - i - 1) * a[i] + suff[pos] - suff[j] - (j - pos) * (a[n] - a[j]);
		}
	}

	for(int i = 1 ; i <= n ; i++) dp[i][1] = suff[1] - suff[i] - ((i - 1) * (a[n] - a[i]));

	// for(int i = 1 ; i <= n ; i++) cout << dp[i][1] << '\n';

	// for(int i = 1 ; i <= n ; i++){
	// 	for(int j = i + 1 ; j <= n ; j++){
	// 		cout << i << ' ' << j << ' ' << cost[i][j] << '\n';
	// 	}
	// }
}

void dnc(int i , int l , int r , int optl , int optr){
	if(l > r) return;

	int opt = -1;

	int mid = (l + r) >> 1;

	for(int f = optl ; f <= mid ; f++){
		if(dp[mid][i] >= dp[f][i - 1] + cost[f][mid]){
			dp[mid][i] = dp[f][i - 1] + cost[f][mid];
			opt = f;
		}
	}

	dnc(i , l , mid - 1 , optl , opt);
	dnc(i , mid + 1 , r , opt , optr);
}

void inp()
{
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];

	sort(a + 1 , a + n + 1);
}

void solve()
{
	mem(dp , 0x3f);

	prepare();

	ll ans = oo;

	// for(int j = 2 ; j <= k ; j++){
	// 	for(int i = j ; i <= n ; i++){
	// 		for(int f = j - 1 ; f < i ; f++){
	// 			dp[i][j] = min(dp[i][j] , dp[f][j - 1] + cost[f][i]);
	// 		}
	// 	}
	// }

	for(int f = 2 ; f <= k ; f++){
		dnc(f , 1 , n , 1 , n);
	}

	for(int i = k ; i <= n ; i++) ans = min(ans , dp[i][k] + pref[n] - pref[i] - (1ll * (n - i) * a[i]));

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
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
#define file "river"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const ll oo = 1e18 + 7;
const int N = 1e6 + 5;
const int LOG = 20;
int n , k , mod;
ll a[N];
void inp()
{
	cin >> n >> mod >> k;
	a[0] = 1;
	for(int i = 1 ; i < n ; i++){
		a[i] = a[i - 1] + 1 + ((1ll * i * i) % mod);
	}
	// for(int i = 0 ; i < n ; i++){
	// 	cout << a[i] << ' ';
	// }
	// nl;
}

void solve()
{
	ll l = 1 , r = 1e15 + 8e6;
	ll ans = -1;
	while(l <= r){
		// cout << l << ' ' << r << '\n';
		ll mid = (l + r) >> 1;
		int i = -1;
		ll length = 0;
		int cnt = 0;
		bool check = 0;
		while(i < n - 1){
			int pos = upper_bound(a + i , a + n , length + mid) - a - 1;
			// cout << pos << ' ' << i << ' ' << length << '\n';
			if(pos <= i && i != n - 1){
				// cout << pos << '\n';
				check = 1;
				break;
			}
			i = pos;
			cnt++;
			length = a[pos];
		}
		if(!check && cnt <= k){
		// cout << check << ' ' << cnt << '\n';
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
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
    cin.tie(0)->ios_base::sync_with_stdio(false);
  
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
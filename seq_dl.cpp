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
const int N = 2e3 + 5;
const int LOG = 20;

int n , a[N];
ll ans;
int cnt[N];
vector <int> compress;

void inp()
{
	cin >> n;

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		compress.pb(a[i]);
	}

	sort(all(compress));
	compress.erase(unique(all(compress)) , compress.end());
}

void solve()
{
	for(int i = 1 ; i <= n ; i++) a[i] = lower_bound(all(compress) , a[i]) - compress.begin();

	for(int i = 1 ; i <= n ; i++){
		int tmp = 0;
		ll sum = 0;

		mem(cnt , 0);

		for(int j = i ; j <= n ; j++){
			cnt[a[j]] ^= 1;
			sum += a[j];

			if(cnt[a[j]]) tmp++;
			else tmp--;

			if(!tmp && sum){
 				ans++;
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
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
#define file "tera"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , l;
int a[5][N];
ll ans;
vector <int> length;

void inp()
{
	cin >> n >> l;
	for(int i = 1 ; i <= 4 ; i++){
		for(int j = 1 ; j <= n ; j++) cin >> a[i][j];
	}
}

void solve()
{
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(a[1][i] + a[2][j] > l) continue;
			length.pb(a[1][i] + a[2][j]);
		}
	}

	sort(all(length));

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(a[3][i] + a[4][j] > l) continue;
			int left = lower_bound(all(length) , l - a[3][i] - a[4][j]) - length.begin();
			if(length[left] == l - a[3][i] - a[4][j]){
				int right = upper_bound(all(length) , l - a[3][i] - a[4][j]) - length.begin() - 1;
				ans += right - left + 1;
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

main()
{
    cin.tie(0)->sync_with_stdio(false);
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
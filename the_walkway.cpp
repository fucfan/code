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
int n , d , m , s[N];
void inp()
{
	cin >> n >> m >> d;
	for(int i = 1 ; i <= m ; i++){
		cin >> s[i];
	}
}

void solve()
{
	int last = 1;
	int cnt = 1;
	for(int i = 1 ; i <= m ; i++){
		cnt += (s[i] - last) / d;
		cnt += (s[i] - last) % d != 0;
		last = s[i];
	}
	cnt += (n - s[m]) / d;
	// cout << cnt << '\n';
	last = 0;
	int ans = cnt;
	int res = 0;
	// cout << cnt << '\n';
	for(int i = 2 ; i < m ; i++){
		int val = cnt;
		val -= (s[i] - s[i - 1]) / d;
		val -= (s[i] - s[i - 1]) % d != 0;
		val -= (s[i + 1] - 1 - s[i]) / d;
		val += (s[i + 1] - 1 - s[i - 1]) / d;
		// val -= (s[i + 1] - s[i - 1] %  d != 0);
		// cout << val << ' ';
		if(ans > val){
			ans = val;
			res = 1;
		}
		else if(ans == val) res++;
	}
	int val = cnt;
	val -= (s[1] - 1) / d;
	val -= ((s[1] - 1) % d != 0);
	val -= (s[2] - 1 - s[1]) / d;
	val += (s[2] - 2) / d;
	// cout << val << ' ';
	if(ans > val){
		ans = val;
		res = 1;
	}
	else if(ans == val) res++;
	val = cnt;
	val -= (s[m] - s[m - 1]) / d;
	val -= (((s[m] - s[m - 1]) % d) != 0);
	val -= (n - s[m]) / d;
	val += (n - s[m - 1]) / d;
	// cout << val << ' ';
	if(ans > val){
		ans = val;
		res = 1;
	}
	else if(ans == val) res++;
	// nl;
	cout << ans << ' ' << res << '\n';
	// cout << "gg\n";
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
    cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
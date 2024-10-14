// Code by Diamond
#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ON(x, i) ((x) | (1 << (i)))
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

template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 25;
const int LOG = 20;

ll n, k, s;
ll d[N][N];
bool check = 0;
vector <int> trace , ans;

void inp()
{
	cin >> k >> n >> s;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			cin >> d[i][j];
}

void magic(int i, ll last, ll sum)
{
	if (i > k)
	{
		if (sum == s)
		{
			check = 1;
			for(int j = 0 ; j < ans.size() ; j++){
				if(ans[j] < trace[j]){
					return;
				}
				if(ans[j] > trace[j]){
					ans = trace;
					return;
				}
			}
		}
		return;
	}

	for (int j = 1; j <= n; j++)
	{
		if (d[j][i] < last)
			continue;
		trace.pb(d[j][i]);
		magic(i + 1, d[j][i], sum + d[j][i]);
		trace.pop_back();
	}
}

void solve()
{
	for(int i = 1 ; i <= k ; i++) ans.pb(oo);
	magic(1, 0, 0);
	if (check){
		cout << "YES\n";
		for(auto i : ans) cout << i << ' ';
	}
	else
		cout << "NO\n";
		
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
    cin.tie(0)->sync_with_stdio(0);
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

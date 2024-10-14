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
#define file "phuc"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , val[N] , lim , dp[N];
vector <int> adj[N];
int get_max(int i , int a[]){
	if(i > lim) return 0;
	int res = 1e9;
	if(dp[i] != -1) return dp[i];
	int val1 = get_max(i + 1 , a) + a[i];
	int val2 = get_max(i + 1 , a) - a[i];
	if(abs(val1) > abs(val2)) res = val2;
	else res = val1;
	return dp[i] = res;
}
void dfs(int i , int par){
	int cnt = 0;
	int sum = 0;
	int a[adj[i].size() + 1];
	for(auto j : adj[i]){
		if(j == par) continue;
		dfs(j , i);
		cnt++;
		sum += val[j];
		a[cnt] = val[j];
		// cout << j << ' ' << val[j] << "\n";
		// cout << val[j] << '\n';
	}
	if(adj[i].size() == 1 && i != 1) return;
	lim = cnt;
	for(int i = 0 ; i <= cnt + 1 ; i++){
		dp[i] = -1;
	}
	// nl;
	cout << i << '\n';
	for(int j = 1 ; j <= lim ; j++){
		cout << a[j] << ' ' << val[j] << "gg\n";
	}
	nl;
	// nl;
	int minus = abs(get_max(1 , a));
	// cout << minus << '\n';
	cout << i << ' ' << sum << ' ' << minus << '\n';
	val[i] = (((sum + minus) / 2) * ((sum - minus) / 2) + (val[i] * sum) * );
}
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> val[i];
	}
	for(int i = 2 ; i <= n ; i++){
		int x;
		cin >> x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
}

void solve()
{
	dfs(1 , 0);
	cout << val[1] << '\n';
	for(int i = 1 ; i <= n ; i++){
		cout << val[i] << ' ';
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
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
#define file "sumdistance"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , child[N];
ll dp[N];
vector <pii> adj[N];

void dfs(int i , int p){
	child[i] = 1;

	for(auto it : adj[i]){
		int j = it.fi;
		int w = it.se;
		if(j == p) continue;
		dfs(j , i);

		dp[i] += dp[j] + 1ll * child[j] * w;
		child[i] += child[j];
	}
}

void dfs2(int i , int p , ll val){	
	if(i != 1) dp[i] = dp[p] - val * child[i] + val * (n - child[i]);

	for(auto it : adj[i]){
		int j = it.fi;
		int w = it.se;
		if(j == p) continue;
		dfs2(j , i , w);
	}
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int u , v , c;
		cin >> u >> v >> c;
		adj[u].pb({v , c});
		adj[v].pb({u , c});
	}
}

void solve()
{
	dfs(1 , 0);
	dfs2(1 , 0 , 0);

	for(int i = 1 ; i <= n ; i++) cout << dp[i] << '\n';
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
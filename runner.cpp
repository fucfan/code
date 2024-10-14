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
#define file "runner"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , m , par[N][LOG + 1] , h[N] , is_lca[N] , val[N];
vector <int> adj[N];
void dfs(int i , int p){
	for(auto j : adj[i]){
		if(j == p) continue;
		par[j][0] = i;
		h[j] = h[i] + 1;
		dfs(j , i);
	}
}
void dfs1(int i){
	for(auto j : adj[i]){
		if(j == par[i][0]) continue;
		dfs1(j);
		val[i] += val[j];
	} 
}
void prepare(){
	h[0] = -1;
	for(int j = 1 ; j <= LOG ; j++){
		for(int i = 1 ; i <= n ; i++){
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
int lca(int u , int v){
	if(h[u] > h[v]) swap(u , v);
	// cout << h[u] << ' ' << h[v] << '\n';
	// cout << par[u][0] << ' ' << par[v][0] << '\n';
	for(int i = LOG ; i >= 0 ; i--){
		if(h[par[v][i]] >= h[u]) v = par[v][i];
		// cout << i << ' ' << par[v][i] << ' ' << h[par[v][i]] << '\n';
	}
	// cout << u << ' ' << v << '\n';
	for(int i = LOG ; i >= 0 ; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	if(u != v) return par[u][0];
	return v;
}
void inp()
{
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int a , b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1 , 0);
	// for(int i = 1 ; i <= n ; i++)
	// 	cout << par[i][0] << '\n';
	prepare();
	// cout << lca(1 , 2) << '\n'
	// 	 << lca(2 , 5) << '\n'
	// 	 << lca(2 , 4) << '\n';
	for(int i = 1 ; i < n ; i++){
		val[i]++;
		val[i + 1]++;
		int c = lca(i , i + 1);
		val[c]--;
		val[par[c][0]]--;
	}
	// for(int i = 1 ; i <= n  ;i++) cout << val[i] << ' ';
	// 	nl;
	dfs1(1);
	for(int i = 1 ; i <= n ; i++){
		cout << val[i] << '\n'; 
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
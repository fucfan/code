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

int n , v , par[N][LOG + 5] , depth[N] , sumP[N];
ll p[N] , p_near[N][LOG + 5];
vector <int> adj[N];

void dfs(int i , int pre){
	sumP[i] += p[i];
	for(auto j : adj[i]){
		if(j == pre) continue;
		p_near[i][0] += p[j];
		depth[j] = depth[i] + 1;
		sumP[j] += sumP[i];
		par[j][0] = i;
		dfs(j , i);
	}
}

void prepare(){
	dfs(1 , 0);
	depth[0] = -1;
	for(int j = 1 ; j <= LOG ; j++){
		for(int i = 1 ; i <= n ; i++){
			par[i][j] = par[par[i][j - 1]][j - 1];
			p_near[i][j] = p_near[i][j - 1] + p_near[par[i][j - 1]][j - 1];
		}
	}
}


pair <ll , int> lca(int u , int v){
	int f_u = u;
	int f_v = v;

	if(depth[u] > depth[v]) swap(u , v);

	ll res = 0;

	for(int i = LOG ; i >= 0 ; i--){
		if(depth[par[v][i]] >= depth[u]){
			res += p_near[v][i];
			v = par[v][i];
		}
	}

	// if(u == v) return u;

	if(u == v) return {res + p[u] + p_near[u][0] - sumP[f_u] - sumP[f_v] + 2 * sumP[par[u][0]] , u};

	for(int i = LOG ; i >= 0 ; i--){
		if(par[u][i] != par[v][i]){
			res += p_near[u][i];
			res += p_near[v][i];
			u = par[u][i];
			v = par[v][i];
		}
	}

	// cout << u << ' ' << v << '\n';

	// cout << sumP[f_u] << ' ' << sumP[f_v] << '\n';

	return {res + p_near[u][0] + p_near[v][0] + p_near[par[u][0]][0] + p[par[u][0]] + p[par[u][1]] - sumP[f_u] - sumP[f_v] + 2 * sumP[u] , par[u][0]};
}

void inp()
{
	cin >> n >> v;

	for(int i = 1 ; i <= n ; i++) cin >> p[i];

	for(int i = 1 ; i < n ; i++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}	

void solve()
{
	prepare();

	ll ans = 0;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			pair <ll , int> tmp = lca(i , j);
			if(depth[i] + depth[j] - 2 * depth[tmp.se] != v) continue;
			ans = max(ans , tmp.fi);
			// cout << i << ' ' << j << ' ' << lca(i , j) << '\n';
		}
	}

	// cout << lca(6 , 12);

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
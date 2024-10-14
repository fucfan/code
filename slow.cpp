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
#define file "slow"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , P[N] , top_hld[N] , node[N] , idx[N] , cnt , child[N] , tree[N] , par[N];
vector <int> adj[N];

void update(int id , int l , int r , int pos){
	if(pos > r || l > pos) return;
	if(l == r){
		tree[id]++;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1 , l , mid , pos);
	update(id << 1 | 1 , mid + 1 , r , pos);
	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int get(int id , int l , int r , int u , int v){
	if(u > r || l > v) return 0;
	if(u <= l && r <= v) return tree[id];

	int mid = (l + r) >> 1;

	return get(id << 1 , l , mid , u , v) + get(id << 1 | 1 , mid + 1 , r , u , v);
}

void dfs(int i , int p){
	child[i] = 1;
	for(auto j : adj[i]){
		if(j == p) continue;
		par[j] = i;
		dfs(j , i);
		child[i] += child[j];
	}
}

void hld(int i , int p , int top){
	idx[i] = ++cnt;
	node[cnt] = i;
	top_hld[i] = top;

	int best_node = -1;
	int sz = 0;
	for(auto j : adj[i]){
		if(j == p) continue;
		if(sz < child[j]){
			best_node = j;
			sz = child[j];
		}
	}

	if(best_node == -1) return;

	hld(best_node , i , top);

	for(auto j : adj[i]){
		if(j == p || j == best_node) continue;
		hld(j , i , j);
	}
}

int get_val(int u){
	int res = 0;
	while(u){
		res += get(1 , 1 , n , idx[top_hld[u]] , idx[u]);
		u = par[top_hld[u]];
	}
	return res;
}

void prepare(){
	dfs(1 , 0);
	hld(1 , 0 , 1);
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> P[i];
	}
}

void solve()
{
	prepare();
	for(int i = 1 ; i <= n ; i++){
		cout << get_val(P[i]) << '\n';
		update(1 , 1 , n , idx[P[i]]);
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
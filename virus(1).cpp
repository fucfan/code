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
#define file "virus"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , top1 , top2 , tree[N] , top_hld[N] , idx[N] , dp[N] , lazy[N] , d , par[N] , child[N];
ll ans;
vector <int> adj1[N] , adj2[N] , tour;

void down(int id , int l , int r){
	if(lazy[id] == -1 ) return;
	int mid = (l + r) >> 1;
	tree[id << 1] = lazy[id] * (mid - l + 1); 
	lazy[id << 1] = lazy[id];
	tree[id << 1 | 1] = lazy[id] * (r - mid);
	lazy[id << 1 | 1] = lazy[id]; 
	lazy[id] = -1;
}

void build(int id , int l , int r){
	if(l == r){
		tree[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1 , l , mid);
	build(id << 1 | 1 , mid + 1 , r);
	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

void update(int id , int l , int r , int u , int v , int val){
	if(v < l || r < u) return;
	if(u <= l && r <= v){
		tree[id] = (r - l + 1) * val;
		lazy[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	down(id , l , r);
	update(id << 1 , l , mid , u , v , val);
	update(id << 1 | 1 , mid + 1 , r , u , v , val);
	tree[id] = max(0 , tree[id << 1]) + max(0 , tree[id << 1 | 1]);
}

int get(int id , int l , int r , int u , int v){
	if(u > r || l > v) return 0;
	if(u <= l && r <= v) return max(0 , tree[id]);
	int mid = (l + r) >> 1;
	down(id , l , r);
	return get(id << 1 , l , mid , u , v) + get(id << 1 | 1 , mid + 1 , r , u , v);
}

int get_hld(int u){
	int res = 0;
	while(u){
		// cout << u << ' ' << top_hld[u] << '\n';
		int v = top_hld[u];
		res += get(1 , 1 , n , idx[v] , idx[u]);
		u = par[v];
	}
	return res;
}

void dfs1(int i , int p){
	child[i] = 1;

	for(auto j : adj1[i]){
		if(j == p) continue;
		par[j] = i;
		dfs1(j , i);
		child[i] += child[j];
	}
}

void hld(int i , int p , int top){
	idx[i] = ++d;
	top_hld[i] = top;

	int best_node = -1;
	int Max = 0;

	for(auto j : adj1[i]){
		if(j == p) continue;
		if(Max < child[j]){
			Max = child[j];
			best_node = j;
		}
	}

	if(best_node == -1) return;

	hld(best_node , i , top);

	for(auto j : adj1[i]){
		if(j == best_node || j == p) continue;
		hld(j , i , j);
	}
}

void dfs2(int i , int p){
	ans += get_hld(i);

	update(1 , 1 , n , idx[i] , idx[i] , 1);

	for(auto j : adj2[i]){
		if(j == p) continue;
		dfs2(j , i);
	}

	update(1 , 1 , n , idx[i] , idx[i] , 0);

	// cout << i << ' ' << ans << '\n';
}

void prepare(){
	mem(lazy , - 1);
	// build(1 , 1 , n);
	dfs1(top1 , 0);
	hld(top1 , 0 , top1);
	dfs2(top2 , 0);
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		if(x){
			adj1[x].pb(i);
			adj1[i].pb(x);
		}
		else top1 = i;
	}
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		if(x){
			adj2[x].pb(i);
			adj2[i].pb(x);
		}
		else top2 = i;
	}
}

void solve()
{
	prepare();
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
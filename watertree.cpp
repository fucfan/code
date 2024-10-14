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
#define file "watertree"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , q , val[N] , st[N] , en[N] , tree[N] , lazy[N] , par[N];
vector <int> tour , adj[N];

void down(int id){
	if(lazy[id] == -1) return;
	tree[id << 1] = lazy[id];
	lazy[id << 1] = lazy[id];
	tree[id << 1 | 1] = lazy[id];
	lazy[id << 1 | 1] = lazy[id]; 
	lazy[id] = -1;
}

void update(int id , int l , int r , int u , int v , int x){
	if(v < l || r < u) return;
	if(u <= l && r <= v){
		tree[id] = x;
		lazy[id] = x;
		return;
	}
	int mid = (l + r) >> 1;
	down(id);
	update(id << 1 , l , mid , u , v , x);
	update(id << 1 | 1 , mid + 1 , r , u , v , x);
	tree[id] = min(tree[id << 1] , tree[id << 1 | 1]);
}

int get(int id , int l , int r , int u , int v){
	if(u > r || l > v) return 1;
	if(u <= l && r <= v){
		return tree[id];
	}
	int mid = (l + r) >> 1;
	down(id);
	int tmp = min(get(id << 1 , l , mid , u , v) , get(id << 1 | 1 , mid + 1 , r , u , v));
	// cout << l << ' ' << r << ' ' << tmp << '\n';
	return tmp;
}

void dfs(int i , int p){
	tour.pb(i);
	st[i] = tour.size() - 1;

	for(auto j : adj[i]){
		if(j == p) continue;
		par[j] = i;
		dfs(j , i);
	}

	en[i] = tour.size() - 1;
}

void prepare(){
	tour.pb(0); 
	dfs(1 , 0);
	// for(int i = 1 ; i <= n ; i++) cout << st[i] << ' ' << en[i] << '\n';
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
}

void solve()
{
	prepare();
	mem(lazy , -1);
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int type , x;
		cin >> type >> x;
		if(type == 1){
			if(!get(1 , 1 , n , st[x] , en[x])) update(1 , 1 , n , st[par[x]] , st[par[x]] , 0);
			update(1 , 1 , n , st[x] , en[x] , 1);
		}
		if(type == 2) update(1 , 1 , n , st[x] , st[x] , 0);
		if(type == 3) cout << get(1 , 1 , n , st[x] , en[x]) << '\n';
		// cout << type << ' ' << x << '\n';
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
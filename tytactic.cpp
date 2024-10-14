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
#define file "tytactic"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , q , val[N] , st[N] , en[N] , tree[N];
vector <int> tour , adj[N];

void build(int id , int l , int r){
	if(l == r){
		// cout << l << ' ' << r << ' ' << val[tour[l]] << '\n';
		tree[id] = val[tour[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1 , l , mid);
	build(id << 1 | 1 , mid + 1 , r);
	tree[id] = tree[id << 1] + tree[id << 1 | 1];
	// cout << l << ' ' << r << ' ' << tree[id] << '\n'; 
}

void update(int id , int l , int r , int pos , int x){
	if(pos < l || r < pos) return;
	if(l == r){
		tree[id] = x;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1 , l , mid , pos , x);
	update(id << 1 | 1 , mid + 1 , r , pos , x);
	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int get(int id , int l , int r , int u , int v){
	if(u > r || l > v) return 0;
	if(u <= l && r <= v){
		return tree[id];
	}
	int mid = (l + r) >> 1;
	int tmp = get(id << 1 , l , mid , u , v) + get(id << 1 | 1 , mid + 1 , r , u , v);
	// cout << l << ' ' << r << ' ' << tmp << '\n';
	return tmp;
}

void dfs(int i , int p){
	tour.pb(i);
	st[i] = tour.size() - 1;

	for(auto j : adj[i]){
		if(j == p) continue;
		dfs(j , i);
	}

	en[i] = tour.size() - 1;
}

void prepare(){
	tour.pb(0); 
	dfs(1 , 0);
	build(1 , 1 , n);
	// for(int i = 1 ; i <= n ; i++) cout << st[i] << ' ' << en[i] << '\n';
}

void inp()
{
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++) cin >> val[i];
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
	for(int i = 1 ; i <= q ; i++){
		char type;
		cin >> type;
		if(type == 'Q'){
			int x;
			cin >> x;
			cout << get(1 , 1 , tour.size() - 1 , st[x] , en[x]) << '\n';
		}
		else{
			int x , y;
			cin >> x >> y;
			update(1 , 1 , tour.size() - 1 , st[x] , y);
		}
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
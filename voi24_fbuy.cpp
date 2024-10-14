#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}


struct Query{
	int id;
	int node, new_type;

	void input(int num){
		cin >> node >> new_type;
		id = num;
	}
} query[N];

int ans[N];
vector <int> adj[N];
vector <Query> upt[N];
int n, k, q, init_type[N], a[N], c[N], type[N];

struct centroid_decomposition{
	struct segment_tree{
		pii node[N << 2 | 1];
		int lazy[N << 2 | 1];

		void down(int id, int l, int r){
			int mid = (l + r) >> 1;
			node[id << 1].fi += 2 * node[id << 1].se + lazy[id] * lazy[id] * (mid - l + 1);
			node[id << 1].se += (mid - l + 1) * lazy[id];
			lazy[id << 1] += lazy[id];

			node[id << 1 | 1].fi += 2 * node[id << 1 | 1].se + lazy[id] * lazy[id] * (r - mid);
			node[id << 1 | 1].se += (r - mid) * lazy[id];
			lazy[id << 1 | 1] += lazy[id];

			lazy[id] = 0;
		}

		void update(int id, int l, int r, int u, int v, int val){
			if(u > r || l > v) return;

			if(l == r){
				node[id].fi += 2 * node[id].se * val + val * val * (r - l + 1);
				node[id].se += (r - l + 1) * val;
				lazy[id]++;
				return;
			}

			int mid = (l + r) >> 1;

			down(id, l, r);

			update(id << 1, l, mid, u, v, val);
			update(id << 1 | 1, mid + 1, r, u, v, val);

			node[id].fi = node[id << 1].fi + node[id << 1 | 1].fi;
			node[id].se = node[id << 1].se + node[id << 1 | 1].se;
		}

		pii get(int id, int l, int r, int u, int v){
			if(l > v || u > r) return {0, 0};

			if(u <= l && r <= v) return node[id];

			int mid = (l + r) >> 1;

			down(id, l, r);

			pii x = get(id << 1, l, mid, u, v);
			pii y = get(id << 1 | 1, mid + 1, r, u, v);

			return {x.fi + y.fi, x.se + y.se};
		}
	} IT[21];

	bool del[N];
	vector <int> cd_node[N];
	int sz[N], st[N], en[N], num_node, cnt_type[30], val_type[30], cur_val, res, tmp_type[30];
	
	void get_sz(int i, int p){
		sz[i] = 1;
		for(auto j : adj[i]){
			if(j == p || del[j]) continue;
			get_sz(j, i);
			sz[i] += sz[j];
		}
	}

	void dfs(int i, int p, int root){
		cd_node[i].pb(root);
		for(auto j : adj[i]){
			if(del[j] || j == p) continue;
			dfs(j, i, root);
		}
	}

	int get_centroid(int i, int p, int num_node){
		for(auto j : adj[i]){
			if(del[j] || sz[j] <= num_node / 2 || j == p) continue;
			return get_centroid(j, i, num_node);
		}
		return i;
	}

	void get_par_centroid(int i){
		get_sz(i, 0);
		int root = get_centroid(i, 0, sz[i]);
		dfs(root, 0, root);
		del[root] = 1;
		for(auto j : adj[root]){
			if(del[j]) continue;
			get_par_centroid(j);
		}
	}

	void euler_prepare(int i, int p){
		sz[i] = 1;
		type[i] = init_type[i];
		st[i] = ++num_node;
		for(auto j : adj[i]){
			if(j == p) continue;
			euler_prepare(j, i);
			sz[i] += sz[j];
		}
		en[i] = num_node;
	}																														

	void get_val(int i, int p, int cnt_node){
		cur_val += c[type[i]] * (2 * cnt_type[type[i]] * val_type[type[i]] + 1) * sz[i];
		cout << i << ' ' << cur_val << ' ' << val_type[type[i]] << ' ' << c[type[i]] * (2 * cnt_type[type[i]] * val_type[type[i]] + 1) * sz[i] << "gg\n";
		cnt_type[type[i]]++;
		res += cur;
		IT[i].update(1, 1, num_node, st[i], en[i], 1);
		for(auto j : adj[i]){
			if(j == p || del[j]) continue;
			get_val(j, i, cnt_node);
		}
		cnt_type[type[i]]--;
	}

	void update(int i, int p, int tmp){
		val_type[type[i]] += sz[i];

		for(auto j : adj[i]){
			if(j == p || del[j]) continue; 
			update(j, i, tmp);
		}
	}

	void sol(int i){
		res = 0;
		get_sz(i, 0);
		int root = get_centroid(i, 0, sz[i]);

		num_node = 0;
		euler_prepare(root, 0);

		int tmp = 1;
		cur_val = 0;

		tmp_type[type[root]] = 1;
		val_type[type[root]] = 1;

		for(auto j : adj[root]){
			if(del[j]) continue;
			cur_val += c[type[root]] * sz[j];
			cnt_type[type[root]] = 1;
			get_val(j, root, tmp);
			cout << j << ' ' << cur_val << ' ' << c[type[root]] * sz[j] << "oo\n";
			update(j, root, c[type[root]] * sz[j]);
			tmp += sz[j];
			cout << j << ' ' << cur_val << "ff\n";
		}

		ans[0] += cur_val;

		cout << i << ' ' << root << '\n';

		del[root] = 1;

		for(auto j : adj[root]){
			if(del[j]) continue;
			sol(j);
		}
	}
} cd;

void prepare(){
	cd.get_par_centroid(1);
	for(int i = 1; i <= n; i++) cd.del[i] = 0;
	for(int i = 1; i <= q; i++){
		for(auto j : cd.cd_node[i]){
			upt[j].pb(query[i]);
		}
	}
}

void inp(){
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) cin >> init_type[i];
    for(int i = 1; i <= k; i++) cin >> c[i];
    for(int i = 2; i <= n; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    for(int i = 1; i <= q; i++){
    	query[i].input(i);
    }
}

void solve(){
	prepare();
    cd.sol(1);
    cout << ans[0];
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
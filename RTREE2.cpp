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
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, q;
vector <int> adj[N];

struct segment_tree{
    int node[N << 2 | 1];
    int lazy[N << 2 | 1];

    void down(int id){
        node[id << 1] += lazy[id]; 
        lazy[id << 1] += lazy[id];
        node[id << 1 | 1] += lazy[id]; 
        lazy[id << 1 | 1] += lazy[id]; 

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if(u > r || l > v) return;

        if(u <= l && r <= v){
            node[id] += val;
            lazy[id] += val;
            return;
        }

        int mid = (l + r) >> 1;

        down(id);

        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);

        node[id] = max(node[id << 1], node[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v){
        if(u > r || l > v) return 0;
    
        if(u <= l && r <= v) return node[id];

        int mid = (l + r) >> 1;

        down(id);

        return max(get(id << 1, l, mid, u, v),
                   get(id << 1 | 1, mid + 1, r, u, v));
    }
} it;

struct HLD{
    int num_dfs;
    int top[N];
    int depth[N];
    int id[N];
    int node[N];
    int par[N];
    int sz[N];

    void dfs(int i, int p){
        sz[i] = 1;
        for(auto j : adj[i]){
            if(j == p) continue;
            par[j] = i;
            depth[j] = depth[i] + 1;
            dfs(j, i);
            sz[i] += sz[j];
        }
    }

    void dfs_hld(int i, int p, int tp){
        id[i] = ++num_dfs;
        node[id[i]] = i;
        top[i] = tp;
        int Max = -1;
        int best_node = -1;
        for(auto j : adj[i]){
            if(j == p) continue;
            if(maxi(Max, sz[j])) best_node = j;
        }
        if(best_node != -1) dfs_hld(best_node, i, tp);

        for(auto j : adj[i]){
            if(j == p || j == best_node) continue;
            dfs_hld(j, i, j);
        }
    }
} hld;;

struct Edge{
    int u, v;

    void get_ans(){
        if(hld.depth[u] > hld.depth[v]) swap(u, v);
        cout << it.get(1, 1, n, hld.id[v], hld.id[v]) << '\n';
    }
} edge[N];

void update(int u, int v){
    while(hld.top[u] != hld.top[v]){
        if(hld.depth[hld.top[u]] > hld.depth[hld.top[v]]) swap(u, v);
        it.update(1, 1, n, hld.id[hld.top[v]], hld.id[v], 1);
        v = hld.par[hld.top[v]];
    }
    if(hld.depth[u] > hld.depth[v]) swap(u, v);
    it.update(1, 1, n, hld.id[u] + 1, hld.id[v], 1);
}

void inp(){
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    hld.dfs(1, 0);
    hld.dfs_hld(1, 0, 1);
    for(int i = 1; i <= q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            update(u, v);
        }
        else{
            int u;
            cin >> u;
            edge[u].get_ans();
        }
    }
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
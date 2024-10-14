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
vector <pii> adj[N];

struct HLD{
    int num_dfs;
    int top[N];
    int id[N];
    int pos[N];
    int depth[N];
    int dis[N];
    int sz[N];
    int par[N];

    void dfs(int i, int p){
        sz[i] = 1;
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p) continue;
            depth[j] = depth[i] + 1;
            dis[j] = it.se;
            par[j] = i;
            dfs(j, i);
            sz[i] += sz[j];
        }
    }

    void dfs_build(int i, int p, int tp){
        top[i] = tp;
        id[i] = ++num_dfs;
        // st[i] = num_dfs;
        pos[id[i]] = i;
        int best_node = -1;
        int Max = -1;
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p) continue;
            if(maxi(Max, sz[j])) best_node = j;
        }

        if(best_node != -1) dfs_build(best_node, i, tp);

        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p || j == best_node) continue;
            dfs_build(j, i, j);
        }
        // en[i] = num_dfs;
    }
    
    void build(){
        dfs(1, 0);
        dfs_build(1, 0, 1); 
    }
} hld;


struct segment_tree{
    pii node[N << 2 | 1];
    pii lazy[N << 2 | 1];

    int down(int id, int l, int r){
            // cout << l << ' ' << r << ' ' << node[id].fi << ' ' << node[id].se << "gg\n";
        if(l == r){
            return (1ll * node[id].fi * node[id].se) % mod;
        }

        int mid = (l + r) >> 1;

        node[id << 1].fi = add(node[id].fi, node[id << 1].fi);
        node[id << 1].se = add(node[id].se, node[id << 1].se);
        node[id << 1 | 1].fi = add(node[id].fi, node[id << 1 | 1].fi);
        node[id << 1 | 1].se = add(node[id].se, node[id << 1 | 1].se);

        node[id] = {0, 0};

        int x = down(id << 1, l, mid);
        int y = down(id << 1 | 1, mid + 1, r);

        return add(x, y);
    }

    void update(int id, int l, int r, int u, int v, pii val){
        if(u > r || l > v) return;

        if(u <= l && r <= v){
            // cout << l << ' ' << r << ' ' << node[id].fi << ' ' << node[id].se << '\n';
            node[id].fi = add(node[id].fi, val.fi);
            node[id].se = add(node[id].se, val.se);
            // cout << l << ' ' << r << ' ' << node[id].fi << ' ' << node[id].se << '\n';

            return;
        }

        int mid = (l + r) >> 1;

        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);

        // merge(id);
    }
} IT;

void update_root(int node, pii val){
    while(node){
        IT.update(1, 1, n, hld.id[hld.top[node]], hld.id[node], val);
        node = hld.par[hld.top[node]];
    }
}

int lca(int u, int v){
    while(hld.top[u] != hld.top[v]){
        if(hld.depth[hld.top[u]] > hld.depth[hld.top[v]]) swap(u, v);
        v = hld.par[hld.top[v]];
    }
    if(hld.depth[u] > hld.depth[v]) swap(u, v);
    return u;
}

int dist(int u, int v){
    return sub(add(hld.depth[u], hld.depth[v]), 2ll * hld.depth[lca(u, v)] % mod);
}

void prepare(){
    hld.build();
    hld.depth[0] = -1;
}

void inp(){
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        w = 1;
        cin >> u >> v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
}

void solve(){
    prepare();
    vector <int> st;
    for(int i = 1; i <= q; i++){
        int k;
        cin >> k;
        if(k > sqrt(n)){
            for(int i = 1; i <= k; i++){
                int x;
                cin >> x;
                IT.update(1, 1, n, 1, n, {x, 0});
                update_root(x, {-x + mod, x});
                st.pb(x);
            }   

            cout << IT.down(1, 1, n) << '\n';

            while(st.size()){
                int x = st.back();
                IT.update(1, 1, n, 1, n, {-x + mod, 0});
                update_root(x, {x, -x + mod});
                st.pop_back();
            }
        }
        else{
            int ans = 0;
            for(int i = 1; i <= k; i++){
                int x;
                cin >> x;
                st.pb(x);
            }   
            for(int j = 0; j < st.size(); j++){
                for(int k = j + 1; k < st.size(); k++){
                    int u = st[j];
                    int v = st[k];
                    // cout << u << ' ' << v << ' ' << dist(u, v) << '\n';
                    ans = add(ans, (1ll * u * v % mod) * dist(u, v) % mod);
                }
            }
            st.clear();
            cout << ans << '\n';
        }
    }
}

main(){
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
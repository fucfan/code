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
#define file "netw"
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

int n, res[N], sz_comp;
vector <pii> adj[N];
vector <int> compress;

int add(int x, int y){
    if(x + y < mod) return x + y;
    return x + y - mod;
}

int sub(int x, int y){
    if(x - y >= 0) return x - y;
    return x - y + mod;
}

struct fenwick_tree{
    int node[N];

    void update(int pos, int val){
        if(val < 0) val += mod;
        for(; pos <= sz_comp; pos += (pos & -pos)){
            node[pos] = add(node[pos], val);
        }
    }

    int get(int pos){
        int res = 0;
        for(; pos > 0; pos -= (pos & -pos)){
            res = add(res, node[pos]);
        }
        return res;
    }
} BIT[6];

struct centroid_decomposition{
    int sz[N];
    pair <int, pii> val[N];
    bool del[N];

    void get_sz(int i, int p){
        sz[i] = 1;
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p || del[j]) continue;
            get_sz(j, i);
            sz[i] += sz[j];
        }
    }

    int find_centroid(int i, int p, int cur_sz){
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p || del[j] || sz[j] <= cur_sz / 2) continue;
            return find_centroid(j, i, cur_sz);
        }
        return i;
    }

    void update(int i, int p, int Min, int depth, int type){
        BIT[0].update(Min, 1ll * depth * depth % mod * compress[Min - 1] % mod * type);
        BIT[1].update(Min, 1ll * depth * compress[Min - 1] % mod * type);
        BIT[2].update(Min, 1ll * depth * depth % mod * type);
        BIT[3].update(Min, depth * type);
        BIT[4].update(Min, compress[Min - 1] % mod * type);
        BIT[5].update(Min, 1 * type);
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p || del[j]) continue;
            update(j, i, min(Min, it.se), depth + 1, type);
        }
    }

    void get_val(int i, int p, int Min, int depth){
        res[i] = add(res[i], BIT[0].get(Min));
        res[i] = add(res[i], 1ll * BIT[1].get(Min) * 2 % mod * depth % mod);
        res[i] = add(res[i], 1ll * BIT[4].get(Min) * depth % mod * depth % mod);

        res[i] = add(res[i], 1ll * sub(BIT[2].get(sz_comp), BIT[2].get(Min)) * compress[Min - 1] % mod);
        res[i] = add(res[i], 1ll * sub(BIT[3].get(sz_comp), BIT[3].get(Min)) * 2 % mod * depth % mod * compress[Min - 1] % mod);
        res[i] = add(res[i], 1ll * sub(BIT[5].get(sz_comp), BIT[5].get(Min)) * depth % mod * depth % mod * compress[Min - 1] % mod);
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p || del[j]) continue;
            get_val(j, i, min(Min, it.se), depth + 1); 
        }
    }

    void sol(int i){
        get_sz(i, 0);
        int root = find_centroid(i, 0, sz[i]);
        
        for(auto it : adj[root]){
            int j = it.fi;
            if(del[j]) continue;
            update(j, root, it.se, 1, 1);
        }
        res[root] = add(res[root], BIT[0].get(sz_comp));

        BIT[4].update(sz_comp, compress.back() % mod);
        BIT[5].update(sz_comp, 1);

        for(auto it : adj[root]){
            int j = it.fi;
            if(del[j]) continue;
            update(j, root, it.se, 1, -1);
            get_val(j, root, it.se, 1);
            update(j, root, it.se, 1, 1);
        }
        for(auto it : adj[root]){
            int j = it.fi;
            if(del[j]) continue;
            update(j, root, it.se, 1, -1);
        }

        BIT[4].update(sz_comp, sub(0, compress.back() % mod));
        BIT[5].update(sz_comp, sub(0, 1));

        del[root] = 1;

        for(auto it : adj[root]){
            int j = it.fi;
            if(del[j]) continue;
            sol(j);
        }
    }
} cd;

void prepare(){
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());
    sz_comp = compress.size();

    for(int i = 1; i <= n; i++){
        for(auto &it : adj[i]){
            it.se = lower_bound(all(compress), it.se) - compress.begin() + 1;
        }
    }
}

void inp(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        compress.pb(w);
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
}

void solve(){
    prepare();
    cd.sol(1);
    for(int i = 1; i <= n; i++){
        cout << res[i] << '\n';
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
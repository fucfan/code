#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

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

int n , m;
vector <pii> adj[N];

struct Edge{
    int u , v , w;
    bool used;
    
    bool operator<(Edge b){
        return w < b.w;
    }
    
    bool operator>(Edge b){
        return w > b.w;
    }

    void input(){
        cin >> u >> v >> w;
    }
} edge[N];

struct DSU{
    int par[N] , sz[N];

    void make_set(){
        for(int i = 1 ; i <= n ; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int a){
        return (a == par[a] ? a : get(par[a]));
    }

    bool uni(int a , int b){
        a = get(a);
        b = get(b);

        if(a == b) return 0;

        if(sz[a] > sz[b]) swap(a , b);
        par[a] = b;
        sz[b] += sz[a];

        return 1;
    }
}dsu;

struct LCA{
    int par[N][LOG + 5];
    int Max[N][LOG + 5];
    int Min[N][LOG + 5];
    int depth[N];

    void build(int i , int p){
        if(!p) depth[p] = -1;

        for(int j = 1 ; j <= LOG ; j++){
            par[i][j] = par[par[i][j - 1]][j - 1];
            Max[i][j] = max(Max[i][j - 1] , Max[par[i][j - 1]][j - 1]);
            Min[i][j] = min(Min[i][j - 1] , Min[par[i][j - 1]][j - 1]);
        }

        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p) continue;
            par[j][0] = i;
            Max[j][0] = it.se;
            Min[j][0] = it.se;
            depth[j] = depth[i] + 1;
            build(j , i);
        }
    }

    pii get(int u , int v){
        pii res = {0 , oo};

        if(depth[u] > depth[v]) swap(u , v);

        for(int i = LOG ; i >= 0 ; i--){
            if(depth[par[v][i]] >= depth[u]){
                res.fi = max(res.fi , Max[v][i]);
                res.se = min(res.se , Min[v][i]);
                v = par[v][i];
            }
        }

        if(u == v) return res;

        for(int i = LOG ; i >= 0 ; i--){
            if(par[u][i] != par[v][i]){
                res.fi = max(res.fi , Max[u][i]);
                res.se = min(res.se , Min[v][i]);
                u = par[u][i];
                v = par[v][i];
            }
        }

        res.fi = max({res.fi , Max[u][0] , Max[v][0]});
        res.se = min({res.se , Min[u][0] , Min[v][0]});

        return res;
    }
} lca;

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        edge[i].input();
    }
}

void solve(){
    sort(edge + 1 , edge + 1 + m , greater<>());

    dsu.make_set();

    for(int i = 1 ; i <= m ; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        if(dsu.uni(u , v)){
            adj[u].pb({v , w});
            adj[v].pb({u , w});
            edge[i].used = 1;
        }
    }

    for(int i = 1 ; i <= n ; i++) if(!lca.par[i][0]) lca.build(i , 0);

    ll ans = 0;

    for(int i = 1 ; i <= m ; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if(dsu.get(u) != dsu.get(v)) continue;
        if(edge[i].used) continue;
        pii tmp = lca.get(u , v);
        // cout << u << ' ' << v << ' ' << w << ' ' << tmp.fi << ' ' << tmp.se << '\n';
        ans = max(ans , 1ll * max(tmp.fi , w) + min(tmp.se , w));
    }

    cout << ans;
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
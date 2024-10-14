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

int n, q, par[N][LOG + 5], depth[N], val[N][LOG + 5];
vector <int> adj[N];

void dfs(int i, int p){
    for(auto j : adj[i]){
        if(j == p) continue;
        depth[j] = depth[i] + 1;
        par[j][0] = i;
        dfs(j, i);
    }
}

void prepare(){
    depth[0] = -1;
    dfs(1, 0);
    for(int j = 1; j <= LOG; j++){
        for(int i = 1; i <= n; i++){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

void update(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    for(int i = LOG; i >= 0; i--){
        if(depth[par[v][i]] >= depth[u]){
            val[v][i]++;
            v = par[v][i];
        }
    }

    if(u == v) return;

    for(int i = LOG; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            val[u][i]++;
            val[v][i]++;
            u = par[u][i];
            v = par[v][i];
        }
    }

    val[u][0]++;
    val[v][0]++;
}

void inp(){
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    prepare();
    for(int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        update(u, v);
    }
    for(int j = LOG; j >= 1; j--){
        for(int i = 1; i <= n; i++){
            val[i][j - 1] += val[i][j];
            val[par[i][j - 1]][j - 1] += val[i][j];
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, val[i][0]);  
    }
    cout << res;
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
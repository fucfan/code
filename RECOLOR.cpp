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
#define file "recolor"
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

int n , m;
vector <int> adj[N];
int cor[N] , val[N];
set <int> s[N];

struct DSU{
    int par[N] , sz[N];

    void make_set(){
        for(int i = 1 ; i <= n ; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int a){
        return par[a] = (par[a] == a ? a : get(par[a]));
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
} dsu;

void prepare(){
    dsu.make_set();
    for(int i = 1 ; i <= n ; i++) adj[i].clear();
}

void inp(){
    cin >> n >> m;
    prepare();
    for(int i = 1 ; i <= n ; i++) cin >> cor[i];
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        if(cor[u] == cor[v]) dsu.uni(u , v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int anc_i = dsu.get(i);
        ans = max(ans , dsu.sz[anc_i]);
        for(auto j : adj[i]){
            int anc_j = dsu.get(j);
            if(anc_j != anc_i){
                if(!s[cor[anc_j]].count(anc_j)){
                    s[cor[anc_j]].insert(anc_j);
                    val[cor[anc_j]] += dsu.sz[anc_j];
                    ans = max(ans , val[cor[anc_j]] + 1);
                }
            }
        }
        for(auto j : adj[i]){
            int anc_j = dsu.get(j);
            s[cor[anc_j]].clear();
            val[cor[anc_j]] = 0;
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
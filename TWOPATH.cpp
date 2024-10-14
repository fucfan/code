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
const int N = 3e6 + 5;
const int LOG = 21;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, depth[N], val[N];
vector <pii> adj[N];
pii vst[N];

void dfs(int i, int p){
    for(auto it : adj[i]){
        int j = it.fi;
        if(j == p) continue;
        depth[j] = depth[i] + 1;
        val[j] = (val[i] ^ it.se);
        dfs(j, i);
    }
}

void prepare(){
    depth[0] = -1;
    dfs(1, 0);
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
}

void solve(){
    prepare();
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            // int ancestor = lca(i, j);
            if(!vst[val[i] ^ val[j]].fi){
                vst[val[i] ^ val[j]] = {i, j};
            }
            else{
                return cout << i << ' ' << j << ' '
                            << vst[val[i] ^ val[j]].fi << ' ' << vst[val[i] ^ val[j]].se << '\n', void();
            }
        }
    }

    cout << -1;
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
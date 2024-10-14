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

int n, m;
vector <int> query, ans;

struct DSU{
    int par[N];
    int sz[N];

    void make_set(){
        for(int i = 1; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int a){
        return (a == par[a] ? a : get(par[a]));
    }

    bool uni(int a, int b){
        a = get(a);
        b = get(b);
        if(a == b) return 0;
        if(sz[a] > sz[b]) swap(a, b);
        par[a] = b;
        sz[b] += sz[a];
        return 1;
    }
} dsu;

struct EDGE{
    bool cut;
    int u, v;

    void input(){
        cin >> u >> v;
    }
} edge[N];

void prepare(){
    dsu.make_set();
    for(int i = 1; i < n; i++){
        if(edge[i].cut) continue;
        dsu.uni(edge[i].u, edge[i].v);
    }
    reverse(all(query));
}

void inp(){
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> edge[i].u >> edge[i].v;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int id;
        cin >> id;
        edge[id].cut = 1;
        query.pb(id);
    }
}

void solve(){
    prepare();
    for(auto j : query){
        int u = edge[j].u;
        int v = edge[j].v;
        ans.pb(1ll * dsu.sz[dsu.get(u)] * dsu.sz[dsu.get(v)]);
        dsu.uni(u, v);
    }
    reverse(all(ans));
    for(auto j : ans) cout << j << '\n';
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
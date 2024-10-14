#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair <int , int>
#define pb push_back
#define all(c) (c).begin , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(b))
#define nl cout << '\n';
#define file "trip"

const int N = 5e5 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e18 + 7;
const int LOG = 20;
const int base = 31;

using namespace std;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

int n;
int st[N];
int ans[N];
bool vst[N];
vector <int> adj[N];

struct segment_tree{
    ll node[4 * N];
    ll lazy[4 * N];

    void down(int id , int l , int r){
        if(lazy[id] == -1) return;

        int mid = (l + r) >> 1;
        node[id << 1] = lazy[id] * (mid - l + 1);
        lazy[id << 1] = lazy[id];
        node[id << 1 | 1] = lazy[id] * (r - mid);
        lazy[id << 1 | 1] = lazy[id];

        lazy[id] = -1;
    }

    void build(int id , int l , int r){
        if(l == r){
            lazy[id] = -1;
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1 , l , mid);
        build(id << 1 | 1 , mid + 1 , r);

        lazy[id] = -1;
    }

    void update(int id , int l , int r , int u , int v , ll val){
        if(u > r || l > v) return;

        if(u <= l && r <= v){
            node[id] = val * (r - l + 1);
            lazy[id] = val;
            return;
        }

        int mid = (l + r) >> 1;

        down(id , l , r);

        update(id << 1 , l , mid , u , v , val);
        update(id << 1 | 1 , mid + 1 , r , u , v , val);

        node[id] = node[id << 1] + node[id << 1 | 1];
    }

    ll get(int id , int l , int r , int u , int v){
        if(u > r || l > v) return 0;

        if(u <= l && r <= v) return node[id];

        int mid = (l + r) >> 1;

        down(id , l , r);

        return get(id << 1 , l , mid , u , v) +
               get(id << 1 | 1 , mid + 1 , r , u , v);
    }
} ST;

struct HLD{
    int tp[N];
    int idx[N];
    int num_node;
    int node[N];
    int child[N];
    int par[N];

    void dfs_child(int i , int p){
        child[i] = 1;

        for(auto j : adj[i]){
            if(j == p) continue;
            par[j] = i;
            dfs_child(j , i);
            child[i] += child[j];
        }
    }

    void dfs(int i , int p , int top){
        num_node++;
        idx[i] = num_node;
        node[num_node] = i;
        tp[i] = top;

        int best_node = -1;
        int Max = -1;

        for(auto j : adj[i]){
            if(j == p) continue;
            if(Max < child[j]){
                Max = child[j];
                best_node = j;
            }
        }

        if(best_node != -1) dfs(best_node , i , top);

        for(auto j : adj[i]){
            if(j == p || j == best_node) continue;
            dfs(j , i , j);
        }
    }

    void update(int u , int val){
        while(u){
            ST.update(1 , 1 , n , idx[tp[u]] , idx[u] , val);
            u = par[tp[u]];
        }
    }
} hld;

void prepare(){
    ST.build(1 , 1 , n);
    hld.dfs_child(1 , 0);
    hld.dfs(1 , 0 , 1);
    ans[1] = (n - 1) * 2;
}

void inp()
{
    cin >> n;
    for(int i = 2 ; i <= n ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve()
{
    prepare();

    // for(int i = 1 ; i <= n ; i++) cout << hld.idx[i] << ' ';
    // nl;

    // for(int i = 1 ; i <= n ; i++) cout << hld.node[i] << ' ';
    // nl;

    for(int i = 2 ; i <= n ; i++){
        for(int j = i ; j <= n ; j += i){
            hld.update(j , 1);
        }

        // for(int j = 1 ; j <= n ; j++) cout << ST.get(1 , 1 , n , hld.idx[j] , hld.idx[j]) << ' ';
        // nl;

        ans[i] = (ST.node[1] - 1) * 2;

        for(int j = i ; j <= n ; j += i){
            hld.update(j , 0);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
//    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

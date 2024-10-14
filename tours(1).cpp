#include <bits/stdc++.h>
#define ll long long
#define BIT(x , i) (((x) >> (i)) & 1)
#define flip(x , i) ((x) ^ (1 << (i)))
#define fi first
#define se second
#define pii pair<ll , ll>
#define pb push_back
#define nl cout << '\n';
#define add(x , y) ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
#define all(c) (c).begin() , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(a))
#define file "tours"

using namespace std;

const int N = 4e5 + 5;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int base = 31;
const int LOG = 20;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

int n , m;
vector<int> adj[N];
bool deleted[N] , ans[N];
int del_node[N];

struct disjoint_set_union{
    int par[N] , sz[N];

    void make_set(){
        for(int i = 1 ; i <= n ; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int i){
        return (i == par[i] ? i : get(par[i]));
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

void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> del_node[i];
        deleted[del_node[i]] = 1;
    }
}

void solve()
{
    dsu.make_set();

    int scc = 0;
    
    for(int i = n ; i >= 1 ; i--){
        scc++;
        deleted[del_node[i]] = 0;
        for(auto j : adj[del_node[i]]){
            if(deleted[j]) continue;
            if(dsu.uni(j , del_node[i])){
                scc--;
            }
        }
        ans[i] = (scc == 1);
        // cout << scc << '\n';
    }

    for(int i = 1 ; i <= n ; i++){
        cout << (ans[i] == 1 ? "YES" : "NO") << '\n';
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

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

int n , m , s , k;
int val[N];
vector <pii> adj[N];
bool vst[N] , bef[N];

struct DSU{
    int par[N];
    int sz[N];
    
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
} dsu;

void bfs(int s){
    priority_queue <pii , vector <pii> , greater<pii>> q;
    q.push({0 , s});

    ll cur_pow = 0;

    while(q.size()){
        int u = q.top().se;
        int dis = q.top().fi;

        if(dis > cur_pow) break;

        q.pop();
        if(!vst[u]) cur_pow += val[u];
        vst[u] = 1;
        bef[u] = 1;

        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;

            if(!vst[v]){
                q.push({w , v});
            }
        }
    }
    
    int ans = 0;

    if(k == 1){
        dsu.make_set();
        queue <int> qu;
        while(q.size()){
            int node = q.top().se;
            if(vst[node]) continue;
            qu.push(node);
            q.pop();
        }

        while(qu.size()){
            int u = qu.front();

            qu.pop();
            
            for(auto it : adj[u]){
                int v = it.fi;
                int w = it.se;

                if(bef[v]) continue;

                if(w <= cur_pow){
                    dsu.uni(u , v);
                    if(!vst[v]){
                        qu.push(v);
                        vst[v] = 1;
                    }
                }
            }
        }

        for(int i = 1 ; i <= n ; i++){
            if(!bef[i]) ans = max(ans , dsu.sz[dsu.get(i)]);
        }
    }

    for(int i = 1 ; i <= n ; i++) ans += bef[i];
    cout << ans;
}

void inp(){
    cin >> n >> m >> s >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> val[i];
    }

    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
}

void solve(){
    bfs(s);
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
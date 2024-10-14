#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<ll , ll>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , m , T , c[N] , par[N];
vector <pii> adj[N];
vector <int> new_adj[N];
ll d[N] , ans;

void dfs(int i , int p){
    for(auto j : new_adj[i]){
        if(j == p) continue;
        dfs(j , i);
        c[i] += c[j];
    }
}

void dijsktra(){
    mem(d , 0x3f);
    d[1] = 0;
    priority_queue <pii , vector<pii> , greater<pii>> q;
    q.push({d[1] , 1});

    while(q.size()){
        int u = q.top().se;
        ll dis = q.top().fi;
        q.pop();

        if(dis > d[u]) continue;

        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                par[v] = u;
                q.push({d[v] , v});
            }
            if(d[v] == d[u] + w){
                par[v] = min(par[v] , u);
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        new_adj[i].pb(par[i]);
        new_adj[par[i]].pb(i);
    }

    dfs(1 , 0);
    for(int i = 1 ; i <= n ; i++){
        ans = max(ans , (1ll * c[i] * d[i]) - (1ll * c[i] * T));
    }
}

void inp(){
    cin >> n >> m >> T;
    for(int i = 1 ; i <= n ; i++) cin >> c[i];
    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
}

void solve(){
    dijsktra();
    cout << ans;
}

void run_with_file(){
    if(fopen(file".inp","r")){
        freopen(file".inp","r", stdin);
        freopen(file".out", "w", stdout);
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
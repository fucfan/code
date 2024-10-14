#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int , int>
#define pip pair<ll, pii>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "spath"
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 1e4 + 5;
const int LOG = 20;

int n , m , p , l , k , vst[N];
bool vst1[N];
vector <pii> adj[N] , new_adj[N];
ll d[N][30];
int dist[N];

void bfs(int i){
    // cout << i << ": ";
    // mem(dist , 0);
    dist[i] = 0;
    vst[i] = i;

    queue <int> q;
    q.push(i);

    while(q.size()){
        int u = q.front();
        // cout << u << '/' << vst[u] << ' ';
        q.pop();
        for(auto it : adj[u]){
            int v = it.fi;
            if(vst[v] == i || vst1[v]) continue;
            dist[v] = dist[u] + 1;
            if(dist[v] <= l){
                // cout << v << ' ';
                new_adj[i].pb({v , p});
                new_adj[v].pb({i , p});
                q.push(v);
            }
            vst[v] = i;
        }
    }
    // cout << "gg";
    // nl;
}

void dijsktra(){
    mem(d , 0x3f);
    d[1][0] = 0;
    priority_queue <pip , vector<pip> , greater<pip>> q;
    q.push({d[1][0] , {1 , 0}});
    while(q.size()){
        pii u = q.top().se;
        ll dis = q.top().fi;

        q.pop();

        if(dis > d[u.fi][u.se]) continue;

        for(auto it : adj[u.fi]){
            pii v = {it.fi , u.se};
            ll w = it.se;
            if(d[v.fi][v.se] > d[u.fi][u.se] + w){
                d[v.fi][v.se] = d[u.fi][u.se] + w;
                q.push({d[v.fi][v.se] , v});
            }
        }

        if(u.se < k){
            // cout << u.fi << '\n';
            for(auto it : new_adj[u.fi]){
                // cout << it.fi << ' ';
                pii v = {it.fi , u.se + 1};
                ll w = it.se;
                if(d[v.fi][v.se] > d[u.fi][u.se] + w){
                    d[v.fi][v.se] = d[u.fi][u.se] + w;
                    q.push({d[v.fi][v.se] , v});
                }
            }
            // nl;
        }
    }

    ll ans = oo; 

    for(int i = 0 ; i <= k ; i++) ans = min(ans , d[n][i]);

    cout << ans;
}

void inp(){
    cin >> n >> m >> p >> l >> k;
    for(int i = 1 ; i <= m ; i++){
        int u , v , t;
        cin >> u >> v >> t;
        adj[u].pb({v , t});
        adj[v].pb({u , t});
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        bfs(i);
        vst1[i] = 1;
    }
    dijsktra();
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
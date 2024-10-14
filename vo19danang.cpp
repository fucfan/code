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
#define ppi pair <ll , pii>
using namespace std;

const ll oo = 1e18 + 7;
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

int n , m , D;
vector <ppi> adj[N];
vector <ll> d[N];

struct Edge{
    int u , v , w;

    bool operator<(Edge b){
        return w < b.w;
    }

    void input(){
        cin >> u >> v >> w;
    }
} edge[N];

void dijkstra(){
    for(int i = 1 ; i <= n ; i++){
        for(auto j : adj[i]){
            d[i].pb(oo);
        }
    }

    priority_queue<ppi , vector<ppi> , greater<ppi>> q;

    for(auto it : adj[1]){
        q.push({it.se.fi , {it.fi , it.se.se}});
        d[it.fi][it.se.se] = it.se.fi;
    }

    for(auto &j : d[1]) j = 0;

    while(q.size()){
        pii u = q.top().se;
        ll dis = q.top().fi;

        q.pop();

        if(dis > d[u.fi][u.se]) continue;

        // cout << u.fi << ' ' << adj[u.fi][u.se].se.fi << ' ' << dis << '\n';

        for(auto it : adj[u.fi]){
            pii v = {it.fi , it.se.se};
            int w = it.se.fi;

            if(w - adj[u.fi][u.se].se.fi >= D && d[u.fi][u.se] + w < d[v.fi][v.se]){
                d[v.fi][v.se] = d[u.fi][u.se] + w;
                for(int j = v.se + 1 ; j < (int)d[v.fi].size() ; j++) d[v.fi][j] = min(d[v.fi][j] , d[v.fi][v.se]);
                q.push({d[v.fi][v.se] , {v.fi , v.se}});
            }

            // cout << u.fi << ' ' << v.fi << ' ' << d[v.fi][v.se] << ' ' << w << "gg\n";
        }
    }

    ll ans = oo;

    for(auto j : d[n]){
        ans = min(ans , j);
    }

    cout << (ans == oo ? -1 : ans);
}

void inp(){
    cin >> n >> m >> D;
    for(int i = 1 ; i <= m ; i++){
        edge[i].input();
    }
}

void solve(){
    sort(edge + 1 , edge + 1 + m);
    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        u = edge[i].u;
        v = edge[i].v;
        w = edge[i].w;
        adj[u].pb({v , {w , adj[v].size()}});
        adj[v].pb({u , {w , adj[u].size() - 1}});
    }
    dijkstra();
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
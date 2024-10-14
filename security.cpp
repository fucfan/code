#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<ll , ll>
#define pb push_back

const int N = 2e3 + 5;
const int LOG = 20;
using namespace std;

int n , m , adj1[N][N] , par[N] , ans[N];
bool vst[N];
vector<int> adj[N];

void bfs(int s , int t){
    memset(vst , 0 , sizeof(vst));
    memset(par , 0 , sizeof(par));
    queue <int> q;
    vst[s] = 1;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!adj1[u][v] || vst[v]) continue;
            vst[v] = 1;
            par[v] = u;
            q.push(v);
        }
    }
    int u = t;
    while(par[u]){
        adj1[u][par[u]]--;
        adj1[par[u]][u]--;
        ans[u] = 1;
        u = par[u];
    }
}

int main(){
    freopen("security.inp" , "r" , stdin);
    freopen("security.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        adj1[u][v]++;
        adj1[v][u]++;
    }
    bfs(1 , n);
    bfs(n , 1);
    int res = 0;
    for(int i = 1 ; i <= n ; i++) res += ans[i];
    cout << res;
}

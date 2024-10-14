#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
int n , m , par[N] , cnt[N] , ans;
ll d[2][N];
vector <pii> adj[N];
queue <int> path;
bool vst[N];
void djsktra(int s , int type){
    priority_queue <pii , vector <pii> , greater <pii>> q;
    q.push({0 , s});
    d[type][s] = 0;
    while(!q.empty()){
        ll dis = q.top().fi;
        int u = q.top().se;
        q.pop();
        if(dis > d[type][u]) continue;
        for(auto it : adj[u]){
            int v = it.fi;
            ll w = it.se;
            if(d[type][u] + w < d[type][v]){
                d[type][v] = d[type][u] + w;
                q.push({d[type][v] , v});
                if(type == 0)par[v] = u;
            }
        }
    }
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int a , b , c;
        cin >> a >> b >> c;
        adj[a].pb({b , c});
        adj[b].pb({a , c});
    }
}

void solve()
{
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 1 ; j <= n ; j++){
            d[i][j] = oo;
        }
    }
    djsktra(1 , 0);
    djsktra(n , 1);
    path.push(1);
    while(!path.empty()){
        int u = path.front();
        path.pop();
        int check = false;
        if(path.size() == 0) check = true;
        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            if(d[1][v] + d[0][u] + w == d[0][n] && !vst[v]){
                path.push(v);
                vst[v] = true;
            }
        }
        if(path.size() == 1 && check){
            ans++;
        }
    }
    cout << ans;
}

void run_with_file()
{
//    if(fopen(file".inp","r")){
//        freopen(file".inp","r", stdin);
//        freopen(file".out", "w", stdout);
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , m , par[N] , sz[N] , mst , cnt[N];
ll ans;
pii up[N][20];
pair <int , pii> edge[N];
bool check[N];
vector <pii> adj[N];
void make_set(){
    for(int i = 1 ; i <= n ; i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int get(int a){
    if(a == par[a]) return a;
    return get(par[a]);
}
void uni(int a , int b){
    a = get(a);
    b = get(b);
    if(sz[a] > sz[b]) swap(a , b);
    par[a] = b;
    sz[b] += sz[a];
}
void dfs(int i , int pre){
    for(auto j : adj[i]){
        if(j.fi != pre){
            cnt[j.fi] = cnt[i] + 1;
            up[j.fi][0] = {i , j.se};
            dfs(j.fi , i);
        }
    }
}
void set_up(){
    for(int i = 1 ; i <= 17 ; i++){
        for(int j = 1 ; j <= n ; j++){
            up[j][i].se = min(up[j][i - 1].se , up[up[j][i - 1].fi][i - 1].se);
            up[j][i].fi = up[up[j][i - 1].fi][i - 1].fi;
        }
    }
}
pii ancestor_k(int u , int k){
    int val = up[u][0].se;
    for(int j = 0 ; (1 << j) <= k ; j++){
        if(k >> j & 1){
            val = min(val , up[u][j].se);
            u = up[u][j].fi;
        }
    }
    return {u , val};
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        cin >> edge[i].se.fi >> edge[i].se.se >> edge[i].fi;
    }
    sort(edge + 1 , edge + 1 + m);
    reverse(edge + 1 , edge + 1 + m);
}

void solve()
{
    make_set();
    for(int i = 1 ; i <= m ; i++){
        int u = edge[i].se.fi;
        int v = edge[i].se.se;
        int w = edge[i].fi;
        if(get(u) != get(v)){
            check[i] = true;
            uni(u , v);
            mst += w;
            adj[u].pb({v , w});
            adj[v].pb({u , w});
        }
    }
    dfs(1 , 0);
    set_up();
    for(int i = 1 ; i <= m ; i++){
        if(!check[i]){
            int u = edge[i].se.fi;
            int v = edge[i].se.se;
            int w = edge[i].fi;
            if(cnt[u] > cnt[v]) swap(u , v);
            pii anc = ancestor_k(v , cnt[v] - cnt[u]);
            v = anc.fi;
            int val = anc.se;
            while(u != v){
                val = min(val , min(up[u][0].se , up[v][0].se));
                u = up[u][0].fi;
                v = up[v][0].fi;
            }
            if(val > w){
                ans += val - w;
            }
        }
    }
    cout << ans;
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
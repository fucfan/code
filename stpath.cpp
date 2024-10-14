#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "stpath"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

struct Edge{
    int u , v , w;
} edge[N];

int n , m , q;
int h[N] , par[N][LOG + 5] , sz[N] , par_dsu[N];
bool used[N];
ll d[50][N] , dis_lca[N];
vector <pii> adj[N];
vector <int> spe_node;

bool cmp(Edge a , Edge b){
    return a.w < b.w;
}

void make_set(){
    for(int i = 1 ; i <= n ; i++){
        par_dsu[i] = i;
        sz[i] = 1;
    }
}

int get(int a){
    return (a == par_dsu[a] ? a : get(par_dsu[a]));
}

bool uni(int a , int b){
    a = get(a);
    b = get(b);
    if(a == b) return 0;

    if(sz[a] > sz[b]) swap(a , b);
    par_dsu[a] = b;
    sz[b] += sz[a];

    return 1;
}

void dfs(int i , int p){
    for(auto it : adj[i]){
        int j = it.fi;
        ll w = it.se;
        if(j == p) continue;

        h[j] = h[i] + 1;
        dis_lca[j] = dis_lca[i] + w;
        par[j][0] = i;

        dfs(j , i);
    }
}

int lca(int u , int v){
    if(h[u] > h[v]) swap(u , v);
    for(int i = LOG ; i >= 0 ; i--){
        if(h[par[v][i]] >= h[u]) v = par[v][i];
    }

    if(u == v) return u;

    for(int i = LOG ; i >= 0 ; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

void dijsktra(int s){
    d[s][spe_node[s - 1]] = 0;
    priority_queue <pii , vector<pii> , greater<pii>> q;

    q.push({0 , spe_node[s - 1]});
    while(q.size()){
        int u = q.top().se;
        ll dis = q.top().fi;
        // cout << s << ' ' << u << '\n';
        q.pop();

        if(dis > d[s][u]) continue;

        for(auto it : adj[u]){
            int v = it.fi;
            ll w = it.se;

            if(d[s][v] > d[s][u] + w){
                d[s][v] = d[s][u] + w;
                q.push({d[s][v] , v});
            }
        }
    }
}

void prepare(){
    make_set();
    mem(d , 0x3f);
    sort(edge + 1 , edge + 1 + m , cmp);
    for(int i = 1 ; i <= m ; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        if(uni(u , v)){
            used[i] = 1;
            adj[u].pb({v , w});
            adj[v].pb({u , w});
        }
    }
    dfs(1 , 0);
    h[0] = -1;
    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i <= n ; i++){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    for(int i = 1 ; i <= m ; i++){
        if(used[i]) continue;

        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        spe_node.pb(u);

        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
    // sort(all(spe_node));
    // spe_node.erase(unique(all(spe_node)) , spe_node.end());

    for(int j = 0 ; j < (int)spe_node.size() ; j++) dijsktra(j + 1);
}

void inp()
{
    cin >> n >> m >> q;
    for(int i = 1 ; i <= m ; i++){
        int u , v , c;
        cin >> u >> v >> c;
        edge[i] = {u , v , c};
    }
}

void solve()
{
    prepare();
    for(int i = 1 ; i <= q ; i++){
        int u , v;
        cin >> u >> v;
        ll dis1 = dis_lca[u] + dis_lca[v] - 2 * dis_lca[lca(u , v)];
        ll dis2 = oo;
        for(int j = 0 ; j < (int)spe_node.size() ; j++) dis2 = min(dis2 , d[j + 1][u] + d[j + 1][v]);
        cout << min(dis1 , dis2) << '\n';
    }
}

void run_with_file()
{
    if (fopen(file".inp", "r"))
    {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
}
main()
{
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
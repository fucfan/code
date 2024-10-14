#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
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

int n, q, cor[N];
int depth[N];
int d[N], st[N], en[N];
pii rmq[N][LOG + 5];
vector <int> adj[N];
vector <int> cur;
vector <pii> tour;

void bfs(){
    queue <int> q;
    for(auto j : cur) q.push(j), d[j] = 0;
    cur.clear();
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] <= d[u] + 1) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void dfs(int i, int p){
    depth[i] = depth[p] + 1;
    st[i] = tour.size();
    tour.pb({depth[i], i});
    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j, i);
        tour.pb({depth[i], i});
    }
    en[i] = (int)tour.size() - 1;
}


void prepare(){
    depth[0] = -1;
    dfs(1, 0);
    // for(auto j : tour) cout << j.se << ' ';
    // nl;
    for(int i = 0; i < (int)tour.size(); i++){
        rmq[i][0] = tour[i];
    }
    for(int j = 1; j <= LOG; j++){
        for(int i = 0; i + (1 << (j - 1)) < (int)tour.size(); i++){
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
}

pii get(int l, int r){
    int length = 31 - __builtin_clz(r - l + 1);
    // cout << l << ' ' << r << ' ' << length << '\n';
    // return {1, 1};
    return min(rmq[l][length], rmq[r - (1 << length) + 1][length]);
}

void inp(){
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    prepare();
    mem(d, 0x3f);
    d[1] = 0;
    cur.pb(1);
    int cnt = 1;
    for(int i = 1; i <= q; i++){
        int type, node;
        cin >> type >> node;
        if(type == 1){
            cor[node] = 1;
            d[node] = 0;
            cnt++;
            if(cnt > sqrt(n)){
                bfs();
                cnt = 1;
            }
            cur.pb(node);
        }
        else{
            int ans = d[node];
            // cout << node << ' ' << d[node] << "gg\n";
            for(auto j : cur){
                int lca = get(min(st[node], st[j]), max(st[node], st[j])).se;
                // cout << j << ' ' << node << ' ' << lca << "gg\n";
                ans = min(ans, depth[node] + depth[j] - 2 * depth[lca]);
            }
            cout << ans << '\n';
        }
    }
    // cout << 1;
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
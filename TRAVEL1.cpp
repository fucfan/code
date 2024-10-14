#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "travel"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , m , k , low[N] , num[N] , d , scc , comp[N] , st , val[N] , cnt_node[N] , val1[N] , ans;
vector <pii> adj[N] , big_adj[N];
stack <int> node;
bool vst[N];

void dfs(int i){
    num[i] = low[i] = ++d;
    node.push(i);
    for(auto it : adj[i]){
        int j = it.fi;
        if(it.se) continue;
        if(vst[j]) continue;
        if(!num[j]){
            dfs(j);
            low[i] = min(low[i] , low[j]);
        }
        else low[i] = min(low[i] , num[j]);
    }
    if(low[i] == num[i]){
        // cout << i << "gg\n";
        scc++;
        // cout << scc << ": ";
        while(node.size()){
            int u = node.top();
            // cout << u << ' ';
            node.pop();
            comp[u] = scc;
            cnt_node[scc]++;

            for(auto it : adj[u]){
                if(it.se) continue;
                int v = it.fi;
                // if(comp[u] != comp[v]) 
                // if(comp[u] == 2) cout << u << ' ' << v << ' ' << comp[v] << ' ' << comp[u] << ' ' << scc << ' ' << it.se << '\n';
                if(comp[u] != comp[v] && comp[v]) big_adj[scc].pb({comp[v] , it.se});
                if(comp[u] != comp[v] && comp[v]) big_adj[comp[v]].pb({scc , 1});
            }

            vst[u] = 1;
            if(u == 1) st = scc;

            if(u == i) break;
        }
        // nl;
    }
}

void dijsktra(int s){
    mem(val , -0x3f);
    priority_queue <pii> q;
    val[s] = cnt_node[s];
    q.push({val[s] , s});
    while(q.size()){
        int u = q.top().se;
        int dis = q.top().fi;
        q.pop();
        if(dis < val[u]) continue;
        for(auto it : big_adj[u]){
            if(!it.se) continue;
            int v = it.fi;
            if(val[v] < val[u] + cnt_node[v]){
                val[v] = val[u] + cnt_node[v];
                q.push({val[v] , v});
            }
        }
    }
}

void dijsktra1(int s){
    mem(val1 , -0x3f);
    priority_queue <pii> q;
    val1[s] = cnt_node[s];
    q.push({val1[s] , s});
    while(q.size()){
        int u = q.top().se;
        int dis = q.top().fi;
        q.pop();
        if(dis < val1[u]) continue;
        for(auto it : big_adj[u]){
            if(it.se) continue;
            int v = it.fi;
            if(val1[v] < val1[u] + cnt_node[v]){
                val1[v] = val1[u] + cnt_node[v];
                q.push({val1[v] , v});
            }
        }
    }
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb({v , 0});
        adj[v].pb({u , 1});
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        if(!num[i]) dfs(i);
        // nl;
    }

    // for(int i = 1 ; i <= n ; i++) cout << i << ' ' << comp[i] << '\n';
    if(!k) cout << cnt_node[st];
    else{
        dijsktra(st);
        dijsktra1(st);

        for(int i = 1 ; i <= scc ; i++){
            for(auto j : big_adj[i]){
                if(j.se == 0) ans = max(ans , val[i] + val1[j.fi]);
                else ans = max(ans , val1[i] + val[i]);
            }
        }
        cout << ans - cnt_node[st];
    }
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
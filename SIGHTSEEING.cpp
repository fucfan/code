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
#define file "sightseeing"
using namespace std;

const int oo = 1e9;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , m , k , q;
vector <int> d[N];
vector <pii> adj[N];

void dijsktra(){
    // for(int i = 2 ; i <= n ; i++){
    //     // d[i].pb(oo);
    //     for(int j = 1 ; j <= k + 1 ; j++) d[i].pb(-oo);
    // }
    for(int i = 1 ; i <= k + 1 ; i++) d[1].pb(oo);
    priority_queue <pair <vector<int> , int>> q;
    q.push({d[1] , 1});
    while(q.size()){
        int u = q.top().se;
        vector <int> dis = q.top().fi;
        q.pop();
        if(dis < d[u]) continue;
        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            vector <int> tmp = d[u];
            tmp.pb(w);
            sort(all(tmp));
            tmp.pop_back();
            sort(all(tmp));
            reverse(all(tmp));
            if(d[v] < tmp){
                d[v] = tmp;
                q.push({d[v] , v});
            }
        }
    }
}

void inp(){
    cin >> n >> m >> k >> q;
    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
}

void solve(){
    dijsktra();

    for(int i = 1 ; i <= q ; i++){
        int node;
        cin >> node;
        cout << d[node][0] << '\n';
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
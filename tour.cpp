#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<ll, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "tour"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
#define pip pair <ll , pii>
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , m , k , p[N];
vector <pii> adj[N];
ll d[N][N];
ll dp[N][(1 << 15) + 5];

void dijkstra(int s){
    priority_queue <pii , vector <pii> , greater<pii>> q;

    mem(d[s] , 0x3f);

    q.push({0 , s});
    
    d[s][s] = 0;

    while(q.size()){
        int u = q.top().se;
        ll dis = q.top().fi;

        q.pop();

        if(dis != d[s][u]) continue;

        // cout << u.fi << ' ' << u.se << '\n';

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

ll sol(int i , int mask){
    if(mask == (1 << k) - 1) return d[i][1];
    ll res = oo;
    if(dp[i][mask] != -1) return dp[i][mask];
    for(int j = 1 ; j <= k ; j++){
        if(BIT(mask , j - 1) || d[i][p[j]] > oo) continue;
        res = min(res , sol(p[j] , mask ^ (1 << (j - 1))) + d[i][p[j]]);
    }
    return dp[i][mask] = res;
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= k ; i++){
        cin >> p[i];
    }
    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
    }
}

void solve(){
    dijkstra(1);
    for(int i = 1 ; i <= k ; i++) dijkstra(p[i]);
    mem(dp , -1);
    ll ans = sol(1 , 0);

    cout << (ans < oo ? ans : -1);
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

// #include<bits/stdc++.h>
// #define fi first
// #define se second
// #define ull unsigned long long
// #define ll long long
// #define BIT(a , b) ((a >> b) & 1)
// #define flip(a , b) ((a) ^ (1 << (b)))
// #define pii pair<int, int>
// #define pb push_back
// #define nl cout << "\n";
// #define __ <<" "<<
// #define mem(a, b) memset((a), (b), sizeof((a)))
// #define all(c) (c).begin(), (c).end()
// #define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
// #define file "tour"
// #define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
// #define pip pair <ll , pii>
// using namespace std;

// const ll oo = 1e18 + 7;
// const int mod = 1e9 + 7;
// const int N = 1e3 + 5;
// const int LOG = 20;
// const int base = 31;

// void run_with_file(){
//     if(fopen(file".inp" , "r")){
//         freopen(file".inp", "r" , stdin);
//         freopen(file".out", "w" , stdout);
//     }
// }

// int n , m , k , p[N];
// vector <pii> adj[N];
// ll d[N][(1 << 15) + 5];

// void dijkstra(){
//     priority_queue <pip , vector <pip> , greater<pip>> q;

//     mem(d , 0x3f);

//     q.push({0 , {1 , 0}});
    
//     d[1][0] = 0;

//     while(q.size()){
//         pii u = q.top().se;
//         ll dis = q.top().fi;

//         q.pop();

//         if(dis != d[u.fi][u.se]) continue;

//         // cout << u.fi << ' ' << u.se << '\n';

//         for(auto it : adj[u.fi]){
//             int v = it.fi;
//             ll w = it.se;

//             // cout << v << ' ' << d[v][u.se] << '\n';

//             if(p[v] && !BIT(u.se , p[v] - 1)){
//                 if(d[v][u.se ^ (1 << (p[v] - 1))] > d[u.fi][u.se] + w){
//                     d[v][u.se ^ (1 << (p[v] - 1))] = d[u.fi][u.se] + w;
//                     q.push({d[v][u.se ^ (1 << (p[v] - 1))] , {v , u.se ^ (1 << (p[v] - 1))}});
//                 }
//             }
//             else{
//                 if(d[v][u.se] > d[u.fi][u.se] + w){
//                     d[v][u.se] = d[u.fi][u.se] + w;
//                     q.push({d[v][u.se] , {v , u.se}});
//                 }
//             }
//         }
//     }

//     ll ans = oo;

//     for(int i = 2 ; i <= n ; i++){
//         for(auto it : adj[i]){
//             if(it.fi == 1){
//                 // cout << i << '\n';
//                 ans = min(ans , d[i][(1 << k) - 1] + it.se);
//             }
//         }
//     }

//     cout << (ans == oo ? -1 : ans);
// }

// void inp(){
//     cin >> n >> m >> k;
//     for(int i = 1 ; i <= k ; i++){
//         int x;
//         cin >> x;
//         p[x] = i;
//     }
//     for(int i = 1 ; i <= m ; i++){
//         int u , v , w;
//         cin >> u >> v >> w;
//         adj[u].pb({v , w});
//         // adj[v].pb({u , w});
//     }
// }

// void solve(){
//     dijkstra();
// }

// int main(){
//     cin.tie(0)->sync_with_stdio(false);
//     run_with_file();
//     int test_case = 1;
//     //cin >> test_case;
//     while(test_case--){
//         inp();
//         solve();
//     }
// }

// /*      UwU      */
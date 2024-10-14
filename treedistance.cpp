#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int sub , n , k , child[N] , dis[N] , depth[N];
ll ans;
vector <int> adj[N] , vt[N];

void pre_dfs(int i , int p){
    child[i] = 1;

    for(auto j : adj[i]){
        if(j == p) continue;
        depth[j] = depth[i] + 1;
        pre_dfs(j , i);
        child[i] += child[j];
    }
}

void dfs(int i , int p , bool keep){
    // cout << i << ' ' << p << ' ' << keep << '\n';

    int Max = -1;
    int best_node = -1;

    for(auto j : adj[i]){
        if(j == p) continue;;
        if(child[j] > Max){
            Max = child[j];
            best_node = j;
        }
    }

    for(auto j : adj[i]){
        if(j == p || j == best_node) continue;
        // cout << i << ' ' << j << "gg\n";
        dfs(j , i , 0);
    }

    if(best_node != -1) dfs(best_node , i , 1) , swap(vt[i] , vt[best_node]);
    // if(depth[i] <= 2){
    //     cout << i << ' ' << p << ' ' << keep << '\n';

    //     for(int i = 0 ; i <= n ; i++){
    //         cout << i << ' ' << dis[i] << '\n';
    //     }
    //     cout << ans;
    //     nl;
    // }

    dis[depth[i]]++;

    ans += dis[depth[i] + k];

    for(auto j : adj[i]){
        if(j == best_node || j == p) continue;

        for(auto f : vt[j]){
            if(k - depth[f] + depth[i] + depth[i] < 0) continue;
            ans += dis[k - depth[f] + depth[i] + depth[i]];
            // cout << depth[f] << ' ' << depth[i] << ' ' << k - depth[f] + depth[i] + depth[i] << ' ' << dis[k - depth[f] + depth[i] + depth[i]] << "gg\n";
        }

        for(auto f : vt[j]){
            vt[i].pb(f);
            dis[depth[f]]++;
        }
    }

    vt[i].pb(i);

    // ans += dis[depth[i] + k];

    // if(depth[i] <= 2){
    //     cout << i << ' ' << p << ' ' << keep << '\n';

    //     for(int i = 0 ; i <= n ; i++){
    //         cout << i << ' ' << dis[i] << '\n';
    //     }
    //     cout << ans;
    //     nl;
    // }

    if(!keep){
        for(auto j : vt[i]){
            dis[depth[j]]--;
        }
    }
//     else{
//         for(auto j : vt[i]){
//             dis[depth[j] - depth[i]]--;
//             dis[depth[j] - depth[i] + 1]++;
//         }
//     }
}

void inp(){
    cin >> sub;
    cin >> n >> k;
    for(int i = 1 ; i < n ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }    
}

void solve(){
    pre_dfs(1 , 0);
    dfs(1 , 0 , 0);
    cout << ans;
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
    inp();
    solve();
}

/*      UMU      */
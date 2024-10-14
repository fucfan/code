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
#define file "tree"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
const int LOG = 20;

int n , p , depth[N];
ll dp[N][50] , dp1[N] , nxt_dp[50];
vector <int> adj[N];

void dfs(int i , int par){
    dp[i][0] = 1;
    for(auto j : adj[i]){
        if(j == par) continue;
        depth[j] = depth[i] + 1;
        dfs(j , i);
        for(int f = 0 ; f < p ; f++){
            dp[i][f] += dp[j][(f - 1 + p) % p];
        }
    }
}

void dfs1(int i , int par){
    // cout << i << ": ";
    // for(int j = 0 ; j < p ; j++) cout << dp[i][j] << ' ';
    // nl;
    for(auto j : adj[i]){
        if(j == par) continue;
        dp1[j] += dp[j][0] + dp[i][p - 1];
        for(int f = 0 ; f < p ; f++){
            nxt_dp[f] += dp[i][(f - 1 + p)% p] - dp[j][(f - 2 + p) % p];
        }
        for(int f = 0 ; f < p ; f++){
            dp[j][f] += nxt_dp[f];
            nxt_dp[f] = 0;
        }
        dfs1(j , i);
    }
}

void inp(){
    cin >> n >> p;
    for(int i = 2 ; i <= n ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    dfs(1 , 0);
    dfs1(1 , 0);
    // for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) cout << dp[j][0] << ' ';
        // nl;
    // }
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
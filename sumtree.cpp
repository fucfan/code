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
#define file "sumtree"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , par[N] , t;
ll  dp2[N] , dp[N] , dp1[N] ;
vector <pii> adj[N];
void dfs(int i , int p){
    for(auto j : adj[i]){
        if(j.fi == p) continue;
        par[j.fi] = i;
        dfs(j.fi , i);
        dp[i] += dp[j.fi] + j.se * (dp1[j.fi]);
        dp1[i] += dp1[j.fi];    
    }
    dp1[i]++;
}
void dfs1(int i , int p){
    for(auto j : adj[i]){
        if(j.fi == p) continue;
        dp2[j.fi] = (dp2[i] - dp[j.fi] - (j.se * dp1[j.fi])) + j.se * (n - dp1[j.fi]) + dp[j.fi];
        dfs1(j.fi , i);
    }
}
void inp()
{
    cin >> t;
    for(int g = 1 ; g <= t ; g++){
        cin >> n;
        mem(dp , 0);
        mem(dp1 , 0);
        mem(dp2 , 0);
        for(int i = 1 ; i < n ; i++){
            int a , b , c;
            cin >> a >> b >> c;
            adj[a].pb({b , c});
            adj[b].pb({a , c});
        }
        dfs(1 , 0); 
        dp2[1] = dp[1];
        dfs1(1 , 0);
        for(int i = 1 ; i <= n ; i++) cout << dp2[i] << '\n';
        for(int i = 1 ; i <= n ; i++) adj[i].clear();
    }
}

void solve()
{
    
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
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UwU      */
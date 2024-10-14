#include <bits/stdc++.h>
#define ll long long
#define name "steal"
#define fi first
#define se second
#define pii pair<int , int>
#define pb push_back

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

using namespace std;

int n , k;
pair <int , pii> dp[N];
vector <int> adj[N];

void dfs(int i , int p){
    dp[i].se = {oo , oo};
    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j , i);
        if(dp[j].se.fi + 1 >= dp[j].se.se){
            dp[i].fi++;
        }
        else{
            dp[i].fi += dp[j].fi;
        }
            dp[i].se.fi = min(dp[i].se.fi , dp[j].se.fi + 1);
            dp[i].se.se = min(dp[i].se.se , dp[j].se.se);
    }
    if(adj[i].size() == 1){
        dp[i].se = {0 , 0};
        dp[i].fi = 1;
    }
    if(dp[i].fi > 1 && adj[i].size() > 2){
        for(auto j : adj[i]){
            dp[i].se.se = min(dp[i].se.se , )
        }
        dp[i].se.fi = 0;
    }
}

int main(){
    freopen(name".inp" , "r" , stdin);
    freopen(name".out" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(k , 0);
    cout << dp[k].fi;
}

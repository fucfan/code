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
#define file "test"
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , k , st;
vector <int> adj[N];
ll dp[N][150] , dp1[N];

void dfs(int i , int p){
    if(adj[i].size() == 1)dp[i][0] = 1;
    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j , i);
        for(int f = 1 ; f <= k ; f++){
            dp[i][f] += dp[j][f - 1];
        }
        dp1[i] += dp1[j];
    }
    int max1 = 0;
    int max2 = 0;
    for(int j = 1 ; j <= k ; j++){
        if(dp[i][j] == 1){
            max2 = max1;
            max1 = j;
        }
        else if(dp[i][j] > 1){
            max1 = j;
            max2 = j;
        }
    }
    cout << i << ' ' << max1 << ' ' << max2 << ' ' << dp1[i] << "gg\n";
    for(int j = 0 ; j <= k ; j++) cout << dp[i][j] << ' ';
    cout << '\n';
    if(dp1[i]){
        if(max1 + max2 >= k){
            if(!max2){
                dp1[i]++;
                memset(dp[i] , 0 , sizeof(dp[i]));
                dp[i][0] = 1;
            }
            else if(max1 + max2 > k){
                dp1[i]++;
                memset(dp[i] , 0 , sizeof(dp[i]));
                dp[i][0] = 1;
            }
        }
    }
    else{
        if(max1 + max2 >= k){
            dp1[i]++;
            memset(dp[i] , 0 , sizeof(dp[i]));
            dp[i][0] = 1;
        }
    }
}

void inp()
{
    cin >> n >> k;
    for(int i = 1 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}

void solve()
{
    if(k <= 1){
        cout << n;
        exit(0);
    }
    dfs(1 , 0);
    cout << dp1[1];
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

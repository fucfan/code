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
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , dp1[N] , dp2[N];
vector <int> adj[N];
void dfs(int i , int p){
    ll res1 = 0;
    ll res2 = 0;
    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j , i);
        res2 += dp1[j];
    }
    res1 = res2;
    bool check = false;
    for(auto j : adj[i]){
        if(j == p) continue;
        if(res1 < res2 - dp1[j] + (dp2[j] + 1)){
            res1 = max(res1 , res2 - dp1[j] + (dp2[j] + 1));
            check = true;
        }
    }
    dp1[i] = res1;
    dp2[i] = res2;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}

void solve()
{
    dfs(1 , 0);
    // for(int i = 1 ; i <= n ; i++){
    //     cout << dp1[i] << ' ' << dp2[i] << '\n';
    // }
    cout << max(dp1[1] , dp2[1]);
}

void run_with_file()
{
//    if(fopen(file".inp","r")){
//        freopen(file".inp","r", stdin);
//        freopen(file".out", "w", stdout);
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
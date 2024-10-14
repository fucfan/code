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
int n , k , r , w[N] , u , v , res;
vector <int> adj[N] , ans;
ll DFS(int i , int par){
    ll sum = w[i];
    for(auto j : adj[i]){
        if(j != par){
            sum =sum + DFS(j , i);
        }
    }
    return sum;
}
void inp()
{
    cin >> n >> k >> r;
    for(int i = 1 ; i <= n ; i++){
        cin >> w[i];
    }
    for(int i = 1 ; i <= n - 1 ; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        ans.pb(DFS(i , 0));
    }
    sort(all(ans));
    reverse(ans.begin() , ans.end());
    for(int i = 0 ; i < k; i++){
        res = res + ans[i];
    }
    cout << res;
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
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
int n , k , child[N] , cnt;
vector <int> adj[N];
void dfs(int i , int p){
    ll res = 1;
    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j , i);
        res += child[j];
    }
    if(res >= k){
        // cout << i << '\n';
        cnt++;
        child[i] = 0;
        return;
    }
    child[i] = res;
}
void inp()
{
    cin >> k >> n;
    for(int i = 2 ; i <= n ; i++){
        int a;
        cin >> a;
        adj[a].pb(i);
        adj[i].pb(a);
    }
}

void solve()
{
    dfs(1 , 0);
    cout << cnt;
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
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
#define file "phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , cor[N] , cnt;
vector <int> adj[N];
void dfs(int i , int st){
    cor[i] = 1;
    for(auto j : adj[i]){
        if((cor[j] == 1 && j != st) || cor[j] == 2){
            // cout << j << ' ' << st << '\n';
            cout << -1;
            exit(0);
        }
        if(!cor[j])dfs(j , st);
    }
    cor[i] = 2;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int a;
        cin >> a;
        adj[i].pb(a);
    }
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        if(cor[i] != 2){
            dfs(i , i);
            cnt++;
        }
    }
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
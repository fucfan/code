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
const int mod = 1e9;
const int N = 2e5 + 5;
int n , m , k , q;
ll dp[1005][1005];
bool ban[1005][1005];
ll sol(int x , int y){
    // cout << x << ' ' << y << '\n';
    if(x == n && y == m) return 1;
    if(x > n || y > m || x < 1 || y < 1) return 0;
    if(ban[x][y]) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    ll res = 0;
    res = (res + sol(x - 1 , y + 2) % mod) % mod;
    res = (res + sol(x + 1 , y + 2) % mod) % mod;
    res = (res + sol(x + 2 , y - 1) % mod) % mod;
    res = (res + sol(x + 2 , y + 1) % mod) % mod;
    dp[x][y] = res;
    return res;
}
void inp()
{
    cin >> n >> m >> k >> q;
    for(int i = 1 ; i <= k ; i++){
        int a , b;
        cin >> a >> b;
        ban[a][b] = 1;
    }
}

void solve()
{
    mem(dp , -1);
    for(int i = 1 ; i <= q ; i++){
        int a , b;
        cin >> a >> b;
        cout << sol(a , b) << '\n';
    }
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
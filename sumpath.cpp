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
#define file "sumpath"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 998244353;
const int N = 2207 + 5;
char a[N][N];   
ll dp[N][N] , n , m , cnt[N][N];
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
            // a[i][j] = '9';
        }
    }
}   

void solve()
{
    mem(dp , 0);
    dp[1][1] = a[1][1] - '0';
    cnt[1][1] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            int u = i - 1;
            int v = j - 1;
            int c = (a[i][j] - '0') ;
            if(u){
                dp[i][j] = ((dp[i][j] % mod) + (dp[u][j] + ((c * cnt[u][j]) % mod))) % mod;
                dp[i][j] %= mod;
                cnt[i][j] = (cnt[i][j] % mod + cnt[u][j] % mod) % mod;
                cnt[i][j] %= mod;
            }
            if(v){
                dp[i][j] = ((dp[i][j] % mod) + (dp[i][v] + ((c * cnt[i][v]) % mod))) % mod;
                dp[i][j] %= mod;
                cnt[i][j] = (cnt[i][j] % mod + cnt[i][v] % mod) % mod;
                cnt[i][j] %= mod;
            }
            if(u && v){
                dp[i][j] = ((dp[i][j] % mod) + (dp[u][v] + ((c * cnt[u][v]) % mod))) % mod;
                dp[i][j] %= mod;
                cnt[i][j] = (cnt[i][j] % mod + cnt[u][v] % mod) % mod;
                cnt[i][j] %= mod;
            }
            // cout << dp[i][j] << ' ';
        } 
        nl;
    }
    cout << dp[n][m];
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
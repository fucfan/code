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
#define file "P:\\cpp\\test"
using namespace std;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e3 + 5;
string s , t;
int n , m , dp[N][N];
void inp()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = " " + s;
    t = " " + t;
}
 
void solve()
{
    for(int i = 1 ; i <= n ; i++) dp[i][0] = i;
    for(int j = 1 ; j <= m ; j++) dp[0][j] = j;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min(min(dp[i - 1][j] , dp[i][j - 1]) , dp[i - 1][j - 1]) + 1;
            }
        }
    }
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 1 ; j <= m ; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     nl;
    // }
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
    // run_with_file();
    inp();
    solve();
}
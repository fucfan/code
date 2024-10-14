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
int n , a[N] , b[N] , trace[N];
ll dp[N];
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] >> b[i];
    }
}
 
void solve()
{   
    dp[1] = a[1];
    if(n == 1){
        cout << min(a[1] , b[1]);
        exit(0);
    }
    for(int i = 2 ; i <= n ; i++){
        dp[i] += min(dp[i - 1] + a[i] , dp[i - 2] + b[i - 1]);
        // cout << dp[i] << ' ';
    }
    cout << dp[n] << '\n';
    for(int i = 1 ; i <= n ; i++){
        if(dp[i] == dp[i + 1] - a[i + 1]){
            trace[i] = 1;
        }
        else if(dp[i] == dp[i + 2] - b[i + 1]){
            trace[i ] = 2;
            i--;
        }
    }
    for(int i = 1 ; i <= n ; i++) cout << trace[i] << ' ';
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
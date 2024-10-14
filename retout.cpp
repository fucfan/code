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
#define file "retout"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
ll n , Max , m , a[N] , sum , dp[5007];
ll p(ll a , ll b){
    if(b == 1) return a % mod;
    if(b == 0) return 1;
    ll t = p(a , b / 2);
    if(b % 2) return (((t * t) % mod) * (a % mod)) % mod;
    return (t * t) % mod;
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        // cin >> a[i];
        sum += a[i];
        a[i] = 1; 
        // if(i % 2) a[i] = i;
        // else a[i] = i - 1; 
        // cout << a[i] << '\n';
        Max = max(Max , a[i]);   
    }
    // cout << Max;
    if(Max == 1){
        ll num = 1;
        for(ll i = (m - 1) - (n - 1) + 1 ; i <= m - 1 ; i++){
            // cout << i << '\n';
            num *= i % mod;
            num %= mod;
        }
        ll num1 = 1;
        for(ll i = 1 ; i < n ; i++){
            num1 *= i;
            num1 %= mod;
        }
        // cout << num << ' ' << num1 << '\n';
        cout << (num * p(num1 , mod - 2)) % mod;
        exit(0);
    }
}

void solve()
{
    sort(a + 1 , a + 1 + n);
    dp[sum] = 1;
    for(int i = sum + 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            dp[i] += dp[i - a[j]];
        }
    }
    for(int i = sum ; i <= m ; i++){
        cout << dp[i] << ' ';
    }
    cout << dp[m];
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
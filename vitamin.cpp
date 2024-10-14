#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "vitamin"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, x, a[N];
int dp[N][101];
int Max[N];

void inp(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    mem(dp, 0x3f);
    dp[a[1]][1] = 1;
    for(int i = 1; i <= x; i++){
        // dp[i][1] = oo;
        for(int j = 1; j <= n; j++){
            if(i >= a[j]){
                // cout << i << ' ' << a[j] << '\n';
                dp[i][1] = min(dp[i - a[1]][j] + 2, dp[i][1]);
            }
        }
            // cout << i << ' ' << 1 << ' ' << dp[i][1] << '\n';
        for(int j = 2; j <= n; j++){
            // dp[i][j] = oo;
            if(i >= a[j])
            dp[i][j] = min(dp[i - a[j]][j - 1] + 1, dp[i][j]);
            // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }

        if(i >= a[n])
            dp[i][n] = min(dp[i - a[n]][n] + 1, dp[i][n]);
    }

    int ans = oo;

    for(int i = 1; i <= n; i++){
        ans = min(ans, dp[x][i]);
    }
    
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
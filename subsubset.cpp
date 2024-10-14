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
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 998244353;
const int N = 3e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , m , a[N];
int dp[3000][6000][3];

void inp(){ 
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
}

void solve(){
    dp[1][0][0] = 1;
    dp[1][0][2] = 1;
    if(a[1] <= m) dp[1][a[1]][1] = 1;
    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            dp[i][j][2] = add(dp[i - 1][j][2] , dp[i - 1][j][1]);
            dp[i][j][2] = add(dp[i][j][2] , dp[i - 1][j][0]);
            dp[i][j][2] = add(dp[i][j][2] , dp[i - 1][j][2]);
            if(j >= a[i]){
                dp[i][j][1] = add(dp[i][j][1] , dp[i - 1][j - a[i]][0]);
                dp[i][j][1] = add(dp[i][j][1] , dp[i - 1][j - a[i]][1]);
                dp[i][j][2] = add(dp[i][j][2] , dp[i - 1][j - a[i]][2]);
            }
        }
    }

    int ans = 0;

    for(int i = 0 ; i <= m ; i++) ans = add(ans , dp[n][i][2]);
    // cout << Pow(2 , n) << '\n';

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
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , a[N];
int dp[N][N];
ll pref[N];

void prepare(){
    for(int i = 1 ; i <= n ; i++){
        pref[i] = pref[i - 1] + a[i];
    }
}

ll get(int l , int r){
    return pref[r] - pref[l - 1];
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){
    mem(dp , -0x3f);
    prepare();
    // dp[0][0] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j >= 1 ; j--){
            if(j == 1){
                dp[i][j] = 1;
            // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
                continue;
            }
            for(int k = j - 1 ; k >= 1 ; k--){
                if(get(k , j - 1) <= get(j , i)){
                    dp[i][j] = max(dp[i][j] , dp[j - 1][k] + 1);
                }
            }
            // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }

    int ans = 0;

    for(int i = 1 ; i <= n ; i++){
        ans = max(ans , dp[n][i]);
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
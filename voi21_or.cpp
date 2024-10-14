#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
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
const int N = 2e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , a[N] , l , r , k;
int frac[N];
int finv[N];


ll Pow(ll a , ll b){
    b--;
    a %= mod;
    ll tmp = a;
    while(b){
        if(b & 1) (a *= tmp) %= mod;
        (tmp *= tmp) %= mod;
        b >>= 1;
    }
    return a;
}

void prepare(){
    frac[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        frac[i] = (1ll * frac[i - 1] * i) % mod;
    }
    finv[n] = Pow(frac[n] , mod - 2);
    for(int i = n ; i >= 1 ; i--){
        finv[i - 1] = (1ll * finv[i] * i) % mod;
    }
}

ll nCk(int n , int k){
    if(n < k) return 0;
    return (1ll * frac[n] * (1ll * finv[k] * finv[n - k] % mod)) % mod;
}

namespace sub2{
    ll dp[301][301][301];

    bool check(){
        for(int i = 1 ; i <= n ; i++) if(a[i] > 200) return 0;
        return (n <= 200);
    }

    ll sol(int i , int cnt , int val){
        if(i > n){
            // if(cnt == k && l <= val && val <= r) cout << chosen << '\n';
            return (cnt == k && l <= val && val <= r && (val % 3 == 0));
        }

        if(dp[i][cnt][val] != -1) return dp[i][cnt][val];

        ll res = 0;
        ll value = 0;

        if(cnt < k){
            value = sol(i + 1 , cnt + 1 , val | a[i]);
            res = add(res , value);
        }

        value = sol(i + 1 , cnt , val);
        res = add(res , value);

        return dp[i][cnt][val] = res;
    }

    void solve(){
        mem(dp , -1);
        cout << sol(1 , 0 , 0);
    }
}

namespace sub4{
    int dp[23][N] , dp1[23][N];
    ll val[N];

    bool check(){
        return 1;
    }

    void build(){
        for(int i = l ; i <= r ; i++){
            if(i % 3) continue;
            if(__builtin_popcount(i) & 1){
                dp1[0][i]++;
            }
        }

        for(int i = 1 ; i <= LOG ; i++){
            for(int mask = 0 ; mask < (1 << LOG) ; mask++){
                dp1[i][mask] = dp1[i - 1][mask];
                if(!BIT(mask , i - 1))
                    dp1[i][mask] += dp1[i - 1][mask ^ (1 << (i - 1))];
            }
        }

        for(int i = 0 ; i <= r ; i++){
            if(__builtin_popcount(i) & 1)
                (val[i] += (nCk(dp[LOG][i] , k) * dp1[LOG][i]) % mod) %= mod; 
            else{
                val[i] = (((val[i] - (nCk(dp[LOG][i] , k) * dp1[LOG][i]) % mod) + mod) % mod);
            }
        }

        mem(dp1 , 0);

        for(int i = l ; i <= r ; i++){
            if(i % 3) continue;
            if(!(__builtin_popcount(i) & 1)){
                // cout << i << '\n';
                dp1[0][i]++;
            }
        }

        for(int i = 1 ; i <= LOG ; i++){
            for(int mask = 0 ; mask < (1 << LOG) ; mask++){
                dp1[i][mask] = dp1[i - 1][mask];
                if(!BIT(mask , i - 1))
                    dp1[i][mask] += dp1[i - 1][mask ^ (1 << (i - 1))];
            }
        }
        
        // for(int i = 1 ; i <= 16 ; i++) cout << dp1[LOG][i] << '\n';

        for(int i = 0 ; i <= r ; i++){
            if(!(__builtin_popcount(i) & 1))
                (val[i] +=( nCk(dp[LOG][i] , k) * dp1[LOG][i]) % mod) %= mod; 
            else{
                val[i] = (((val[i] - (nCk(dp[LOG][i] , k) * dp1[LOG][i]) % mod) + mod) % mod);
            }
        }
    }

    void solve(){
        prepare();

        for(int i = 1 ; i <= n ; i++){
            dp[0][a[i]]++;
        }

        for(int i = 1 ; i <= LOG ; i++){
            for(int mask = 0 ; mask < (1 << LOG) ; mask++){
                dp[i][mask] = dp[i - 1][mask];
                if(BIT(mask , i - 1)){
                    dp[i][mask] += dp[i - 1][mask ^ (1 << (i - 1))];
                }
            }
        }  

        build();

        ll ans = 0;

        for(int i = 0 ; i <= r ; i++){
            //cout << i << ' ' << val[i] << '\n';
            ans = add(ans , val[i]);
        }

        assert(ans >= 0);

        cout << ans;
    }
}

void inp(){
    cin >> n >> k >> l >> r;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){
    //if(sub2::check()) return sub2::solve();
    if(sub4::check()) return sub4::solve();
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

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
#define file "TPCNINJA"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

ll n, mod, m, k, num_gr;

namespace sub2{
    ll dp[2001][2001];

    bool check(){
        return (n <= 1000);
    }

    void solve(){
        num_gr = n / k + (n % k != 0);
        
        dp[0][0] = 1;
            
        for(int j = 1; j <= num_gr; j++){
            for(int i = 1; i <= n; i++){
                for(int f = max(0ll, i - k); f <= i - 1; f++){
                    dp[i][j] = add(dp[i][j], dp[f][j - 1]);
                    // cout << i << ' ' << j << ' ' << f << ' ' << j - 1 << ' ' << dp[f][j - 1] << ' ' << dp[i][j] << '\n';
                }
                // cout << i << ' ' << j << ' ' << dp[i][j] << "gg\n";
            }
        }

        cout << num_gr << ' ' << dp[n][num_gr] << '\n';

        for(int j = 0; j <= num_gr; j++)
            for(int i = 0; i <= n; i++) dp[i][j] = 0;
    }  
}

namespace sub3{  
    vector<vector<ll>> nCk, val;

    bool check(){
        return (n < N);
    }

    ll mul(ll a, ll b){
        if(!b) return 0;
        b--;
        for(ll tmp = a; b > 0; b >>= 1, tmp = add(tmp, tmp)){
            if(b & 1) a = add(a, tmp);
        }
        return a;
    }

    ll Pow(ll a, ll b){
        if(!b) return 1;
        b--;
        for(ll tmp = a; b > 0; b >>= 1, tmp = mul(tmp, tmp)){
            if(b & 1) a = mul(a, tmp);
        }
        return a;
    }
    
    void prepare(int _n){
        int Max = max(n / k + (n % k != 0), k);
        int Min = min(n / k + (n % k != 0), k);
        for(int i = 0; i <= Max + 1; i++){
            val.pb(vector <ll>(Min + 2, 0));
            nCk.pb(vector <ll>(Min + 2, 0));
        }
        for(int i = 0; i <= Max; i++){
            nCk[i][0] = 1;
        }
        for(int i = 1; i <= Max; i++){
            for(int j = 1; j <= Min; j++){
                if(j > i) nCk[i][j] = 0;
                else if(i == j) nCk[i][j] = 1;
                else nCk[i][j] = add(nCk[i - 1][j - 1], nCk[i - 1][j]);
                // cout << i << ' ' << j << ' ' << nCk[i][j] << '\n';
            }
        }
    }

    void solve(){
        num_gr = n / k + (n % k != 0);
        int left = (k - (n % k)) % k;
        // cout << left << ' ' << num_gr << "hh\n";
        prepare(left);
        ll res = 0;
        for(ll i = 1; i <= left; i++){
            for(int j = 1; j <= min(num_gr - (n % k != 0), i); j++){
                val[i][j] = add(nCk[i - 1][j - 1], val[i - 1][j]);
            }
        }

        for(int i = 0; i <= min(num_gr, 1ll * left); i++){
            ll tmp = mul(val[left][i], nCk[num_gr - (n % k != 0)][i]);
            res = add(res, tmp);
        }
        cout << num_gr << ' ' << add(res, 1) << '\n';   
    }   
}

void inp(){
    cin >> n >> k >> mod;
}

void solve(){
    if(sub2::check()) return sub2::solve(), void();
    if(sub3::check()) return sub3::solve(), void();
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
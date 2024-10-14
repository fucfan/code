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
const int N = 2e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, k, h[N], cnt[N];
int fact[N], inv[N], dp[N][N];

int Pow(int a, int b){
    b--;
    for(int tmp = a; b > 0; b >>= 1, tmp = 1ll * tmp * tmp % mod){
        if(b & 1) a = 1ll * a * tmp % mod;
    }
    return a;
}

void prepare(){
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }

    inv[n] = Pow(fact[n], mod - 2);

    for(int i = n; i >= 1; i--){
        inv[i - 1] = 1ll * inv[i] * i % mod;
    }
}

int nCk(int n, int k){
    return 1ll * fact[n] * inv[n - k] % mod * inv[k] % mod;
}

void inp(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        cnt[h[i]]++;
    }
}

void solve(){
    prepare();
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(int f = 1; f <= k; f++){
            for(int j = 1; j <= i; j++){
                if(i - j <= f){
                    dp[i][f] = (dp[i][f] + 1ll * dp[j - 1][f - (i - j)] * nCk(n - j, n - i)) % mod;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0 ; i <= k; i++) res = add(res, dp[n][i]);

    for(int i = 1; i <= n; i++) res = 1ll * res * fact[cnt[i]] % mod;

    cout << res;
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

/*
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
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".ans", "w" , stdout);
    }
}

int n, k, a[N];
vector <int> vt;

void inp(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        vt.pb(i);
    }
}

void solve(){
    int ans = 0;
    sort(all(vt));
    do{
        int mx = 0;
        int cnt = 0;
        for(auto j : vt){
            // cout << j << ' ';
            if(a[j] < mx) cnt++;
            mx = max(mx, a[j]);
        }
        if(cnt <= k){
            // cout << "YES\n";
            ans++;
        }
        // else nl;
    }
    while(next_permutation(all(vt)));

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
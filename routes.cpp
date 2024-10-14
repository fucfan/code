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
#define file "routes"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int N = 1e2 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m, q, mod;
pii bl[N];
int fact[300001];
int dp[N][N][2];

int Pow(int a, int b){
    b--;
    for(int tmp = a; b > 0; b >>= 1, tmp = 1ll * tmp * tmp % mod){
        if(b & 1) a = 1ll * a * tmp % mod;
    }
    return a;
}

void prepare(){
    fact[0] = 1;

    for(int i = 1; i <= m + n; i++){ 
        fact[i] = 1ll * fact[i - 1] * i % mod;
        // cout << i << ' ' << fact[i] << '\n';
    }
    
    sort(bl + 1, bl + 1 + q);
}

int nCk(int _n, int _k){
    if(_n < 0 || _k < 0 | _n < _k) return 0;
    return 1ll * fact[_n] * Pow(1ll * fact[_k] * fact[_n - _k] % mod, mod - 2) % mod;
}

int sol(int i, int pre, int type){
    if(i > q){
        if(pre){
            int tmp = nCk(n - bl[pre].fi + m - bl[pre].se, n - bl[pre].fi);
        // cout << i << ' ' << pre << ' ' << type << ' ' << tmp << '\n';
            if(type) return mod - tmp;
            return tmp;
        }
        return 0;
    }

    if(dp[i][pre][type] != -1) return dp[i][pre][type];

    int res = 0;
    int val;
    val = sol(i + 1, pre, type);
    // cout << i << ' ' << pre << ' ' << type << ' ' << val << "gg\n";
    res = add(res, val);
    val = 1ll * sol(i + 1, i, 1 - type) 
              * nCk(bl[i].fi - bl[pre].fi + bl[i].se - bl[pre].se,
                    bl[i].fi - bl[pre].fi) % mod;
    // cout << i << ' ' << pre << ' ' << type << ' ' << val << "gg\n";
    res = add(res, val);

    return dp[i][pre][type] = res;
}

void inp(){
    cin >> n >> m >> q >> mod;
    for(int i = 1; i <= q; i++){
        cin >> bl[i].fi >> bl[i].se;
    }
}

void solve(){
    prepare();
    mem(dp, -1);
    bl[0] = {1, 1};
    int val1 = nCk(n - 1 + m - 1, n - 1);
    int val2 = sol(1, 0, 0);
    cout << add(val1, val2);
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
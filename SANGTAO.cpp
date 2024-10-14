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
#define file "sangtao"
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
        freopen(file".out", "w" , stdout);
    }
}

vector <int> adj[N];
int n, k, dp[N], dp1[N], fact[N], inv[N];

int Pow(int a, int b){
    b--;
    for(int tmp = a; b > 0; b >>= 1, tmp = 1ll * tmp * tmp % mod){
        if(b & 1) a = 1ll * a * tmp % mod;
    }
    return a;
}

void prepare(){
    fact[0] = 1;
    for(int i = 1; i <= k; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
    inv[k] = Pow(fact[k], mod - 2);

    for(int i = k; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % mod;
}

int nCk(int _n, int _k){
    return 1ll * fact[_n] * inv[_k] % mod * inv[_n - _k] % mod; 
}

void inp(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){
    	int u, v;
    	cin >> u;
    	u++;
    	v = i + 1;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
}

void solve(){
    prepare();
    int res = 0;
    for(int i = k; i >= 1; i--){
        int val = 1ll * i * Pow(i - 1, (n - 1)) % mod * nCk(k, i) % mod;
        if((i & 1) == (k & 1)) res = add(res, val);
        else res = sub(res, val);
    }
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
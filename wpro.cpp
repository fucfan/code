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
#define file "wpro"
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

ll pref[N], dp[N];
int inv_l1, phi_l2, g, inv_g;
int n, l1, l2, cost_cut, cost_uni, a[N];

int Pow(int a, int b, int mod){
    b--;
    a %= mod;
    for(int tmp = a; b > 0; b >>= 1, tmp = 1ll * tmp * tmp % mod){
        if(b & 1) a = 1ll * a * tmp % mod;
    }
    return a;
}

int phi(int num){
    int res = num;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            while(num % i == 0) num /= i;
            res -= res / i;
        }
    }
    if(num > 1) 
        res -= res / num;
    return res;
}

void prepare(){
    g = __gcd(l1, l2);

    phi_l2 = phi(l2);
    inv_l1 = Pow(l1 / g, phi_l2 - 1, l2 / g);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
    }
}

ll get(int l, int r){
    return pref[r] - pref[l - 1];
}

ll cost(int l, int r){
    ll c = get(l, r);
    // cout << l << ' '  << r << ' ' << c << ' ' << g << '\n'; 
    if(c % g) return loo;
    ll x = c / g % (l2 / g) * inv_l1 % (l2 / g);
    ll y = (c - x * l1) / l2;
    // cout << l << ' ' << r << ' ' << x << ' ' << y << ' ' << c << ' ' << inv_l1 << ' ' << phi_l2 << ' ' << l2 / g << '\n';
    if(y < 0){
        ll tmp = y * g / l1 - ((y * g) % l1 != 0);
        x += tmp * l2 / g;
        y -= tmp * l1 / g;
        // cout << tmp << ' ' << tmp * l2 / g << ' ' << tmp * l1 / g << ' ' << x << ' ' << y << ' ' << l1 << '\n';
        if(x < 0) return loo;
    }
    // cout << l << ' ' << r << ' ' << x << ' ' << y << ' ' << c << ' ' << inv_l1 << ' ' << phi_l2 << ' ' << l2 / g << '\n';
    return (x + y - 1) * cost_cut + 1ll * (r - l) * cost_uni;
}

void inp(){
    cin >> n >> l1 >> l2 >> cost_cut >> cost_uni;
    if(l1 > l2) swap(l1, l2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    prepare();
    mem(dp, 0x3f);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = min(dp[i], dp[j - 1] + cost(j, i));
        }
        // cout << i << ' ' << dp[i] << '\n';
    }
    
    cout << dp[n];
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
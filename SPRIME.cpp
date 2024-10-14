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
#define file "sprime"
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

ll l , r;
ll ans = 0;

bool check(ll k){
    if(k < 2) return 0;
    for(ll i = 2 ; i <= sqrt(k) ; i++){
        if(k % i == 0) return 0;
    }
    return 1;
}

void btr(ll i , ll val){
    if(val > r) return;
    for(ll j = 1 ; j <= 9 ; j++){
        val = 1ll * j * i + val;
        // cout << i << ' ' << tmp << "gg\n";
        bool ok = check(val);
        if(ok){
            if(l <= val && val <= r){
                // cout << val << '\n';
                ans++;
            }
            btr(i * 10 , val);
        }
        val %= i;
    }
}

void inp(){
    cin >> l >> r;
}

void solve(){
    btr(1 , 0);
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
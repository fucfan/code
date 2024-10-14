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
#define file "sumcalc"
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

int q;
ll n[N];
ll res[N];

namespace sub2{
    bool check(){
        for(int i = 1; i <= q; i++){
            if(n[i] >= N) return 0;
        }
        return 1;
    }

    ll sol(ll i){
        if(i == 1) return 0;
        return sol(sqrt(i)) + 1;
    }

    void prepare(){
        for(int i = 1; i < N; i++){
            res[i] = res[i - 1] + sol(i);
        }
    }

    void solve(){
        prepare();
        for(int i = 1; i <= q; i++){
            cout << res[n[i]] << '\n';
            // cout << i << ' ' << res[i] - res[i - 1] << '\n';
        }
    }
}

namespace sub3{
    ll val[N];

    bool check() {return 1;}

    void solve(){
        for(int i = 1; i <= 5; i++){
            ull tmp = 1;
            val[i] = val[i - 1] + ((tmp << (1 << (i))) - (tmp << (1 << (i - 1)))) * i;
            // cout << i << ' ' << val[i] << '\n';
        }
        // nl;

        for(int i = 1; i <= q; i++){
            int tmp = 63 - __builtin_clzll(n[i]);
            tmp = 63 - __builtin_clzll(tmp);
            // cout << tmp << '\n';
            // cout << tmp << ' ' << n[i] - (1ll << (1ll << tmp)) << ' ';
            cout << val[tmp] + (n[i] - (1ll << (1ll << (tmp))) + 1) * (tmp + 1) << '\n';
        }
    }
}

void inp(){
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> n[i];
    }
}

void solve(){
    if(sub2::check()) return sub2::solve(), void();
    if(sub3::check()) return sub3::solve(), void();
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
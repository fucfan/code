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
#define file "xor"
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

ll a, n;

void inp(){
    cin >> a >> n;
}

void solve(){
    // for(int i = 8; i >= 1; i--) cout << BIT(a, i - 1);
    // nl;
    // for(int i = 8; i >= 1; i--) cout << BIT(n, i - 1);
    // nl;
    ll tmp = 0;
    for(int i = 62; i >= 0; i--){
        // if(tmp % n == 0) break;
            // cout << ((tmp + (1ll << i) * BIT(a, i)) % n) << '\n';
        if((n - ((tmp + (1ll << i) * BIT(a, i)) % n)) % n <= (1ll << i) - 1){
            tmp += (1ll << i) * BIT(a, i);
        }
        else{
            tmp += (1ll << i) * (1 - BIT(a, i));
        }
    }
    // cout << tmp << '\n';
    // for(int i = 8; i >= 1; i--) cout << BIT(tmp, i - 1);
    // nl;
    cout << (tmp ^ a);
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
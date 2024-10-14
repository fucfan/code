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
#define file "STAIRWAY"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

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

ll n;

void inp(){
    cin >> n;
}

void solve(){
    ll ans = 0;
    ll tmp_n = n / 10;
    ll tmp = 10;
    int cnt = 1;
    for(int i = 2 ; i <= 14 ; i++){
        if(n >= tmp) cnt = i;
        if(tmp_n > tmp - tmp / 10){
            ans += 1ll * i * (tmp - tmp / 10);
            tmp *= 10;
        }
        else{
            ans += 1ll * i * (tmp_n - (tmp / 10 - 1));
            // cout << i << ' ' << ans << '\n';
            break;
        }
        // cout << i << ' ' << ans << '\n';
    }
    
    // cout << ans << '\n';

    cout << ans + 1 + (cnt * (n % 10 != 0)) * (n != 1);
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
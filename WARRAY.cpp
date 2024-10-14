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
        freopen(file".out", "w" , stdout);
    }
}

int n, a[N], length;
ll sum;

void inp(){
    cin >> n;
    // n = 1e5;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // a[i] = 1e8;
    }
}

void solve(){
    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += a[i];
    }
    ll minus = 0;
    sort(a + 1, a + 1 + n, greater<>());
    for(int i = 1; i <= n; i++){
        if(a[i] >= 0){
            sum += a[i];
            length++;
            res = sum * length;
        }
        else if((sum + a[i]) * (length + 1) - res >= a[i]){
            sum += a[i];
            length++;
            res = sum * length;
        }
        else minus += a[i];
        // cout << a[i] << ' ' << res << ' ' << sum << ' ' << length << '\n';
        // cout << a[i] << ' ' << sum << ' ' << length << ' ' << res << '\n';
    }
    cout << max(0ll, res + minus);
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
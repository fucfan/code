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
const int N = 3e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m, a[N];
ll ans = 0;

int ok(int val1, int val2){
    if(val1 < val2) return 1;
    if(val1 > val2) return -1;
    return 0;
}

ll get_sum(int l, int r){
    return r - l + 1;
}

ll get_cost(int length){
//    cout << length << "gg\n";
    ll res = 0;
    for(int i = 1; i <= length - m + 1; i++){
        res += get_sum(m, length - i + 1);
    }
    return res;
}

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    ans = 0;
    int pre = 1;
    int type = ok(a[1], a[2]);
    a[n + 1] = a[n];
    for(int i = 2; i <= n; i++){
        if(ok(a[i], a[i + 1]) == type || !ok(a[i], a[i + 1])){
            ans += get_cost(i - pre + 1);
            type = ok(a[i], a[i + 1]);
            pre = i;
        }
        else{
            type = ok(a[i], a[i + 1]);
        }
    }
    cout << ans << '\n';
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

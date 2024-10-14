#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<ll, ll>
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

int n;
pii a[N];
ll pref[N];

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].se;
    }
}

void solve(){
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i].se;
    }
    if(pref[n] < 0){
        cout << "-inf\n";  
        return;
    } 
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if((pref[i] - a[i].se <= pref[n] / 2) && (pref[n] - pref[i] <= pref[n] / 2)){
            for(int j = 1; j <= n; j++){
                ans += a[j].se * abs(a[j].fi - a[i].fi);
            }
            break;
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
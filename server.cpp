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
#define file "server"
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

struct server{
    int s0, s1, s2, t1, t2;

    void input(){
        cin >> t1 >> t2 >> s0 >> s1 >> s2;
    }
} sv[N];

int n;
ll k;

void inp(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) sv[i].input();
}

void solve(){
    ll l = 0;
    ll r = loo;
    ll ans = 0;

    while(l <= r){
        ll mid = (l + r) >> 1;
        ll money = k;

        bool ok = 1;

        for(int i = 1; i <= n; i++){
            money -= 1ll * sv[i].s0 * min(1ll * sv[i].t1, mid);

            if(mid > sv[i].t2) money -= 1ll * sv[i].s1 * (sv[i].t2 - sv[i].t1);
            else money -= 1ll * sv[i].s1 * max(0ll, mid - sv[i].t1);
            
            money -= 1ll * sv[i].s2 * max(0ll, mid - sv[i].t2);

            if(money < 0){
                ok = 0;
                break;
            }
        }

        // cout << mid << ' ' << money << '\n';

        if(ok){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
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
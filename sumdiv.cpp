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
#define file "sumdiv"
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

int l , r;
vector <pii> seg;

bool cmp(pii a , pii b){
    if(a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

void inp(){
    cin >> l >> r;
}

void solve(){
    for(int i = 1 ; i <= sqrt(r) ; i++){
        if(r / i - (l / i + (l % i != 0)) + 1){
            seg.pb({i , i});
            seg.pb({l / i + (l % i != 0) , r / i});
        }
    }

    sort(all(seg) , cmp);
    int cur = 0;
    ll ans = 0;

    for(int i = 0 ; i < seg.size() ; i++){
        if(i && seg[i - 1].fi == seg[i].fi) continue;
        cur = max(cur , seg[i].fi);
        if(cur <= r) ans += 1ll * (seg[i].se - cur + 1) * (seg[i].se + cur) / 2;
        cur = max(cur , seg[i].se);
        // cout << seg[i].fi << ' ' <<  eg[i].se << ' ' << cur << ' ' << ans << '\n';
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
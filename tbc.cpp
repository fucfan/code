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
#define file "tbc"
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

int n, a[N], k;
ll pref[N];
vector <ll> compress;

struct fenwick_tree{
    int node[N];
    int sz;

    void update(int pos, int val){
        for(; pos <= sz; pos += (pos & -pos)){
            node[pos] += val;
        }
    }

    int get(int pos){
        int res = 0;
        for(; pos > 0; pos -= (pos & -pos)){
            res += node[pos];
        }
        return res;
    }
} BIT;

void prepare(){
    for(int i = 1; i <= n; i++) 
        a[i] -= k, pref[i] = pref[i - 1] + a[i];

    compress.pb(0);
    for(int i = 1; i <= n; i++){
        compress.pb(pref[i]);
    }
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());
    BIT.sz = compress.size() + 5;
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
}

void solve(){
    prepare();
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        int pos = lower_bound(all(compress), pref[i]) - compress.begin() + 1;
        ans += BIT.get(pos);
        BIT.update(pos, 1);
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
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
#define file "virus"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m , pow_a, pow_b, sz_x, sz_y;
pii a[N], b[N];
vector <int> compress_x, compress_y;
ll pref[N][N];

void prepare(){
    for(int i = 1; i <= n; i++){
        compress_x.pb(a[i].fi);
        compress_y.pb(a[i].se);
    }
    for(int i = 1; i <= m; i++){
        compress_x.pb(b[i].fi);
        compress_y.pb(b[i].se);
    }

    sort(all(compress_x));
    compress_x.erase(unique(all(compress_x)), compress_x.end());
    sort(all(compress_y));
    compress_y.erase(unique(all(compress_y)), compress_y.end());

    for(int i = 1; i <= n; i++){
        int x = lower_bound(all(compress_x), a[i].fi) - compress_x.begin() + 1;
        int y = lower_bound(all(compress_y), a[i].se) - compress_y.begin() + 1;
        a[i].fi = x;
        a[i].se = y;
        pref[x][y] = pow_a;
    }

    for(int i = 1; i <= m; i++){
        int x = lower_bound(all(compress_x), b[i].fi) - compress_x.begin() + 1;
        int y = lower_bound(all(compress_y), b[i].se) - compress_y.begin() + 1;
        b[i].fi = x;
        b[i].se = y;
        pref[x][y] = -pow_b;
    }
    sz_x = compress_x.size() + 5;
    sz_y = compress_y.size() + 5;

    for(int i = 1; i <= sz_x; i++){
        for(int j = 1; j <= sz_y; j++){
            // cout << pref[i][j] << " \n"[j == sz_y];
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
}

ll get(int x, int y, int u, int v){
    return pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1];
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }    
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> b[i].fi >> b[i].se;
    }
    cin >> pow_a >> pow_b;
}

void solve(){
    prepare();
    ll ans = 0;
    for(int i = 1; i <= sz_x; i++){
        for(int h = 1; i + h - 1 <= sz_x; h++){
            ll Min = 0;
            for(int j = 1; j <= sz_y; j++){
                ans = max(ans, get(i, 1, i + h - 1, j) - Min);
                Min = min(Min, get(i, 1, i + h - 1, j));
                // cout << i << ' ' << i + h - 1 << ' ' << j << ' ' << get(i, 1, i + h - 1, j) - Min << '\n';
            }
        }
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
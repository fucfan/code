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
const int N = 3e3 + 5;
const int LOG = 11;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, k, a[N][N];
int rmq[N][N][LOG + 2];

void prepare(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++) rmq[i][j][0] = a[i][j];
    }
    for(int sz = 1; sz <= LOG; sz++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                rmq[i][j][sz] = max({rmq[i][j][sz - 1], 
                                     rmq[i + (1 << (sz - 1))][j][sz - 1], 
                                     rmq[i][j + (1 << (sz - 1))][sz - 1], 
                                     rmq[i + (1 << (sz - 1))][j + (1 << (sz - 1))][sz - 1]});
            }
        }
    }
}

int get(int x, int y, int u, int v){
    int sz = 31 - __builtin_clz(x - u + 1);
    return max({rmq[u][v][sz],
                rmq[x - (1 << sz) + 1][v][sz],
                rmq[u][y - (1 << sz) + 1][sz],
                rmq[x - (1 << sz) + 1][y - (1 << sz) + 1][sz]});
}

void inp(){
    cin >> n >> k;
    for(int j = n; j >= 1; j--){
        for(int i = 1; i <= n - j + 1; i++) cin >> a[i][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << a[i][j] << ' ';
        nl;
    }
}

void solve(){
    ll ans = 0;
    prepare();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            ans += get(i, j, i + k - 1, j + k - 1);
            cout << i << ' ' << j << ' '
                 << i + k - 1 << ' ' << j + k - 1 << ' '
                 << get(i, j, i + k - 1, j + k - 1) << '\n';
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
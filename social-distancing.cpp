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
#define file "social-distancing"
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

int n, d, grid[1005][1005];
pii p[N];

void prepare(){
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= d; j++){
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
}

int get(int x, int y, int u, int v){
    return grid[u][v] - grid[x - 1][v] - grid[u][y - 1] + grid[x - 1][y - 1];
}

void inp(){
    cin >> d >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i].fi >> p[i].se;
        p[i].fi += oo;
        p[i].se += oo;
        p[i].fi %= d;
        p[i].se %= d;
        grid[p[i].fi + 1][p[i].se + 1]++;
        // cout << p[i].fi << ' ' << p[i].se << '\n';
    }
}

void solve(){
    prepare(); 
    int ans = oo;
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= d; j++){
            // cout << grid[i][j] << " \n"[j == d];
            // cout << i << ' ' << j << ' ' << get(i, 1, i, d) << '\n';
            ans = min(ans, get(i, 1, i, d) + get(1, j, d, j) - get(i, j, i, j));
        }
    }
    cout << ans << '\n';
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
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
#define file "superman"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 30 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m, k;
int id[(1 << 20)];
int p[30];
int cost[30][30];
int dp[(1 << 20)];
bool hate[30][30];

bool cmp(int a, int b){
    return (__builtin_popcount(a) < __builtin_popcount(b));
}

void prepare(){
    for(int i = 1; i <= 2 * m; i++){
        for(int j = i + 1; j <= 2 * m; j++){
            if(hate[i][j]) continue;
            if(p[i] == p[j]) cost[i][j] = n / 2;
            else{
                int small = (p[i] - p[j] + n) % n - 1;
                int large = (p[j] - p[i] + n) % n - 1;
                if(small == large){
                    cost[i][j] = small;
                }
                else{
                    if(small > large) swap(small, large);
                    // cout << small << ' ' << large << '\n';
                    cost[i][j] = (small + 1) / 2 * 2 + (large - (small & 1)) / 2;
                }
            }
            // cout << i << ' ' << j << ' ' << cost[i][j] << '\n';
        }
    }
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1; i <= 2 * m; i++) cin >> p[i], p[i]--;
    for(int i = 1; i <= k; i++){
        int u, v;
        cin >> u >> v;
        hate[u][v] = hate[v][u] = 1;
    }
}

void solve(){
    prepare();
    mem(dp, 0x3f);
    dp[0] = 0;
    for(int mask = 0; mask < (1 << 2 * m); mask++) id[mask] = mask;
    sort(id, id + (1 << 2 * m), cmp);
    
    for(int id_mask = 0; id_mask < (1 << 2 * m); id_mask++){
        int mask = id[id_mask];
        if(__builtin_popcount(mask) & 1) continue;
        for(int i = 1; i <= 2 * m; i++){
            if(BIT(mask, i - 1)) continue;
            for(int j = i + 1; j <= 2 * m; j++){
                if(BIT(mask, j - 1)) continue;
                if(hate[i][j]) continue;
                int nxt_mask = flip(flip(mask, i - 1), j - 1);
                dp[nxt_mask] = min(dp[nxt_mask], dp[mask] + cost[i][j]);
            }
        }
        // for(int i = 0; i < 2 * m; i++) cout << BIT(mask, i);
        // cout << ' ' << dp[mask] << '\n';
    }

    cout << dp[(1 << 2 * m) - 1];
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
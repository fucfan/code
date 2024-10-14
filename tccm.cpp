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
const int mod = 998244353;
const int N = 1e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, mx_sq, num_turn, mx_dif, p[N], Min, Max;
int pref[105][N], f[105][N];

void prepare(){
    for(int j = 0; j <= mx_sq * num_turn; j++) pref[0][j] = 1;
    for(int i = 1; i <= num_turn; i++){
        for(int j = 0; j <= mx_sq * num_turn; j++){
            f[i][j] = pref[i - 1][j];

            if(j - mx_sq - 1 >= 0) 
                f[i][j] = sub(f[i][j], pref[i - 1][j - mx_sq - 1]);

            pref[i][j] = add(pref[i][j - 1], f[i][j]);
            // cout << i << ' ' << j << ' ' << f[i][j] << '\n';
        }
    }
    for(int i = 1; i <= n; i++) p[i] -= Min, Max = max(Max, p[i]);
}

void inp(){
    cin >> n >> mx_sq >> num_turn >> mx_dif;
    Min = oo;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        Min = min(Min, p[i]);
    }
}

void solve(){
    prepare();
    int res = 0;
    Min = 0;
    if(Max - Min - mx_sq * num_turn > mx_dif){
        cout << 0;
        exit(0);
    }
    for(int lef = 0; lef <= Max + mx_sq * num_turn; lef++){
        int cnt = 1;
        for(int i = 1; i <= n; i++){
            int l = max(p[i], lef);
            int r = min(p[i] + mx_sq * num_turn, lef + mx_dif);

            // cout << i << ' ' << l << ' ' << r << "gg\n";
            if(r >= l){
                int tmp = pref[num_turn][l - p[i] - 1];
                if(l - p[i] - 1 < 0) tmp = 0;
                // cout << i << ' ' << l - p[i] - 1 << ' ' << r - p[i] << '\n';
                // cout << tmp << ' ' << pref[num_turn][r - p[i]] << '\n';
                cnt = 1ll * cnt * sub(pref[num_turn][r - p[i]], tmp) % mod;
                // cout << lef << ' ' << i << ' ' << l << ' ' << r << ' ' << cnt << "gg\n";
            }
            else cnt = 0;
        }
            // cout << lef << ' ' << res <<  ' ' << cnt << "ff\n";
        res = add(res, cnt);
    }

    // cout << res << '\n';
    
    for(int lef = 1; lef <= Max + mx_sq * num_turn; lef++){
        int cnt = 1;
        for(int i = 1; i <= n; i++){
            int l = max(p[i], lef);
            int r = min(p[i] + mx_sq * num_turn, lef + mx_dif - 1);

            if(r >= l){
                int tmp = pref[num_turn][l - p[i] - 1];
                if(l - p[i] - 1 < 0) tmp = 0;
                cnt = 1ll * cnt * sub(pref[num_turn][r - p[i]], tmp) % mod;
            }
            else cnt = 0;
        }
        res = sub(res, cnt);
    }
    cout << res;
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
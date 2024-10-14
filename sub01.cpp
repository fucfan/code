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
#define file "sub01"
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

int n, m;
int pref_n[N][2], pref_m[N][2];
int cnt_n[N], cnt_m[N];

int get_n(int l, int r, int type){
    return pref_n[r][type] - pref_n[l - 1][type];
}

int get_m(int l, int r, int type){
    return pref_m[r][type] - pref_m[l - 1][type];
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pref_n[i][x] = pref_n[i - 1][x] + 1;
        pref_n[i][1 - x] = pref_n[i - 1][1 - x];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        pref_m[i][x] = pref_m[i - 1][x] + 1;
        pref_m[i][1 - x] = pref_m[i - 1][1 - x];
    }
}

void solve(){
    for(int i = n + 1; i <= max(n, m); i++){
        pref_n[i][0] = pref_n[i - 1][0] + 1;
        pref_n[i][1] = pref_n[i - 1][1] + 1;
    }
    for(int i = m + 1; i <= max(n, m); i++){
        pref_m[i][0] = pref_m[i - 1][0] + 1;
        pref_m[i][1] = pref_m[i - 1][1] + 1;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        pref_m[i][x] = pref_m[i - 1][x] + 1;
        pref_m[i][1 - x] = pref_m[i - 1][1 - x];
    }
    for(int i = 1; i <= max(n, m); i++){
        maxi(cnt_n[pref_n[i][0]], get_n(i + 1, n, 1));
        maxi(cnt_m[pref_m[i][0]], get_m(i + 1, m, 1));
    }

    for(int i = max(n, m); i >= 1; i--){
        cnt_n[i] = max(cnt_n[i], cnt_n[i + 1]);
        cnt_m[i] = max(cnt_m[i], cnt_m[i + 1]);
        // cout << i << ' ' << cnt_n[i] << ' ' << cnt_m[i] << '\n';
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        ans = max(ans, min(pref_m[i][0], pref_n[i][0]) + 
                       min(get_n(i + 1, n, 1), cnt_m[pref_n[i][0]]));
    }

    for(int i = 1; i <= m; i++){
        ans = max(ans, min(pref_n[i][0], pref_m[i][0]) + 
                       min(get_m(i + 1, m, 1), cnt_n[pref_m[i][0]]));
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
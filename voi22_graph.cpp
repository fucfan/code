#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "graph"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , lv , a[N] , cur , cnt[N];
ll dp[N][N];

void prepare(){
    for(int i = n ; i >= 1 ; i--){
        if(a[i] > 0) cur++;
        cnt[i] = cur; 
    }
}

ll sol(int i , int Max){
    // cout << i << ' ' << Max << ' ' << dp[i][Max] << '\n';

    // cout << i << ' ' << Max << "hh\n";

    if(Max > lv) return 0;

    if(!i){
        // cout << i << ' ' << Max << ' ' << 1 << '\n';
        return 1;
    }

    if(dp[i][Max] != -1) return dp[i][Max];
    
    ll res = 0;

    ll val1 = -1;
    ll val2 = -1;


    if(a[i] != -1){
        if(a[i] + Max > lv) return dp[i][Max] = 0;
        if(!a[i])(res += sol(i - 1 , Max)) %= mod;
        else (res += sol(i - 1 , Max + 1)) %= mod;
    }
    else{
        val1 = (sol(i - 1 , Max + 1) * max(0 , min(lv - Max , i - 1))) % mod;
        // cout << i << ' ' << Max << ' ' << val1 << ' ' << dp[i - 1][Max + 1] << "gg\n";
        val2 = sol(i - 1 , Max);
        // cout << i << ' ' << Max << ' ' << val2 << "gg\n";
        (res += val1) %= mod;
        (res += val2) %= mod;
    }

    // cout << i << ' ' << Max << ' ' << res << ' ' << val1 << ' ' << val2 << '\n';

    return dp[i][Max] = res;
}

void inp(){
    cin >> n >> lv;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){   
    mem(dp , -1);
    cout << sol(n , 0);
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
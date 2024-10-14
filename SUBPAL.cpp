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
#define file "subpal"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 998244353;
const int N = 4e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

string s;
int n;
int dp1[N][N];
int dp2[N][N];
int ans[N];

void inp(){
    cin >> s;
    n = s.size();
    s = " " + s;
}

void solve(){
    for(int len = 1 ; len <= n ; len++){
        for(int i = 1 ; i + len - 1 <= n ; i++){
            int j = i + len - 1;
            if(s[i] == s[j]) dp1[i][j] = dp1[i + 1][j - 1] + 1;
            dp1[i][j] = add(dp1[i][j] , sub(add(dp1[i + 1][j] , dp1[i][j - 1]) , dp1[i + 1][j - 1]));
        }
    }
    for(int len = n ; len >= 1 ; len--){
        for(int i = 1 ; i + len - 1 <= n ; i++){
            int j = i + len - 1;
            if(s[i] == s[j]) dp2[i][j] = dp2[i - 1][j + 1] + 1;
            dp2[i][j] = add(dp2[i][j] , sub(add(dp2[i - 1][j] , dp2[i][j + 1]) , dp2[i - 1][j + 1]));
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j++){
            if(s[i] != s[j]) continue;
            ans[i] = add(ans[i] , 1ll * (dp1[i + 1][j - 1] + 1) * (dp2[i - 1][j + 1] + 1) % mod);

            if(i != j)
                ans[j] = add(ans[j] , 1ll * (dp1[i + 1][j - 1] + 1) * (dp2[i - 1][j + 1] + 1) % mod);
        }
    }

    for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
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
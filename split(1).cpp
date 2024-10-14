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
#define file "split"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 998244353;
const int N = 7e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n;
string s;
int dp[N][N];
int pref[N][N];
bool ok[N][N];

void prepare(){
    for(int len = 2; len * 2 <= n; len++){
        bool tmp = 0;
        int pos = n + 1;
        for(int i = n; i > n - len; i--){
            if(s[i] != s[i - len]){
                tmp = (s[i] > s[i - len]);
                pos = i;
            }
        }
            // cout << len << ' ' << s1 << ' ' << s2 << '\n';
        for(int i = n; i - 2 * len + 1 > 0; i--){
            if(s[i - len + 1] != s[i - len * 2 + 1]){
                tmp = (s[i - len + 1] > s[i - len * 2 + 1]);
                pos = i - len + 1;
            }
            if(tmp) 
                ok[i - len + 1][i] = 1;
            if(i == pos) tmp = 0;
        }
    }
    for(int i = 2; i <= n; i++) ok[i][i] = (s[i] > s[i - 1]);

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         cout << i << ' ' << j << ' ' << ok[j][i] << '\n';
    //     }
    // }
}

void inp(){
    cin >> s;
    n = s.size();
    s = " " + s;
    s = s + " ";
}

void solve(){
    prepare();
    int ans = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        if(s[i + 1] != '0'){
            for(int j = 1; j <= i; j++){
                if(s[j] == '0') continue;
                if(j - 1 < i - j + 1 || ok[j][i]){
                    dp[i][j] = add(dp[i][j], pref[j - 1][max(0, 2 * j - i - 1)] + 
                                            dp[j - 1][max(0, 2 * j - i - 1)]);
                }
                else dp[i][j] = add(dp[i][j], pref[j - 1][max(0, 2 * j - i - 1)]);
            }

            for(int j = i; j >= 1; j--){
                pref[i][j - 1] = add(pref[i][j], dp[i][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        ans = add(ans, dp[n][i]);
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
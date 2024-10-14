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
#define file "words"
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

int n, z[N], dp[N];
bool not_ok[N];
string s;

void z_function(){
    int l = 0;
    int r = 0;
    for(int i = 1; i < (int)s.size(); i++){
        if(i > r){
            l = r = i;
            while(r < (int)s.size() && s[r] == s[r - l]) r++;
            z[i] = r - l;
            r--;
        }
        else{
            if(z[i - l] < r - i + 1){
                z[i] = z[i - l];
            }
            else{
                l = i;
                while(r < (int)s.size() && s[r] == s[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

void inp(){
    cin >> n;
    cin >> s;
}

void solve(){
    z_function();
    for(int i = 1; i < (int)s.size(); i++){
        for(int j = i; j <= i + z[i] - 1; j++){
            not_ok[j] = 1;
        }
    }
    dp[(int)s.size()] = 1;
    for(int i = (int)s.size() + 1; i <= n; i++){
        dp[i] = add(dp[i], dp[i - 1]);
        for(int j = 2; j <= (int)s.size(); j++){
            if(!not_ok[j - 1]){
                dp[i] = add(dp[i], dp[i - j]);
            }
        }

        // cout << i << ' ' << dp[i] << '\n';
    }

    cout << dp[n];
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
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define bit(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int LOG = 25;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
         freopen(file".inp", "r" , stdin);
         freopen(file".out", "w" , stdout);
    }
}

int n;
string s[N];
int dp[(1 << 24) | 1];

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
}

void solve(){
//    for(int i = 1; i <= n; i++){
//        int mask = 0;
//        for(auto j : s[i]) mask |= (1 << (j - 'a'));
//        dp[mask]++;
//    }

    for(int i = 1; i <= n; i++){
        int mask = 0;
        for(auto j : s[i]) mask |= (1 << (j - 'a'));
        for(int sub_mask = mask;; sub_mask = (sub_mask - 1) & mask){
            if(!sub_mask) break;
            if(__builtin_popcount(sub_mask) & 1) dp[sub_mask]++;
            else dp[sub_mask]--;
        }
    }

    for(int i = 0; i < 24; i++){
        for(int mask = 0; mask < (1 << 24); mask++){
            if(bit(mask, i))
                dp[mask] += dp[mask ^ (1 << i)];
        }
    }

//    for(int i = 1; i < (1 << 6); i++){
//        for(int j = 0; j < 6; j++){
//            cout << bit(i, j);
//        }
//        nl;
//        cout << dp[i] << '\n';
//    }
    int res = 0;

    for(int i = 1; i < (1 << 24); i++){
        res ^= (dp[i] * dp[i]);
    }
    cout << res;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UwU      */


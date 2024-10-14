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
#define file "storge"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 5e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , a[N] , b[N];
vector <int> compress;
ll dp[N][N];

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        compress.pb(a[i]);
    }

    sort(all(compress));
    compress.erase(unique(all(compress)) , compress.end());
}

void solve(){
    for(int i = 1 ; i <= n ; i++) 
        b[i] = lower_bound(all(compress) , a[i]) - compress.begin() + 1;

    mem(dp , 0x3f);
    
    for(int i = 1 ; i <= compress.size() ; i++) dp[0][i] = 0;

    for(int i = 1 ; i <= n ; i++){
        ll Min = oo;
        for(int pre = 1 ; pre <= compress.size() ; pre++){
            Min = min(Min , dp[i - 1][pre]);
            dp[i][pre] = min(dp[i][pre] , Min + abs(compress[pre - 1] - compress[b[i] - 1]));
        }
    }

    ll ans = oo;

    for(int i = 1 ; i <= compress.size() ; i++){
        ans = min(ans , dp[n][i]);
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
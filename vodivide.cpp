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
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
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

int n;
pair <pii , int> a[N];
int dp[N][N];

int sol(int i , int cnt){
    // cout << i << ' ' << cnt << '\n';

    if(i > n) return dp[i][cnt] = 0;

    if(dp[i][cnt] != -1) return dp[i][cnt];

    int res = 0;

    if(cnt > (i - 1) / 2) res = max(res , sol(i + 1 , cnt));
    if(cnt < n / 2) res = max(res , sol(i + 1 , cnt + 1) + a[i].fi.se);

    return dp[i][cnt] = res;
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i].fi.fi;
    for(int i = 1 ; i <= n ; i++) cin >> a[i].fi.se;
    for(int i = 1 ; i <= n ; i++) a[i].se = i;
}

void trace(){
    int cnt = 0;
    vector <pair <pii , int>> val1 , val2;
    for(int i = 1 ; i <= n ; i++){
        if(dp[i][cnt] == dp[i + 1][cnt + 1] + a[i].fi.se && cnt + 1 <= n / 2){
            val1.pb(a[i]);
            cnt++;
        }
        else if(dp[i][cnt] == dp[i + 1][cnt]){
            val2.pb(a[i]);
        }
    }

    sort(all(val1));
    sort(all(val2));

    cout << dp[1][0] << '\n';

    // cout << val1.size() << ' ' << val2.size() << '\n';

    for(int i = 0 ; i < n / 2 ; i++){
        cout << val1[i].se << ' ' << val2[i].se << '\n';
    }
}

void solve(){
    sort(a + 1 , a + 1 + n);
    mem(dp , -1);
    sol(1 , 0);
    trace();
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
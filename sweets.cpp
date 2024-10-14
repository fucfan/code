#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<ll, ll>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "sweets"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

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

int n , a[N];

namespace sub3{
    vector <pair <pii , ll>> vt;
    vector <ll> compress;
    const ll oo = 1e18 + 7;

    int b[N];
    ll ans = -oo;
    ll pref_max[7001][7001];

    bool check(){
        return (n <= 20);
    }

    void out(int type){
        ll suma = 0;
        ll sumb = 0;
        ll sumc = 0;

        if(type == 1){
            for(int i = (n > 8 ? n - 7 : n / 2 + 1) ; i <= n ; i++){
                if(b[i] == 0) suma += a[i];
                if(b[i] == 1) sumb += a[i];
                if(b[i] == 2) sumc += a[i];
            }

            vt.pb({{sumc - sumb , sumb - suma} , sumc - suma});
            compress.pb(sumc - sumb);
            compress.pb(sumb - suma);
        }
        else{
            for(int i = 1 ; i <= (n > 8 ? n - 8 : n / 2) ; i++){
                if(b[i] == 0) suma += a[i];
                if(b[i] == 1) sumb += a[i];
                if(b[i] == 2) sumc += a[i];
            }

            ll x = sumc - sumb;
            ll y = sumb - suma;

            ll _x = upper_bound(all(compress) , -x) - compress.begin();
            ll _y = upper_bound(all(compress) , -y) - compress.begin();

            ans = max(ans , x + y + pref_max[_x][_y]);
        }
    }

    void btr(int i , int end){
        for(int j = 0 ; j <= 2 ; j++){
            b[i] = j;
            if(i != end) btr(i + 1 , end);
            else out(end == n);
        }
    }

    void solve(){
        if(n > 8) btr(n - 7 , n);
        else btr(n / 2 + 1 , n);
        sort(all(compress));
        compress.erase(unique(all(compress)) , compress.end());

        mem(pref_max , -0x3f);

        // cout << compress.size() << '\n';

        for(auto j : vt){
            ll x = j.fi.fi;
            ll y = j.fi.se;
            x = lower_bound(all(compress) , x) - compress.begin() + 1;
            y = lower_bound(all(compress) , y) - compress.begin() + 1;
            pref_max[x][y] = max(pref_max[x][y] , j.se);
            // cout << x << ' ' << y << ' ' << pref_max[x][y]  << ' ' << j.se << '\n';
        }

        for(int i = 1 ; i <= (int)compress.size() ; i++){
            for(int j = 1 ; j <= (int)compress.size() ; j++){
                pref_max[i][j] = max({pref_max[i][j] , pref_max[i - 1][j] , pref_max[i][j - 1]});
            }
        }

        if(n > 8) btr(1 , n - 8);
        else btr(1 , n / 2);

        cout << -ans;
    }
}

namespace sub4{
    const int oo = 1e9 + 7;

    int dp[2][5001][5001];

    bool check(){
        return 1;
    }

    void solve(){
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            sum += a[i];
        }

        mem(dp , 0x3f);
        dp[0][0][0] = 0;
        int ans = oo;

        int x = 0;
        int y = 1;


        for(int i = 1 ; i <= n ; i++){
            for(int suma = 0 ; suma <= sum ; suma++){
                for(int sumc = 0 ; sumc <= sum ; sumc++){
                    dp[y][suma][sumc] = dp[x][suma][sumc];
                    if(suma >= a[i]) dp[y][suma][sumc] = min(dp[y][suma][sumc] , dp[x][suma - a[i]][sumc] + a[i]);
                    if(sumc >= a[i]) dp[y][suma][sumc] = min(dp[y][suma][sumc] , dp[x][suma][sumc - a[i]] - a[i]);
                    // cout << i << ' ' << suma << ' ' << sumc << ' ' << dp[i][suma][sumc] << ' ' << a[i] << '\n';
                }
            }
            swap(x , y);
        }

        
        for(int suma = 0 ; suma <= sum ; suma++){
            for(int sumc = 0 ; sumc <= sum ; sumc++){
                int sumb = sum - suma - sumc;
                if(suma >= sumb && sumb >= sumc){
                    ans = min(ans , dp[x][suma][sumc]);
                }
            }
        }

        cout << ans;
    }
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){
    if(sub3::check()) return sub3::solve();
    if(sub4::check()) return sub4::solve();
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
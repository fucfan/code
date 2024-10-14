#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "whome"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
         freopen(file".inp", "r" , stdin);
         freopen(file".out", "w" , stdout);
    }
}

int n , m;
int s[N];
ll a[N] , p , c;;
ll dp[N][100];

void inp(){
    cin >> n >> m >> p >> c;

    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= m ; i++) cin >> s[i];

    sort(a + 1 , a + 1 + n);
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();

    mem(dp , -0x3f);

    for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int mask = 0 ; mask < (1 << m) ; mask++){
            dp[i][mask] = dp[i - 1][mask];
            for(int j = 1 ; j <= m ; j++){
                if(i >= s[j] && BIT(mask , j - 1))
                    dp[i][mask] = max(dp[i][mask] ,
                                  max(dp[i - s[j]][flip(mask , j - 1)] , dp[i - s[j]][mask]) + p - (a[i] - a[i - s[j] + 1]) * (a[i] - a[i - s[j] + 1]) * c);
            }
        }
    }

//    for(int i = 1 ; i <= n ; i++){
//        for(int mask = 0 ; mask < (1 << m) ; mask++){
//            cout << i << ' ';
//
//            for(int j = 1 ; j <= m ; j++)
//                cout << BIT(mask , j - 1);
//
//            cout << ' ' << dp[i][mask] << '\n';
//        }
//    }

    ll ans = -oo;

    for(int i = 1 ; i <= n ; i++){
        ans = max(ans , dp[i][(1 << m) - 1]);
    }

    cout << ans;
}

/*      UwU      */


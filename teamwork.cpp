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
#define file "teamwork"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e3 + 507;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , a[N] , b[N] , c[N] , num1 , num2 , sub;
int l , cnt , dp[128][2 * N][2] , num[N][70];

void prepare(){
    for(int i = 1 ; i <= n ; i++){
        a[i] = a[i - 1] + a[i];
        b[i] = b[i - 1] + b[i];
        c[i] = c[i - 1] + c[i];
    }
}

int get(int l , int r , int type){
    l = max(l , 0);
    if(l > r) return 0;
    if(type == 0) return a[r] - a[l - 1];
    if(type == 1) return b[r] - b[l - 1];
    if(type == 2) return c[r] - c[l - 1];
    return -1;
}

void reset(){
    for(int i = 0 ; i <= n ; i++){
        a[i] = b[i] = c[i] = 0;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= cnt ; j++){
            for(int f = min(i , l) + 1 ; f >= 0 ; f--){
                dp[i % 128][num[j][f]][0] = dp[i % 128][num[j][f]][1] = 0;
            }
        }
    }
}

void inp(){
    cin >> n >> cnt >> l;
    cin >> num1;
    for(int i = 1; i <= num1 ; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }
    cin >> num2;
    for(int i = 1; i <= num2 ; i++){
        int x;
        cin >> x;
        b[x] = 1;
        c[x] = a[x] * b[x];
        if(c[x]) a[x] = b[x] = 0;
    }
}

void solve(){
    if(cnt * l > 2 * n && cnt > 2){
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            cnt += max({a[i] , b[i] , c[i]});
        }

        cout << cnt << ' ';

        for(int i = 0 ; i <= n ; i++){
            a[i] = b[i] = c[i] = 0;
        }

        return;
    }
    int id = 0;
    for(int i = 1 ; i <= cnt ; i++){
        for(int f = 0 ; f <= l + 1 ; f++){
            num[i][f] = ++id;
        }
    }
    prepare();
    // for(int i = 0 ; i <= n ; i++){
    //     for(int f = 1 ; f <= min(i , l) ; f++){
    //         dp[i][0][f][0] = dp[i][0][f][1] = 0;
    //     }
    // }
    int ans = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= cnt ; j++){
                // cout << i << ' ' << j << ' ' << min(i , l) << ' ' << 0 << '\n';
                // cout << i - min(i , l) << ' ' << j - 1 << ' ' << 0 << ' ' << 0 << ' ' << dp[i - min(i , l)][j - 1][0][0] << "gg\n";
            dp[i % 128][num[j][min(i , l)]][0] = dp[(i - min(i , l)) % 128][num[j - 1][0]][0] + get(i - min(i , l) + 1 , i , 0) + get(i - min(i , l) + 1 , i , 2);
            dp[i % 128][num[j][min(i , l)]][1] = dp[(i - min(i , l)) % 128][num[j - 1][0]][1] + get(i - min(i , l) + 1 , i , 1) + get(i - min(i , l) + 1 , i , 2);
            for(int f = min(i , l) ; f >= 0 ; f--){
                dp[i % 128][num[j][f]][0] = max(dp[i % 128][num[j][f]][0] , dp[(i + 127) % 128][num[j][f]][0]);
                dp[i % 128][num[j][f]][1] = max(dp[i % 128][num[j][f]][1] , dp[(i + 127) % 128][num[j][f]][1]);
                // cout << i - l + 1 << ' ' << i - f << '\n';
                if(j){
                    dp[i % 128][num[j][f]][0] = max(dp[i % 128][num[j][f]][0] , dp[(i - f) % 128][num[j - 1][l - f]][1] + get(i - l + 1 , i , 0) + get(i - f + 1 , i , 2));
                    dp[i % 128][num[j][f]][1] = max(dp[i % 128][num[j][f]][1] , dp[(i - f) % 128][num[j - 1][l - f]][0] + get(i - l + 1 , i , 1) + get(i - f + 1 , i , 2));
                }
                dp[i % 128][num[j][f]][0] = max(dp[i % 128][num[j][f]][0] , dp[i % 128][num[j][f + 1]][0]);
                dp[i % 128][num[j][f]][1] = max(dp[i % 128][num[j][f]][1] , dp[i % 128][num[j][f + 1]][1]);

                // cout << i << ' ' << j << ' ' << f << ' ' << 0 << ' ' << dp[i % 128][j][f][0] << '\n';
                // cout << i << ' ' << j << ' ' << f << ' ' << 1 << ' ' << dp[i % 128][j][f][1] << '\n';
                ans = max({ans , dp[i % 128][num[j][f]][0] , dp[i % 128][num[j][f]][1]});
            }
        }
    }

    cout << ans << ' ';

    reset();
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> sub >> test_case;
    // assert(sub != 3);
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
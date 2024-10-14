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
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int t , sz , Max;
ll k;
string n;
ll dp[21][175][4];
ll dp1[21][175][3];
ll pw[20];

ll cal(int i , int sum , int higher){
    // cout << i << ' ' << sum << ' ' << higher << '\n';

    if(sum == Max){
        // cout << i << ' ' << sum << ' ' << higher << ' ' << sz - (higher == 1) - i + 2 << '\n';
        return dp[i][sum][higher] = sz - (higher == 1) - i + 2;
    }

    if(i > sz) return dp[i][sum][higher] = 0;

    if(dp[i][sum][higher] != -1) return dp[i][sum][higher];

    ll res = 0;

    for(int j = (i == 1) ; j <= 9 ; j++){
        if(sum + j <= Max){
            if(!higher){
                if(j > (n[i] - '0')) res += cal(i + 1 , sum + j , 1);
                if(j < (n[i] - '0')) res += cal(i + 1 , sum + j , 2);
                if(j == (n[i] - '0')) res += cal(i + 1 , sum + j , 0);
            }
            else res += cal(i + 1 , sum + j , higher);
        }
    }

    // cout << i << ' ' << sum << ' ' << higher << ' ' << res << '\n';

    return dp[i][sum][higher] = res;
}

ll cal1(int i , int sum , int ok){
    if(i > sz){
        if(sum <= Max && sum){
    // cout << i << ' ' << sum << ' ' << Max << ' ' << num << '\n';
            return 1;
        }
        return 0;
    }

    if(dp1[i][sum][ok] != -1){
    // cout << i << ' ' << sum << ' ' << Max << ' ' << num << ' ' << dp1[i][sum][ok] << '\n';
        return dp1[i][sum][ok];
    }
    
    ll res = 0;

    if(!ok){
        for(int j = 0 ; j <= (n[i] - '0') ; j++){
            if(sum + j > Max) break;
            if(j < (n[i] - '0')) res += cal1(i + 1 , sum + j , 1);
            else res += cal1(i + 1 , sum + j , ok);
        }
    }
    else{
        for(int j = 0 ; j <= 9 ; j++){
            if(sum + j > Max) break;
            res += cal1(i + 1 , sum + j , 1);
        }
    }

    return dp1[i][sum][ok] = res;
}

void trace(){
    int sum = 0;
    int ok = 0;
    ll ans = 0;
    for(int i = 1 ; i <= sz ; i++){
        for(int j = (i == 1) ; j <= 9 ; j++){
            int nxt_ok = ok;

            if(!ok){
                if(j > (n[i] - '0')) nxt_ok = 1;
                if(j < (n[i] - '0')) nxt_ok = 2;
            }

            // cout << i + 1 << ' ' << sum + j << ' ' << nxt_ok << ' ' << dp[i + 1][sum + j][nxt_ok] << ' ' << k << '\n';

            if(dp[i + 1][sum + j][nxt_ok] == -1) continue;

            if(dp[i + 1][sum + j][nxt_ok] >= k){
                ans = ans * 10 + j;
                sum += j;
                ok = nxt_ok;
                // cout << "gg\n";
                break;
            }
            else{
                k -= dp[i + 1][sum + j][nxt_ok];
            }
        }
        if(sum == Max) break;
    }

    for(int i = 1 ; i < k ; i++) ans *= 10;

    cout << ans << '\n';
}

void query1(){
    int l = 1;
    int r = sz * 9;

    int last = 1;

    while(l <= r){
        int mid = (l + r) >> 1;

        for(int i = 0 ; i <= sz + 1 ; i++){
            for(int j = 0 ; j <= mid + 1 ; j++){
                for(int f = 0 ; f <= 1 ; f++){
                    dp1[i][j][f] = -1;
                }
            }
        }

        Max = mid;
        ll tmp = cal1(1 , 0 , 0);

        // cout << mid << ' ' << tmp << '\n';

        if(tmp >= k){
            r = mid - 1;
            last = mid;
        }
        else{
            l = mid + 1;
        }
    }

    Max = last;

    if(Max > 1){
        Max--;

        for(int i = 0 ; i <= sz + 1 ; i++){
            for(int j = 0 ; j <= Max + 1 ; j++){
                for(int f = 0 ; f <= 1 ; f++){
                    dp1[i][j][f] = -1;
                }
            }
        }

        // nl;

        ll val = cal1(1 , 0 , 0);
        
        // cout << val << "kk\n";

        k -= val;

        // cout << k << ' ' << Max << "gg\n";

        Max++;
    }

    for(int i = 0 ; i <= sz + 1 ; i++){
        for(int j = 0 ; j <= Max + 1 ; j++){
            for(int f = 0 ; f <= 2 ; f++){
                dp[i][j][f] = -1;
            }
        }
    }

    // cout << Max << ' ' << n << "gg\n";
    
    cal(1 , 0 , 0);

    trace();
}

void prepare(){
    pw[0] = 1;
    for(int i = 1 ; i <= 18 ; i++) pw[i] = pw[i - 1] * 10;
}

int digit(ll n , int i){
    if(n / pw[i - 1] == 0) return -1;
    return (n / pw[i - 1]) % 10;
}


void query0(){
    ll ans = 0;
    int sum = 0;
    int ok = 0;
    string tmp = "";

    Max = 0;

    for(int i = 1 ; i <= 19 ; i++){
        int d = digit(k , i);
        if(d == -1) break;
        else tmp = char(d + '0') + tmp;
        Max += d;
    }

    if(Max > 1){
        Max--;

        for(int i = 0 ; i <= sz + 1 ; i++){
            for(int j = 0 ; j <= Max + 1 ; j++){
                for(int f = 0 ; f <= 1 ; f++){
                    dp1[i][j][f] = -1;
                }
            }
        }

        ans = cal1(1 , 0 , 0);

        // cout << ans << ' ';

        Max++;
    }

    for(int i = 0 ; i <= sz + 1 ; i++){
        for(int j = 0 ; j <= Max + 1 ; j++){
            for(int f = 0 ; f <= 2 ; f++){
                dp[i][j][f] = -1;
            }
        }
    }

    // cout << Max << ' ' << n << "gg\n";
    
    cal(1 , 0 , 0);

    // cout << Max << ' ' << ans << ' ';

    tmp = " " + tmp;
    
    for(int i = 1 ; i <= sz ; i++){
        for(int j = (i == 1) ; j < tmp[i] - '0' ; j++){

            int nxt_ok = ok;

            if(!ok){
                if(j > (n[i] - '0')) nxt_ok = 1;
                if(j < (n[i] - '0')) nxt_ok = 2;
            }

            // cout << i + 1 << ' ' << sum + j << ' ' << nxt_ok << ' ' << dp[i + 1][sum + j][nxt_ok] << ' ' << k << '\n';

            if(dp[i + 1][sum + j][nxt_ok] == -1) continue;

            ans += dp[i + 1][sum + j][nxt_ok];
        }

        int j = tmp[i] - '0';

        int nxt_ok = ok;

        if(!ok){
            if(j > (n[i] - '0')) nxt_ok = 1;
            if(j < (n[i] - '0')) nxt_ok = 2;
        }

        if(dp[i + 1][sum + j][nxt_ok] == -1) continue;

            // cout << i + 1 << ' ' << sum + j << ' ' << nxt_ok << ' ' << dp[i + 1][sum + j][nxt_ok] << ' ' << k << '\n';
        
        sum += j;
        ok = nxt_ok;
    }

    for(int i = (int)tmp.size() - 1 ; i >= 1 ; i--){
        if(tmp[i] == '0') ans++;
        else break;
    }

    cout << ans + 1 << '\n';
}

void inp(){
    cin >> t >> n >> k;
    sz = n.size();
    n = " " + n;
}

void solve(){
    if(t) query1();
    else query0();
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;
    prepare();
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */

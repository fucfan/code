#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e7 + 5;
int t;
bool pr[N];
string a , b , s;
ll dp[16][2][127] , pref[N];
void sieve(){
    pr[1] = true;
    pr[0] = true;
    for(int i = 2 ; i <= 300 ; i++){
        if(!pr[i]){
            for(int j = i * i ; j <= 300 ; j += i){
                pr[j] = true;
            }
        }
    }
}
int digit_sum(ll k){
    ll g = k;
    int s = 0;
    while(k > 0){
        s += k % 10;
        k = k / 10;
    }
    return s;
}
void set_up(){
    for(ll i = 2 ; i <= 1e7 ; i++){
        if(!pr[digit_sum(i * i)]){
            pref[i] = pref[i - 1] + 1;  
        }
        else pref[i] = pref[i - 1];
    }
}
ll sol(int i , bool islarge , int sum , int sum1){
    // cout << i << '\n';
    if(i == s.size()){
        if(!pr[sum]){
            // cout << sum1 << '\n';
            return 1;
        }
        return 0;
    }
    // if(dp[i][islarge][sum] != -1){
    //     return dp[i][islarge][sum];
    // }
    ll res = 0;
    if(islarge){
        for(int j = 0 ; j <= 9 ; j++){
            res += sol(i + 1 , islarge , sum + j , sum1 * 10 + j);
        }
    }
    else for(int j = 0 ; j <= s[i] - '0' ; j++){
        if(j < s[i] - '0') res += sol(i + 1 , 1 , sum + j , sum1 * 10 + j);
        else res += sol(i + 1 , 0 , sum + j , sum1 * 10 + j);
    }
    // cout << i << ' ' << next_st << ' ' << next_en <<  ' ' << sum << "gg\n";
    // cout << dp[i][islarge][sum] << '\n';
    dp[i][islarge][sum] = res;
    cout << res << '\n';
    return res;
}
void inp()
{
    cin >> t;
    sieve();
    set_up();
    mem(dp , -1);
    for(int i = 1 ; i <= t ; i++){
        cin >> a >> b;
        while(a.size() < b.size()){
            a = "0" + a;
        } 
        // cout << a << ' ' << b << '\n';
        s = a;
        ll ans1 = sol(0 , 0 , 0 , 0);
        s = b;
        ll ans2 = sol(0 , 0 , 0 , 0);
        ll x = 0;
        ll y = 0;
        for(int i = 0 ; i < a.size() ; i++){
            x = x * 10 + (a[i] - '0');
            y = y * 10 + (b[i] - '0');
        }
        ll n = sqrt(x);
        if(n * n < x) n++;
        ll m = sqrt(y);
        cout << ans1 << ' ' << ans2 << '\n';
        // cout << n << ' ' << m << '\n';
        // cout << pref[n] << ' ' << pref[m] << '\n';
        // cout << pref[m] - pref[n - 1] << '\n';
        if(!pr[digit_sum(x)]) ans1--;
        cout << ans2 - ans1 - (pref[m] - pref[n - 1]) << '\n';
        // cout << ans << '\n';
    }
}

void solve()
{
    
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}

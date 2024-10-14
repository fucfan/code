#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
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
const int N = 1e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , k;
int pw[N] , pref_pw[N] , value[N];
int dp[N][N][2][2];

void prepare(){
    pw[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        pw[i] = (pw[i - 1] * 10) % k;
    }

    pref_pw[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        pref_pw[i] = (pref_pw[i - 1] + pw[i]) % k;
    }
}

ll sol(int i , int m , bool check1 , bool check2){
    if(i > n){
        if(!m && check1 && check2) return 1;
        return 0;
    }

    if(dp[i][m][check1][check2] != -1) return dp[i][m][check1][check2];

    ll res = 0;

    for(int d1 = (i == 1) ; d1 <= 7 ; d1++){
        for(int d2 = (check1 ? 0 : d1) ; d2 <= 7 ; d2++){
            for(int d3 = (check2 ? 0 : d2) ; d3 <= 7 ; d3++){
                bool nxt_check1 = check1;
                bool nxt_check2 = check2;
                if(d2 > d1) nxt_check1 = 1;
                if(d3 > d2) nxt_check2 = 1;

                int nxt_m = m;

                (nxt_m += (pref_pw[n - i] * i * d1 % k)) %= k;
                (nxt_m += (pref_pw[n - i] * i * d2 % k)) %= k;
                (nxt_m += (pref_pw[n - i] * i * d3 % k)) %= k;

                // cout << m << ' ' << i << ' ' << nxt_m << ' ' << d1 << ' ' << d2 << ' ' << d3 << '\n';

                int val = sol(i + 1 , nxt_m , nxt_check1 , nxt_check2);

                res = add(res , val);
            }
        }
    }

    return dp[i][m][check1][check2] = res;
}

void inp(){
    cin >> n >> k;
}

void solve(){
    prepare();

    mem(dp , -1);

    cout << sol(1 , 0 , 0 , 0);
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
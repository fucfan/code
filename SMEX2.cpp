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
#define file "smex2"
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

int n , a[N] , mex[N][N] , cnt[N];
ll dp[N][N];

void prepare(){
    int val = 0;
    for(int i = 1 ; i <= n ; i++){
        mem(cnt , 0);
        val = 0;
        for(int j = i ; j <= n ; j++){
            cnt[a[j]]++;
            while(cnt[val]) val++;
            mex[i][j] = val;
        }
    }
}

ll sol(int i , int pre_mex){
    if(i > n) return 1;

    ll res = 0;

    if(dp[i][pre_mex] != -1) return dp[i][pre_mex];

    for(int j = i ; j <= n ; j++){
        if(mex[i][j] >= pre_mex) (res += sol(j + 1 , mex[i][j])) %= mod; 
    }

    return dp[i][pre_mex] = res;
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){
    prepare();
    mem(dp , -1);
    cout << sol(1 , -1);
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
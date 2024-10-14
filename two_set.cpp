#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 500 + 5;
int n , dp[N][N * N / 2];
int Pow(int a , int b){
    int tmp = a;
    b--;
    while(b){
        if(b & 1) a = (1ll * a * tmp) % mod;
        tmp = (1ll * tmp * tmp) % mod;
        b >>= 1;
    }
    return a;
}
int sol(int i , int sum){
    // cout << i << ' ' << sum << '\n';
    if(i > n){
        if(sum == (n * (n + 1)) / 4) return 1;
        return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    int res = 0;
    res += sol(i + 1 , sum + i);
    if(res >= mod) res -= mod;
    res += sol(i + 1 , sum);
    if(res >= mod) res -= mod;
    return dp[i][sum] = res;
}
void inp(){
    cin >> n;
}

void solve(){
    mem(dp , - 1);
    if((n * (n + 1)) % 4){
        cout << 0;
        exit(0);
    }
    cout << (1ll * sol(1 , 0) * Pow(2 , mod - 2)) % mod;
}

void run_with_file(){
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    // run_with_file();
    inp();
    solve();
}

/*      UMU      */
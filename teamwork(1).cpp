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
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , k , a[N] , dp[N];
void inp(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        int Max = a[i];
        for(int j = i ; j >= (max(1 , i - k + 1)) ; j--){
            Max = max(Max , a[j]);
            dp[i] = max(dp[i] , dp[j - 1] + Max * (i - j + 1));
        }
    }
    // for(int i = 1 ; i <= n ; i++){
    //     cout << dp[i] << ' ';
    // }
    // nl;
    cout << dp[n];
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
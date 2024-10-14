#include <bits/stdc++.h>
#define get_bit(x , i) (((x) >> i) & 1)
#define name "ttttt3"
#define mem(a , b) memset((a) , (b) , sizeof((a)))
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

int q , k;
int dp[30][200];
string s;

ll sol(int i , int mask){
    if(i == s.size()) return 1;
    if(dp[i][mask] != -1) return dp[i][mask];
    ll res = 0;
    for(int j = 0 ; j <= s[i] - '0' - get_bit(mask, 0); j++){
        //if(j + get_bit(mask , 0) <= s[i] - '0')
            (res += sol(i + 1 , (mask >> 1))) %= mod;
    }
    if(i + k < s.size()){
        for(int j = s[i] - '0' + 1 - get_bit(mask, 0); j <= 9 ; j++){
            //if(j + get_bit(mask , 0) <= 9 &&
              // (10 + s[i] - '0') - (j + get_bit(mask , 0)) <= 9)
                (res += sol(i + 1 , (mask >> 1) | (1 << (k - 1)))) %= mod;
        }
    }
    return dp[i][mask] = res % mod;
}

int main(){
    freopen(name".inp" , "r" , stdin);
    freopen(name".out" , "w" , stdout);
    cin >> q >> k;
    for(int i = 1 ; i <= q ; i++){
        cin >> s;
        reverse(s.begin() , s.end());
        mem(dp , -1);
        cout << (sol(0 , 0) - 2 + mod) % mod << '\n';
    }
}

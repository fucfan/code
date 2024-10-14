#include <bits/stdc++.h>
using namespace std;

#define mask(i) (1 << (i))
#define BIT(x, i) ((x) >> (i) & 1)
#define turnOn(x, i) ((x) | (1 << (i)))
using namespace std;
const int N = 1005;

int n;
int a[N][N], dp[30][mask(18)];
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; ++i) dp[i][mask(i - 1)] = 0;
    for(int MASK = 0; MASK < mask(n); ++MASK){
        for(int i = 1; i <= n; ++i){
            if(BIT(MASK, i - 1)) continue;
            for(int j = 0; j < n; ++j){
                if(MASK & mask(j)){
                    dp[i][turnOn(MASK, i - 1)] = min(dp[i][turnOn(MASK, i - 1)], dp[j + 1][MASK] + a[j + 1][i]);
                    // cout << i << " " << j + 1 << " " << dp[i][turnOn(MASK, i - 1)] << endl;
                }
            }
        }
    }
    int total = 1e9;
    for(int i = 0; i < n; ++i){
        total = min(total, dp[i + 1][mask(n) - 1]);
    }
    cout << total;
}
#include <bits/stdc++.h>
using namespace std;
int n , k , gen[5001];
string s;
long long ans , f[5001][5001];
const int MOD = 1e9 + 7;
vector <int> check;
long long sol(int i , int cnt){
    if(i > n && abs(cnt) <= k){
        return 1;
    }
    if(f[i][cnt] != -1) return f[i][cnt];
    long long res = 0;
    if(abs(cnt) <= k)res += sol(i + 1 , gen[i]) % MOD;
    res = (res  + (sol(i + 1 , cnt + gen[i]) % MOD)) % MOD;
    f[i][cnt] = res;
    return res;
}
int main(){
    cin >> n >> k;
    cin >> s;
    memset(f , -1 , sizeof(f));
    for(int i = 1 ; i <= n ; i++){
        gen[i] = s[i - 1] - '0';
        if(gen[i] == 0) gen[i] = -1;
    }
    cout << sol(2 , gen[1]);
}
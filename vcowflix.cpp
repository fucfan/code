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
const int N = 2e5 + 5;
int n , c , w[N] , dp[N];
void inp()
{
    cin >> c >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> w[i];
    }
    sort(w + 1 , w + n + 1);
}

void solve()
{
    dp[0] = 1;
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = c ; j >= w[i] ; j--){
            if(dp[j - w[i]]) dp[j] = 1;
        }
    }
    for(int i = 1 ; i <= c ; i++){
        if(dp[i]) ans = i;
    }
    cout << ans;
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
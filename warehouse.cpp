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
#define file "warehouse"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , t , d , goods[N] , times[N];
ll dp[1030][130];
vector <int> res;
ll sol(int i , int sum_time){
    if(i > n){
        dp[i][sum_time] = 0;
        return 0;
    }
    if(dp[i][sum_time] != -1) return dp[i][sum_time];
    ll res = 0;
    if(i == 0){
        for(int j = 1 ; j <= n ; j++){
            res = max(res , sol(j , times[j]) + goods[j]);
        }
        return res;
    }
    for(int j = i + 1 ; j <= i + d ; j++){
        if(sum_time + times[j] <= t)
            res = max(res , sol(j , sum_time + times[j]) + goods[j]);
    }
    dp[i][sum_time] = res;
    return res;
}
void inp()
{
    cin >> n >> t >> d;
    // n = 1000; t = 100 ; d = 10;
    for(int i = 1 ; i <= n ; i++){
        cin >> goods[i];
        // goods[i] = i;
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> times[i];
        // times[i] = 1;
    }
}

void solve()
{
    mem(dp , -1);
    ll ans = sol(0 , 0);
    ll val = ans;
    int pos = 0;
    int trace_time = 0;
    for(int i = 1 ; i <= n ; i++){
        if(val == dp[i][times[i]] + goods[i]){
            pos = i;
            val = dp[i][times[i]];
            trace_time = times[i];
            res.pb(i);
        }
    }
    while(val){
        // cout << val << '\n';
        for(int i = pos + 1 ; i <= pos + d ; i++){
            if(val == dp[i][trace_time + times[i]] + goods[i] && dp[i][trace_time + times[i]] != -1){
                trace_time += times[i];
                val = dp[i][trace_time];
                pos = i;
                res.pb(i);
                break;
            }
        }
    }
    sort(all(res));
    // cout << ans;
    cout << ans << ' ' << res.size() << '\n';
    for(auto j : res) cout << j << ' ' ; 
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
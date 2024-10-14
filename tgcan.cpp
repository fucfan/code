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
int n;
ll a[N] , cnt[N] , pref[N] , maxnum;
ll ans;
ll P(ll a , ll b){
    if(b == 1) return a % mod;
    ll t = P(a , b / 2);
    if(b % 2 == 0) return (t * t) % mod;
    else return ((t * t) % mod * a % mod) % mod;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        maxnum = max(maxnum , a[i]);
        cnt[a[i]]++;
    }
}

void solve()
{
    for(int i = 1 ; i <= maxnum * 2 ; i++){
        pref[i] = pref[i - 1] + cnt[i];
    }
    // for(int i = 1 ; i <= maxnum * 2 ; i++){
    //     cout << pref[i] << ' ';
    // }
    // nl;
    for(int i = 1 ; i <= maxnum ; i++){
        if(cnt[i] >= 2){
            ans = (ans + (((((cnt[i] * (cnt[i] - 1)) % mod) * (P(2 , mod - 2) % mod)) % mod) * (pref[i * 2 - 1] - cnt[i])) % mod) % mod;
            ans = (ans + ((((((cnt[i] - 2) * (cnt[i] - 1)) % mod) * cnt[i]) % mod) * P(6 , mod - 2)) % mod) % mod;
            // ans = ans + (cnt[i] * (cnt[i] - 1) / 2)
            // cout << i << '\n';
        }
    }
    cout << ans % mod;
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
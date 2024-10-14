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
#define file "teleport"
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
ll pref[N] , a[N] , suma , sumb;
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i] > 0) suma += a[i];
        else sumb -= a[i];
    }
}

void solve()
{
    sort(a + 1 , a + 1 + n);
    for(int i = 1 ; i <= n ; i++){
        if(a[i] > 0) pref[i] = pref[i - 1] + a[i];
        else pref[i] = pref[i - 1] - a[i];
    }
    ll ans = oo;
    int mid = n;
    ll dis = 0;
    ans = min(ans , pref[n - 1]);
    for(int i = n - 1 ; i >= 1 ; i--){
        if(a[i] < 0) break;
        dis += (a[mid] - a[i]);
        // cout << i << ' ' << dis << ' ' << mid << '\n';
        int new_mid = (n + i) / 2;
        dis -= ((new_mid - i + 1) - (n - mid + 1)) * (a[mid] - a[new_mid]);
        // cout << i << ' ' << dis << ' ' << mid << ' ' << new_mid << '\n';
        mid = new_mid;
        ans = min(ans , dis + (pref[i - 1]));
    }
    for(int i = 1 ; i <= n ; i++) a[i] *= -1;
    sort(a + 1 , a + 1 + n);
    for(int i = 1 ; i <= n ; i++){
        if(a[i] > 0) pref[i] = pref[i - 1] + a[i];
        else pref[i] = pref[i - 1] - a[i];
    }
    mid = n;
    dis = 0;
    ans = min(ans , pref[n - 1]);
    for(int i = n - 1 ; i >= 1 ; i--){
        if(a[i] < 0) break;
        dis += (a[mid] - a[i]);
        // cout << i << ' ' << dis << ' ' << mid << '\n';
        int new_mid = (n + i) / 2;
        dis -= ((new_mid - i + 1) - (n - mid + 1)) * (a[mid] - a[new_mid]);
        // cout << i << ' ' << dis << ' ' << mid << ' ' << new_mid << '\n';
        mid = new_mid;
        ans = min(ans , dis + (pref[i - 1]));
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
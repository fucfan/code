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
#define file "wmt"
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int n , m , a[N][N];
ll pref[N][N] , res;
void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
            // a[i][j] = 1;
        }
        sort(a[i] + 1 , a[i] + 1 + m);
    }
}


void solve(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
            // cout << pref[i][j] << ' ';
        }
        // nl;
    }
    ll ans = 0;
    for(int i = 1 ; i < n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            ll l = 1;
            ll r = mod;
            ll val = oo;
            ll res = 0;
            while(l <= r){
                ll mid = (l + r) >> 1;
                int num1 = upper_bound(a[i] + 1 , a[i] + 1 + m , mid) - a[i] - 1;
                int num2 = upper_bound(a[j] + 1 , a[j] + 1 + m , mid) - a[j] - 1;
                if(num1 + num2 >= m) r = mid - 1, val = mid;
                else l = mid + 1;
            }
            int num1 = upper_bound(a[i] + 1 , a[i] + 1 + m , val) - a[i] - 1;
            int num2 = upper_bound(a[j] + 1 , a[j] + 1 + m , val) - a[j] - 1;
            // cout << val << '\n';
            res = val * num1 - (pref[i][num1] - pref[i - 1][num1]) + 
                  val * num2 - (pref[j][num2] - pref[j - 1][num2]) +
                  pref[i][m] - pref[i - 1][m] - pref[i][num1] + pref[i - 1][num1] - (val * (m - num1)) +
                  pref[j][m] - pref[j - 1][m] - pref[j][num2] + pref[j - 1][num2] - (val * (m - num2));
            ans += res;
        }
    }
    cout << ans;
}

void run_with_file(){
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UMU      */
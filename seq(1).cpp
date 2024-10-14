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
int n;
ll a[N] , pref[N] , b[N] , sum , ans , res;
vector <ll> num , cnt[N];
int bs(int l , int r , ll x){
    int mid = (l + r) / 2;
    if(num[mid] == x) return mid;
    if(num[mid] > x) return bs(l , mid - 1 , x);
    if(num[mid] < x) return bs(mid + 1 , r , x);
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
}

void solve()
{
    res = -1e18;
    for(int i = 1 ; i <= n ; i++){
        b[i] = a[i];
    }
    sort(b + 1 , b + 1 + n);
    for(int i = 2 ; i <= n + 1 ; i++){
        if(b[i] != b[i - 1]) num.pb(b[i - 1]);
    }
    for(int i = 1 ; i <= n ; i++){
        int pos = bs(0 , num.size() - 1 , a[i]);
        cnt[pos].pb(i);
    }
    for(int i = 0 ; i < num.size() ; i++){
        for(int j = cnt[i].size() - 1 ; j >= 1 ; j--){
            cnt[i][j] = pref[cnt[i][j]] - pref[cnt[i][j - 1]];
        }
    }
    for(int i = 0 ; i < num.size() ; i++){
        if(cnt[i].size() > 1){
            sum = 0;
            ans = -1e18;
            for(int j = 1 ; j < cnt[i].size() ; j++){
                sum = sum + cnt[i][j];
                ans = max(ans , sum);
                if(sum < 0){
                    sum = 0;
                }
            }
            res = max(res , ans + a[cnt[i][0]]);
        }
    }
    cout << res;
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
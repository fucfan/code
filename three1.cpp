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
#define file "three"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;
int n , ans;
ll pref[N] , k , a[N];
void inp()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
}

void solve()
{
    int l = 1;
    int r = n / 3;
    while(l <= r){
        int mid = (l + r) / 2;
        bool check = false;
        int cnt = 0;
        for(int i = 0 ; i <= n - (3 * mid) ; i++){
            int st = i;
            int ed = mid + i;
            cnt = 0;
            for(int j = 1 ; j <= 3 ; j++){ 
                ll val = pref[ed] - pref[st];
                if(val <= k){
                    st = ed;
                    ed = ed + mid;
                    cnt++;
                }
            }
            if(cnt == 3){
                check = true;
                break;
            }
        }
        if(check){
            l = mid + 1;
            ans = max(ans , mid);
        }
        else r = mid - 1;
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
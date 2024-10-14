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
const int N = 2e6 + 5;
int n , k , a[N] , cnt[N] , ans , b[N] , arr[N];
vector <int> divisor[N];
void sieve(){
    for(int i = 2 ; i <= 1000 ; i++){
        for(int j = i * i ; j <= 1000000 ; j += i){
            // cout << j << '\n';
            divisor[j].pb(i);
        }
    }
}
// bool bs(int l , int r , int x){
//     int mid = (l + r) / 2;
//     if(l == r){
//         if(a[mid] == x) return 1;
//         return 0;
//     }
//     if(a[mid] >= x) return bs(l , mid , x);
//     if(a[mid] < x) return bs(mid , r , x);
// }
void inp()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        b[i] = a[i];
        cnt[a[i]]++;
    }
}

void solve()
{
    sort(b + 1 , b + 1 + n);
    for(int i = 1 ; i <= n ; i++){
        arr[b[i]] = i;
    }
    sieve();
    for(int i = 1 ; i <= n ; i++){
        ans = 0;
        if(a[i] >= k){
            if(a[i] == k){
                ans += n - arr[a[i]];
            }
            else{
                for(auto j : divisor[a[i] - k]){
                    if(j > k) ans += cnt[j];
                    if((a[i] - k) / j > k && (a[i] - k) / j != j) ans += cnt[(a[i] - k) / j];
                }
                if(a[i] - k > k){
                    ans += cnt[a[i] - k];
                    if(k == 0){
                        ans--;
                        if(a[i] - k != 1)ans += cnt[1];
                    }
                }
            }
        }
        cout << ans << ' ';
    }
}

void run_with_file()
{
//    if(fopen(file".inp","r")){
//        freopen(file".inp","r", stdin);
//        freopen(file".out", "w", stdout);
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
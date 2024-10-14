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
#define file "thuemay"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , m , a[N] , cnt[N] , ans , res;
vector <int> day[N];
void sol(int i){
    // cout << i << ' ' << ans << '\n';
    if(i > m){
        res = max(res , ans);
        return;
    }
    bool check = true;
    for(auto j : day[i]){
        cnt[j]++;
        ans++;
        if(cnt[j] > n) check = false;
    }
    if(check){
        sol(i + 1);
    }
    for(auto j : day[i]){
        ans--;
        cnt[j]--;
    }
    sol(i + 1);
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        cin >> a[i];
        for(int j = 1 ; j <= a[i] ; j++){
            int k;
            cin >> k;
            day[i].pb(k);
       }
    }
}

void solve()
{
    sol(1);
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
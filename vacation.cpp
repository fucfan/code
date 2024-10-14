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
int n , a[N] , b[N] , c[N] , f[N][4];
ll hap(int i , int pre){
    if(i > n) return 0;
    if(f[i][pre] != -1) return f[i][pre];
    ll ans = 0;
    // if(pre == 1 && cnt < 2)ans = max(hap(i + 1 , 1 , cnt + 1) + a[i] , ans);
    if(pre != 1)ans = max(hap(i + 1 , 1) + a[i] , ans);
    // if(pre == 2 && cnt < 2)ans = max(hap(i + 1 , 2 , cnt + 1) + b[i] , ans);
    if(pre != 2)ans = max(hap(i + 1 , 2) + b[i] , ans);
    // if(pre == 3 && cnt < 2)ans = max(hap(i + 1 , 3 , cnt + 1) + c[i] , ans);
    if(pre != 3)ans = max(hap(i + 1 , 3) + c[i] , ans);
    f[i][pre] = ans;
    return ans;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
}

void solve()
{
    mem(f , -1);
    cout << hap(1 , 0);
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
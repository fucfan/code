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
#define file "us"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int t;
ll sum[N] , cnt[N];
void sieve(){
    for(int i = 2 ; i <= 1e6 ; i++){
        for(int j = i ; j <= 1e6 ; j += i){
            sum[j] += i;
            cnt[j]++;
        }
    }
    for(int i = 1 ; i <= 1e6 ; i++){
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
    }
}
void inp()
{
    cin >> t;
    sieve();
    for(int i = 1 ; i <= t ; i++){
        int a , b;
        // a = 1;
        // b = 1000000;
        cin >> a >> b;
        // cout << sum[b] << ' '<< sum[a - 1] << '\n';
        cout << cnt[b] - cnt[a - 1] + (b - a + 1) << ' ' << sum[b] - sum[a - 1] + (b - a + 1) << '\n';
    }
    // cout << clock() / 1000.0 << '\n';
}

void solve()
{
    
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
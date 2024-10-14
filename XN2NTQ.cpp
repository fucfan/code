#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define turnOn(x , i ) ((x) | (1 << (i)))
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "XN2NTQ"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 100;
const int LOG = 20;
int n , a[N] , ans , dp[30][N];
pii cnt[N];
bool notprime[N] , vst[N];
void sieve(){
    notprime[1] = notprime[0] = 1;
    for(int i = 2 ; 1ll * i * i <= 2e6 ; i++){
        // cout << 1ll * i * i << '\n';
        if(notprime[i]) continue;
        for(int j = i * i ; j <= 2e6 ; j += i){
            notprime[j] = 1;
        }
    }
}
void sub2(){
    for(int i = 1 ; i <= n ; i++){
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            if(BIT(mask , i - 1)) break;
            for(int j = 1 ; j < i ; j++){
                if(BIT(mask , j - 1)) continue;
                dp[i][mask] = max(dp[i][mask] , dp[i - 1][mask]);
                if(!notprime[a[i] + a[j]]){
                    // cout << i << ' ' << j << '\n';
                    maxi(dp[i + 1][turnOn(mask , i - 1) | turnOn(mask , j - 1)] , dp[i][mask] + 1);
                    maxi(ans , dp[i + 1][turnOn(mask , i - 1) | turnOn(mask , j - 1)]);
                }
            }
        }
    }
    cout << ans;
}
void sub3(){
    for(int i = 1 ; i < n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            if(!notprime[a[i] + a[j]]){
                cnt[i].fi++;
                cnt[j].fi++;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++) cnt[i].se = a[i];
    sort(cnt + 1 , cnt + 1 + n);
    for(int i = 1 ; i < n ; i++){
        if(vst[i]) continue;
        for(int j = i + 1 ; j <= n ; j++){
            if(vst[j] || notprime[cnt[i].se + cnt[j].se]) continue;
            vst[i] = 1;
            vst[j] = 1;
            // cout << cnt[i].se << ' ' <<  cnt[j].se << '\n';
            ans++;
            break;
        }
    }
    cout << ans;
}
void sub5(){
    cout << n / 2;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        // a[i] = i;
    }
    sieve();
    if(n <= 1000) sub3();
    else sub5();
}

void solve()
{
}

void run_with_file()
{
    if (fopen(file".inp", "r"))
    {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
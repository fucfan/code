#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "triple"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 123456789;
const int N = 2e5 + 5;
const int LOG = 20;
int n;
string k;
bool check[12][N];
pii dp[N][12];
void inp()
{
	cin >> k >> n;
}

void solve()
{
    ll ans = 0;
    for(auto j : k){
        ans = ((ans * dp[n][j - '0'].se) % mod + dp[n][j - '0'].fi) % mod;
    }
    cout << ans << '\n';
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
    for(int i = 1 ; i <= 1e5 ; i++) dp[i][0] = {0 , 10};
    for(int i = 1 ; i <= 9 ; i++) dp[0][i] = {i , 10};
    for(int i = 1 ; i <= 1e5 ; i++){
        for(int j = 1 ; j <= 9 ; j++){
            int val = j * 3;
            if(val / 10 == 0){
                dp[i][j] = dp[i - 1][val];
            }
            else{
                dp[i][j].fi = ((dp[i - 1][val / 10].fi * dp[i - 1][val % 10].se) % mod + dp[i - 1][val % 10].fi) % mod;
                dp[i][j].se = (dp[i - 1][val / 10].se * dp[i - 1][val % 10].se) % mod;
            }
        }
    }
    cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
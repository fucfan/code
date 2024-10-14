#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define         pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "slime"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , s , a[N] , cnt[N] , imp , sz;
ll pw_2[N] , fact[N];
vector <int> order;
ll dp[50][N];

void prepare(){
    int k = s;
    while(k % 2 == 0){
        imp += cnt[k];
        k /= 2;
        order.pb(k);
    }

    imp += cnt[k];

    sort(all(order));

    pw_2[0] = fact[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        pw_2[i] = (pw_2[i - 1] * 2) % mod;
    }

    for(int i = 1 ; i <= n ; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    sz = order.size();
}

ll Pow(ll a , ll b){
    b--;
    ll tmp = a;
    while(b){
        if(b & 1) (a *= tmp) %= mod;
        (tmp *= tmp) %= mod;
        b >>= 1;
    }
    return a;
}

ll nCk(int n , int k){
    return (fact[n] * Pow((fact[k] * fact[n - k]) % mod , mod - 2)) % mod;
}

ll sol(int i , int last){
    // cout << i << ' ' << last << '\n';
    if(i == sz){
        return (pw_2[cnt[s]] - (last == 0));
    }
    if(dp[i][last] != -1) return dp[i][last];
    ll res = 0;
    for(int j = 0 ; j <= cnt[order[i]] ; j++){
        (res += (sol(i + 1 , (j + last) / 2) * nCk(cnt[order[i]] , j)) % mod) %= mod; 
    }
    return dp[i][last] = res;
}

void inp()
{
    cin >> n >> s;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
}

void solve()
{
    prepare();
    mem(dp , -1);
    cout << (sol(0 , 0) * pw_2[n - imp]) % mod;
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
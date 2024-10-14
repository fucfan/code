#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
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
#define file "trie"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , a[N] , sz[N] , num_a[N] , num_b[N] , cnt;
ll inv[N] , fact[N];

ll Pow(ll a , ll b){
    ll tmp = a;
    b--;
    while(b){
        if(b & 1) (a *= tmp) %= mod;
        (tmp *= tmp) %= mod;
        b >>= 1;
    }
    return a;
}

void prepare(){
    fact[0] = 1;
    for(int i = 1 ; i <= N - 1 ; i++){
        fact[i] = (fact[i - 1] * i) % mod;
        // cout << i << ' ' << fact[i] << '\n';
    }

    inv[N - 1] = Pow(fact[N - 1] , mod - 2);

    for(int i = N - 1 ; i >= 1 ; i--){
        inv[i - 1] = (inv[i] * i) % mod;
    }
}

ll nCk(int n , int k){
    return (fact[n] * ((inv[k] * inv[n - k]) % mod) % mod);
}

void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        string s;

        cin >> s;

        sz[i] = s.size();

        for(int j = 0 ; j < sz[i] ; j++){
            if(s[j] == 'a') num_a[i]++;
            else num_b[i]++;
        }
    }
}

void solve()
{
    prepare();
    ll ans = 0;
    for(int mask = 1 ; mask < (1 << n) ; mask++){
        int a = oo , b = oo;

        for(int i = 1 ; i <= n ; i++){
            if(!BIT(mask , i - 1)) continue;

            a = min(a , num_a[i]);
            b = min(b , num_b[i]);
        }

        // cout << a + b + 2 << ' ' << a + 1 << ' ' << nCk(a + b + 2 , a + 1) - 1 << '\n';
        // cout << fact[a + b + 2] << ' ' << inv[a + 1] << ' ' << nCk(a + b + 2 , a + 1) - 1 << '\n';

        int tmp = __builtin_popcount(mask);

        if(tmp % 2) (ans += nCk(a + b + 2 , a + 1) - 1) %= mod;
        else{
            ans -= nCk(a + b + 2 , a + 1) - 1;
            (ans += mod * mod) %= mod;
        }  
    }
    cout << ans;
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
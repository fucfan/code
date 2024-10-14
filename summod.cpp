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
ll a , b , c , ans , st , en , last;
ll P(ll a , ll b){
    if(b == 1) return a % mod;
    ll t = P(a , b / 2);
    if(b % 2) return (((t % mod) * (t % mod)) % mod * (a % mod)) % mod;
    return((t % mod) * (t % mod)) % mod;
}
void inp()
{
    cin >> a >> b >> c;
    if(c < b){
        ans = ans + c * (b - max(c , a));
    }
    st = 2;
    b = min(b , c);
    last = min(b , c - 1);
    en = a + 1;
    while(en >= a){
        bool check = false;
        en = c / st + 1;
        if(en < a){
            en = a;
            check = true;
        }
        ll x = (last - en + 1) % mod;
        ll y = (c % last + c % en) % mod;
        ans = (ans + (((x * y) % mod) * P(2 , mod - 2)) % mod) % mod;
        if(en == 1) break;
        st = (c / (en - 1)) + 1;
        last = en - 1;
        if(check) break;
    }
    cout << ans % mod;
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
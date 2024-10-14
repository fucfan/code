#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const ll oo = 1e9 + 7;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 5;
ll q , P[10000007] , a[N] , b[N] , k[N];
vector <ll> pri[N];
void Pr(){
    for(ll i = 2 ; i <= 10000000 ; i++){
        if(P[i] == 0){
            P[i]++;
            for(ll j = i + i ; j <= 10000000 ; j = j + i){
                P[j]++;
            }
        }
    }
}
ll bs(ll l , ll r , ll x , ll k , int type){
    // cout << l << ' ' << r << ' ' << pri[k][l] << ' ' << pri[k][r] << '\n';
    if(r - l <= 1){
        if(type == 1){
            if(x <= pri[k][l]) return l;
            else return r;
        }
        if(type == 2){
            if(x >= pri[k][r]) return r;
            else return l;
        }
    }
    ll mid = (l + r) / 2;
    if(pri[k][mid] == x) return mid;
    if(pri[k][mid] > x) return bs(l , mid , x , k , type);
    if(pri[k][mid] < x) return bs(mid , r , x , k , type);
}
void inp()
{
    cin >> q;
    for(ll i = 1 ; i <= q ; i++){
        cin >> a[i] >> b[i] >> k[i];
    }
}

void solve()
{
    Pr();
    for(ll i = 1 ; i <= 1000000 ; i++){
        if(pri[P[i]].empty()) pri[P[i]].pb(0);
        pri[P[i]].pb(i);
    }
    // for(auto i : pri[2]) cout << i << '\n';
    // cout << pri[1][39767] << '\n';
    for(ll i = 1 ; i <= q ; i++){
        ll x = bs(0 , pri[k[i]].size() - 1 , b[i] , k[i] , 2);
        ll y = bs(0 , pri[k[i]].size() - 1 , a[i] , k[i] , 1);
        ll ans = x - y + 1;
        // if()
        cout << ans << '\n';
    }
    // cout << bs(0 , pri[1].size() - 1 , 7 , 1) << '\n';
    // cout << bs(0 , pri[1].size() - 1 , 10 , 1);
    // cout << pri[1][7] << '\n';
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
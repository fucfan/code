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
const int N = 1e6 + 5;
ll n , POW , cnt;
bool pr[N];
void prime(){
    for(ll i = 2 ; i <= N ; i++){
        if(!pr[i] && (i * i) <= N){
            for(ll j = i * i ; j <= N ; j = j + i){
                pr[j] = true;
            }
        }
    }
}
bool pri(long k){
    for(long i = 2 ; i <= sqrt(k) ; i++){
        if(k % i == 0) return true;
    }
    return false;
}
void inp()
{
    cin >> n;
}

void solve()
{
    ll m = sqrt(n);
    if(m * m == n){
        if(!pri(m)){
            cout << m << ' ' << 2;
            exit(0);
        }
    }
    prime();
    for(long i = 2 ; i <= N ; i++){
        if(n % i == 0 && pri(i)){
            cout << 0;
            exit(0);
        }
        if(n % i == 0){
            POW = 1;
            while(POW < n){
                POW = POW * i;
                cnt++;
            }
            if(POW != n) cout << 0;
            else if(cnt > 1) cout << i << ' ' << cnt;
            else cout << 0;
            exit(0);
        }
    }
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
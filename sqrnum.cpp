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
#define file "sqrnum"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
vector <int> divisor[N];
int val(ll k , ll divi){
    int s = 0;
    while(k % divi == 0){
        k = k / divi;
        s++;
    }
    return s;
}
void sieve(){
    for(int i = 2 ; i <= 1e6 ; i++){
        if(divisor[i].empty()){
            for(ll j = i ; j <= 1e6 ; j = j + i){
                int cnt = val(j , i);
                for(int k = 1 ; k <= cnt ; k++){
                    divisor[j].pb(i);
                }
            }
        }
    }
}
int n , cnt[N] , q , odd;
bool ans;
void check(int s){
    // cout << divisor[s].size() << "asdjsalkdjsl\n";
    if(!divisor[s].empty()){
        int key = cnt[divisor[s][0]];
        for(int j = 0 ; j < divisor[s].size() ; j++){
            cnt[divisor[s][j]]++;
            // cout << divisor[s][j] << ' ' << cnt[divisor[s][j]] << '\n';
            if(divisor[s][j] != divisor[s][j - 1] && j > 0){
                if(cnt[divisor[s][j - 1]] % 2 == 1){
                    if(key % 2 == 0) odd++;
                    key = cnt[divisor[s][j]] - 1;
                }
                else{
                    if(key % 2 == 1) odd--;
                    key = cnt[divisor[s][j]] - 1;
                }
            }
        }
        // nl;
        // if(cnt[divisor[s][divisor[s].size() - 1]] % 2 == 1){
        //     if(key % 2 == 0){
        //         odd++;
        //     }
        // }
        // else{
        //     if(key % 2 == 1){
        //         odd++;
        //     }
        // }
        // cout << key << ' ' << odd << '\n';
        if(odd == 0) ans = true;
        else ans = false;
    }
}
void inp()
{
    sieve();
    for(int i = 2 ; i <= 1e6 ; i++){
        divisor[i].pb(0);
    }
    cin >> n;
    ans = true;
    for(int i = 1 ; i <= n ; i++){
        cin >> q;
        // q = 1e5 + 7;
        check(q);
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
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
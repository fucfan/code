#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "timso"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int l, r;
bool not_prime[N];
vector <int> prime;

void sieve(){
    not_prime[1] = not_prime[0] = 1;
    for(int i = 2; i * i < N; i++){
        if(not_prime[i]) continue;
        for(int j = i * i; j < N; j += i){
            not_prime[j] = 1;
        }
    }
    for(int i = 2 ; i < N; i++){
        if(!not_prime[i]) prime.pb(i);
    }
}

int sol(ll num){
    if(num < 2) return 0;
    for(auto j : prime){
        if(j > sqrt(num)) break;
        if(num % j == 0) return 0;
    }
    return 1;
}

ll reverse_num(int num){
    ll res = 0;
    // cout << num << "gg\n";
    while(num){
        res = res * 10 + num % 10;
        num /= 10;
    }
    // cout << res << '\n';
    return res;
}

void inp(){
    cin >> l >> r;
}

void solve(){
    sieve();
    for(int i = l; i <= r; i++){
        if(sol(reverse_num(i))){
            cout << i << '\n';
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    // cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
    // Times;
}

/*      UwU      */

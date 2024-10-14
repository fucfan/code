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
#define file "task"
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

int x;

void inp(){
    cin >> x;
}

void solve(){
    if(x == 1){
        cout << 1 << '\n' << 1 << '\n';
    }
    else if(x == 2) cout << 2 << '\n' << "1 2 \n";
    else if(x == (1 << 32 - __builtin_clz(x + 1)) - 2){
        // cout << x << ' ';
        cout << __builtin_popcount(x) + 1 << '\n';
        cout << x << ' ';
        for(int i = 0 ; i <= LOG ; i++){
            if(BIT(x , i)){
                cout << (flip(x , i) | 1) << ' ';
            }
        }
        nl;
    }
    else{
        x = (1 << 31 - __builtin_clz(x + 1)) - 1;
        // cout << x << ' ';
        cout << __builtin_popcount(x) << '\n';
        // cout << x << ' ';
        for(int i = 0 ; i <= LOG ; i++){
            if(BIT(x , i)){
                cout << flip(x , i) << ' ';
            }
        }
        nl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
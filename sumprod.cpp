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
#define file "sumprod"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n;

void cal(int num_pow , int st){

    int num1 = ((int)n - num_pow) / (st - 1);
    int num2 = ((int)n - num_pow) % (st - 1);
    
    for(int i = 1 ; i <= num_pow - num1 - 1 ; i++) cout << st;
    cout << st - num2;
    for(int i = 1 ; i <= num1 * st + num2 ; i++) cout << 1; 
    nl;
} 

void inp(){
    cin >> n;
}

void solve(){
    int num_pow = -1;
    int st = -1;
    for(int i = 2 ; i <= 9 ; i++){
        int cur = 1;
        for(int j = 1 ; j <= n ; j++){
            if(cur * i > n){
                if(cur > num_pow){
                    num_pow = cur;
                    st = i;
                }
                else if(cur == num_pow){
                    st = i;
                }
                break;
            }
            cur = cur * i;
        }
    }

    cal(num_pow , st);
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
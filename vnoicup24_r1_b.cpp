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
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9;
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

int n;
ll a[N] , b[N];

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int j = 1 ; j <= n ; j++) cin >> b[j];
}

void solve(){
    for(int i = n ; i >= 1 ; i--){
        if(a[i] < b[i]){
            ll val = b[i] - a[i];
            for(int j = i - 1 ; j >= max(1 , i - 30); j--){
                if(a[j] > b[j]){
                    if(val > (a[j] - b[j]) / (1ll << (i - j))){
                        val -= (a[j] - b[j]) / (1ll << (i - j));
                        a[i] += (a[j] - b[j]) / (1ll << (i - j));
                        a[j] -= (a[j] - b[j]) / (1ll << (i - j)) * (1ll << (i - j));
                    }
                    else{
                        a[j] -= val * (1ll << (i - j));
                        val = 0;
                        a[i] = b[i];
                        break;
                    }
                }
            }
        }
        else if(a[i] > b[i]){
            a[i - 1] += min((a[i] - b[i]) * 2 , 2ll * oo);
            a[i] -= min((a[i] - b[i]) , 1ll * oo);
        }

        // for(int i = 0 ; i <= n ; i++){
        //     cout << a[i] << ' ';
        // }
        // nl;
    }
    for(int i = 0 ; i <= n ; i++){
        if(a[i] > b[i]){
            a[i + 1] += (a[i] - b[i]) / 2;
            a[i] -= (a[i] - b[i]) / 2 * 2;
        }
        // for(int i = 0 ; i <= n ; i++){
        //     cout << a[i] << ' ';
        // }
        // nl;
    }

    // for(int i = 0 ; i <= n ; i++){
    //     cout << a[i] << ' ';
    // }
    a[0] = 0;

    for(int i = 1 ; i <= n ; i++){
        if(a[i] < b[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
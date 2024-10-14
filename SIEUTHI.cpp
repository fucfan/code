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
#define file "sieuthi"
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

int n, m, a[N], mx;
int capa[N];

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
}

void solve(){
    int ans = oo;
    sort(a + 1, a + 1 + n, greater<>());
    for(int sz = mx; sz <= m; sz++){
        for(int i = 1; i <= n; i++){
            int id = n, Min = oo;
            for(int j = 1; j <= n; j++){
                if(capa[j] + a[i] <= sz) 
                    if(mini(Min, sz - capa[j] - a[i])){
                        id = j;
                    }
            }
            capa[id] += a[i];
        }
        int val = 0;
        for(int i = 1; i <= n; i++){
            if(capa[i]) val++, capa[i] = 0;
        }
        ans = min(ans, val);
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
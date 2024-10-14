#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<long double, long double>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "shift"
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

int n;
pii p[N];
pii line;

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i].fi >> p[i].se;
    }
}

void solve(){
    line.fi = (p[1].se - p[2].se) / (p[1].fi - p[2].fi);
    line.se = (p[1].se - p[1].fi * line.fi);

    for(int i = 3; i <= n; i++){
        // cout << i << ' ' << line.fi * p[i].fi + line.se << ' ' << p[i].se << '\n';
        if(line.fi * p[i].fi + line.se != p[i].se){
            cout << "YES\n";
            cout << 1 << ' ' << 2 << ' ' << i;
            exit(0);
        }
    }

    cout << "NO";
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
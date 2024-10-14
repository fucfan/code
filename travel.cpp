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
#define file "travel"
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

int n, c[N], t[N];

namespace sub1{
    bool check(){ return n <= 2000; }

    bool cal(int st){
        ll cost = t[st] - c[st];
        if(cost < 0) return 0;
        for(int i = (st % n) + 1; i != st; i = (i % n) + 1){
            cost += t[i] - c[i];
            if(cost < 0) return 0;
        }
        return 1;
    }

    void solve(){
        for(int i = 1; i <= n; i++){
            if(cal(i)){
                cout << i;
                exit(0);
            }
        }
        cout << -1;
    }
}

namespace sub2{
    ll val[N];
    multiset <ll> st;
    bool check() { return 1; }

    void solve(){
        for(int i = 1; i <= n; i++){
            val[i] = val[i - 1] + t[i] - c[i];
            // cout << val[i] << '\n';
            st.insert(val[i]);
        }

        ll cur = 0;
        ll pre = val[n];

        for(int i = 1; i <= n; i++){
            // cout << i << ' ' << *st.begin() << ' ' << cur << ' ' << pre + t[i] - c[i] << '\n';
            if(*st.begin() < cur){
                st.erase(st.lower_bound(val[i]));
                cur += t[i] - c[i];
                pre += t[i] - c[i];
                st.insert(pre);
            }
            else{
                cout << i;
                exit(0);
            }
        }

        cout << -1;
    }
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i] >> t[i];
    }
}

void solve(){
    if(sub1::check()) return sub1::solve(), void();
    if(sub2::check()) return sub2::solve(), void();
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
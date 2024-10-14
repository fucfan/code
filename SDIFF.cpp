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
#define file "sdiff"
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

int n, a[N], p, q, m, k;

void inp(){
    cin >> n;
    cin >> p >> q >> m;
    for(int i = 1; i <= n; i++){
        a[i] = (1ll * p * i + q) % m;
        // cout << a[i] << ' ';
    }
    // nl;
    cin >> k;
}

void solve(){
    int j = 1;
    deque <int> q1, q2;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(q1.empty()) q1.pb(i);
        else{
            if(a[q1.front()] < a[i]) q1.push_front(i);
            else{
                while(a[q1.back()] < a[i]) q1.pop_back();
                q1.push_back(i);
            }
        }
        if(q2.empty()) q2.pb(i);
        else{
            if(a[q2.front()] > a[i]) q2.push_front(i);
            else{
                while(a[q2.back()] < a[i]) q2.pop_back();
                q2.push_back(i);
            }
        }

        while(q1.front() - q2.front() > k){
            if(q1.front() < q2.front())q1.pop_front();
            else q2.pop_front();
        }

        ans += (i - min(q1.front(), q2.front()) + 1);
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
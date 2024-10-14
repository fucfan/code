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
#define file "socola"
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

int n, q, a[N];

struct Query{
    int k, m;

    void input(){
        cin >> k >> m;
    }
} query[N];

namespace sub1{
    int cost[N];

    bool check(){
        return (n <= 1000 && q <= 1000);
    }

    void solve(){
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= q; i++){
            int k = query[i].k;
            int m = query[i].m;
            for(int i = 1; i <= n; i++){
                if(a[i] >= k) cost[i] = 2 * k - a[i];
                else cost[i] = a[i];
            }
            sort(cost + 1, cost + 1 + n);
            int res = 0;
            for(int i = 1; i <= m; i++){
                res += cost[i];
            }

            cout << res << '\n';
        }
    }
}

namespace sub2{
    ll val[N];

    bool check(){
        for(int i = 2; i <= q; i++){
            if(query[i].k != query[i - 1].k) return 0;
        }
        return 1;
    }

    void solve(){
        int k = query[1].k;
        sort(a + 1, a + 1 + n);
        ll Max = 0;
        ll sum = 0;
        int l = 0;
        int r = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] >= k) a[i] = 2 * k - a[i];

            if(maxi(Max, a[i])){
                l = i;
                r = i;
                val[1] = a[i];
            }
            sum += a[i];
            // cout << a[i] << ' ';
        }
        // nl;

        for(int i = 2; i <= n; i++){
            if(r == n || (a[l - 1] >= a[r + 1] && l != 1)){
                val[i] = val[i - 1] + a[l - 1];
                l--;
            // cout << l << ' ' << r << ' ' << val[i] << "gg\n";
                continue;
            }
            if(l == 1 || (a[l - 1] <= a[r + 1] && r != n)){
                val[i] = val[i - 1] + a[r + 1];
                r++;
            }
        }

        for(int i = 1; i <= q; i++){
            int m = query[i].m;
            cout << sum - val[n - m] << '\n';
        }
    }
}

void inp(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++) query[i].input();
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
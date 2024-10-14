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
#define file "tree"
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

bool not_prime[N];
vector <int> prime, adj[N];
int n, q, a[N], query[N], pos[N], cnt[N];

void sieve(){
    not_prime[0] = not_prime[1] = 1;

    for(int i = 2; i * i < N; i++){
        if(not_prime[i]) continue;
        for(int j = i * i; j < N; j += i){
            not_prime[j] = 1;
        }
    }

    for(int i = 2; i < N; i++){
        if(!not_prime[i]){
            prime.pb(i);
            pos[i] = prime.size();
            cnt[prime.size()] = 1;
        }
    }
}

int Pow(int a, int b){
    if(!b) return 1;
    b--;
    for(int tmp = a; b > 0; b >>= 1, tmp = 1ll * tmp * tmp % mod){
        if(b & 1) a = 1ll * a * tmp % mod;
    }
    return a;
}

namespace sub2{
    int res = 1;
    int par[N];

    bool check(){
        return ((n <= 1000 && q <= 1000) || (n <= 100000 && q <= 5));
    }

    void get_par(int i, int p){
        par[i] = p;
        for(auto j : adj[i]){
            if(j == p) continue;
            get_par(j, i);
        }
    }

    void cal(int num){
        for(auto j : prime){
            if(num % j == 0){
                // cout << j << ' ' << cnt[pos[j]] << ' ' << res << ' ' << Pow(cnt[pos[j]], mod - 2) << "gg\n";
                res = 1ll * res * Pow(cnt[pos[j]], mod - 2) % mod;
                while(num % j == 0){
                    num /= j;
                    cnt[pos[j]]++;
                }
                // cout << j << ' ' << cnt[pos[j]] << ' ' << res << "gg\n";
                res = 1ll * res * cnt[pos[j]] % mod;
            }
            if(j > num) break;
        }
    }

    void dfs(int i, int p){
        cal(a[i]);
        // cout << i << ' ' << res << '\n';
        // for(int j = 1; j <= 10; j++) cout << prime[j - 1] << '/' << cnt[j] << ' ';
        // nl;
        for(auto j : adj[i]){
            if(j == p) continue;
            dfs(j, i);
        }
    }

    void solve(){
        get_par(1, 0);
        for(int i = 1; i <= q; i++){
            int node = query[i];
            dfs(node, par[node]);
            cout << res << ' ';
            res = 1;
            for(int j = 1; j <= (int)prime.size(); j++) cnt[j] = 1;
        }
    }
}

namespace sub5{
    bool check(){
        return 1;
    }

    int sz[N], ans[N], cur = 1;
    vector <int> vt[N];

    void cal(int num){
        for(auto j : prime){
            if(num % j == 0){
                cur = 1ll * cur * Pow(cnt[pos[j]], mod - 2) % mod;
                while(num % j == 0){
                    num /= j;
                    cnt[pos[j]]++;
                }
                cur = 1ll * cur * cnt[pos[j]] % mod;
            }
            if(j > num) break;
        }
    }

    void get_sz(int i, int p){
        sz[i] = 1;
        for(auto j : adj[i]){
            if(j == p) continue;
            get_sz(j, i);
            sz[i] += sz[j];
        }
    }

    void sack(int i, int p, int keep){
        // cout << 1;
        int mx = 0;
        int best_node = -1;
        for(auto j : adj[i]){
            if(j == p) continue;
            if(maxi(mx, sz[j])) best_node = j;
        }

        for(auto j : adj[i]){
            if(j == p || j == best_node) continue;
            sack(j, i, 0);
        }

        if(best_node != -1){
            sack(best_node, i, 1);
            swap(vt[i], vt[best_node]);
        }

        // cout << i << ' ' << cur << ' ' << best_node << '\n';
        // for(int j = 1; j <= 10; j++) cout << prime[j - 1] << '/' << cnt[j] << ' ';
        // nl;

        for(auto j : adj[i]){
            if(j == p || j == best_node) continue;
            for(auto x : vt[j]){
                // cout << x << ' ';
                cal(a[x]);
                vt[i].pb(x);
            }
        }
        // nl;

        vt[i].pb(i);
        cal(a[i]);

        ans[i] = cur;

        if(!keep){
            for(int j = 1; j <= (int)prime.size(); j++) cnt[j] = 1;
            cur = 1;
        }
    }

    void prepare(){
        cur = 1;
        for(int i = 1; i <= (int)prime.size(); i++) cnt[i] = 1;
        get_sz(1, 0);
        sack(1, 0, 1);
    }

    void solve(){
        prepare();
        for(int i = 1; i <= q; i++){
            cout << ans[query[i]] << ' ';
        }
    }
}

void inp(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= q; i++){
        cin >> query[i];
    }
    sieve();
}

void solve(){
    if(sub2::check()) return sub2::solve();
    if(sub5::check()) return sub5::solve();
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
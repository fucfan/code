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
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m, k;
int a[N][N];
int comp_id[N * N];
vector <pii> comp[N];

struct BIT{
    int node[N];
    int sz;

    void update(int pos, int val){
        for(;pos <= sz; pos += (pos & -pos)){
            node[pos] = max(node[pos], val);
        }
    }

    void reset(int pos){
        for(;pos <= sz; pos += (pos & -pos)){
            node[pos] = 0;
        }
    }

    int get(int pos){
        int res = 0;
        for(; pos > 0; pos -= (pos & -pos)){
            res = max(res, node[pos]);
        }
        return res;
    }
} col[N], row[N];

void prepare(){
    for(int i = 1; i <= n; i++){
        row[i].sz = m;
    }
    for(int i = 1; i <= m; i++){
        col[i].sz = n;
    }
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= k; i++){
        int p;
        cin >> p;
        for(int j = 1; j <= p; j++){
            int x;
            cin >> x;
            comp_id[x] = i;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            comp[comp_id[a[i][j]]].pb({i, j});
        }
    }
}

void solve(){
    prepare();  
    for(int i = 1; i <= k; i++){
        sort(all(comp[i]));
        int res = 0;
        for(auto j : comp[i]){
            int val = 0;
            if(j.fi > 1) val = max(val, col[j.se].get(j.fi - 1));
            if(j.se > 1) val = max(val, row[j.fi].get(j.se - 1));
            col[j.se].update(j.fi, val + 1);
            row[j.fi].update(j.se, val + 1);
            res = max(res, val + 1);
            cout << i << ' ' << j.fi << ' ' << j.se << ' ' << val + 1 << '\n';
        }
        cout << res << '\n';
        for(auto j : comp[i]){
            col[j.se].reset(j.fi);
            row[j.fi].reset(j.se);
        }
    }
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
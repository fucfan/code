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
#define file "split"
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

int n, m, cnt, col[N];
pii sz[N];
bool vst[N];
vector <int> adj[N]; 

void dfs(int i){
    // cout << i << '\n';
    vst[i] = 1;
    cnt--;
    if(!cnt) return;
    for(auto j : adj[i]){
        // cout << i << ' ' << j << "gg\n";
        if(vst[j]) continue;
        dfs(j);
        if(!cnt) return;
    }
}

void get_col(int i, int color){
    col[i] = color;
    for(auto j : adj[i]){
        if(!col[j] && vst[j]){
            get_col(j, color);
        }
    }
}

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= 3; i++) cin >> sz[i].fi, sz[i].se = i;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        // cout << u << '' << v << '\n';
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    // dfs(7);
    sort(sz + 1, sz + 4);
    for(int i = 1; i <= 2; i++){
        bool check = 0;
        for(int j = 1; j <= n; j++){
            cnt = sz[i].fi;
            if(!vst[j]){    
                dfs(j);
                if(!cnt){
                    check = 1;
                    get_col(j, sz[i].se);
                    break;
                }
            }
        }
        if(!check){
            for(int i = 1; i <= n; i++){
                cout << 0 << ' ';
            }
            exit(0);
        }
    }
    // dfs(7);
    for(int i = 1; i <= n; i++){
        cout << (col[i] ? col[i] : sz[3].se) << ' ';
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
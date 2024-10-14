#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "reform"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

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

int n , m , low[N] , num[N] , num_node;
int bridge , child[N];
bool in_brigde[N];
stack <int> node;
vector <int> adj[N];
bool vst[N];

void dfs_check(int i){
    vst[i] = 1;
    for(auto j : adj[i]){
        if(vst[j]) continue;
        dfs_check(j);
    }
}

void dfs(int i , int p){
    child[i] = 1;
    node.push(i);
    low[i] = num[i] = ++num_node;

    for(auto j : adj[i]){
        if(j == p) continue;
        if(!num[j]){
            dfs(j , i);
            child[i] += child[j];
            low[i] = min(low[i] , low[j]);
        }
        else low[i] = min(low[i] , num[j]);

        // cout << i << ' ' << j << ' ' << low[j] << ' ' << num[i] << '\n';

        if(low[j] > num[i]){
            in_brigde[j] = 1;
            bridge++;
        }
    }
}

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    int check = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!vst[i]){
            check++;
            dfs_check(i);
        }
    }

    if(check > 2){
        cout << 0;
        exit(0);
    }

    if(check == 1){
        dfs(1 , 0);
        ll ans = 0;
        for(int i = 1 ; i <= n ; i++){
            if(in_brigde[i]){
                ans += (1ll * (n - child[i]) * child[i]) - 1;
            }
        }

        ll del = m - bridge;
        ll add = (1ll * n * (n - 1) / 2 - m);

        cout << ans + (del * add);
    }
    else{
        int tmp = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!num[i]){
                num_node = 0;
                bridge = 0;
                dfs(i , 0);
                // cout << bridge << '\n';
                tmp += bridge;
            }
        }
        ll del = m - tmp;
        ll add = (1ll * num_node * (n - num_node));

        cout << del * add << '\n';
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
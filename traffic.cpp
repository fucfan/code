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
#define file "traffic"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
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

int n , m , k , root;
int pos[N];
vector <int> adj[N];
ll sum_dis[N];
int child[N];
vector <pair <ll , int>> order;
ll ans = oo;

void dfs(int i , int p){
    child[i] = 1;
    sum_dis[i] = 0;
    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j , i);
        child[i] += child[j];
        sum_dis[i] += sum_dis[j] + child[j];
    }
}

int find_centroid(int i , int p){
    for(auto j : adj[i]){
        if(j == p || child[j] < n / 2) continue;
        return find_centroid(j , i);
    }
    return i;
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    dfs(1 , 0);
    int root = find_centroid(1 , 0);
    dfs(root , 0);

    // cout << root << '\n';

    ll ans = sum_dis[root];

    vector <int> order;

    for(int i = 1 ; i <= n ; i++){
        if(i == root) continue;
        order.pb(child[i]);
    }

    sort(all(order) , greater<>());

    for(auto j : order){
        ans -= j;
        k--;
        if(!k) break;
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
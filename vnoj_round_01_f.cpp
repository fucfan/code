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
#define file "test"
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

int n;
bool check[N];
vector <pii> adj[N];
ll ans;
ll val[N] , val_cur[N] , cnt[N];

struct centroid{
    int child[N];
    bool del[N];

    void dfs_child(int i , int p){
        child[i] = 1;
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p || del[j]) continue;
            dfs_child(j , i);
            child[i] += child[j];
        }
    }

    int find_centroid(int i , int p , int num_node){
        for(auto it : adj[i]){
            int j = it.fi;
            if(j == p || del[j] || child[j] <= num_node / 2) continue;
            return find_centroid(j , i , num_node);
        }
        return i;
    }
} cd;

void cal(int i , int p , int pre){
    for(auto it : adj[i]){
        int j = it.fi;
        if(j == p || cd.del[j]) continue;
        if(!cur[it.se]) ans += cnt[it.se] + val[it.se];
    }
}

void cal1(int i , int p , int num_node){

}

void update(int i , int p){
    
}

void clear(int i , int p){
    for(auto it : adj[i]){
        int j = it.fi;
        if(j == p || cd.del[j]) continue;
        val[it.se] = 0;
        cnt[it.se] = 0;
        clear(j , i);
    }
}

void sol(int i){
    cd.dfs_child(i , 0);

    int root = cd.find_centroid(i , 0 , cd.child[i]);
    cd.dfs_child(root , 0);
    cd.del[root] = 1;

    // cout << i << ' ' << root << ' ' << ans << '\n';

    for(auto it : adj[root]){
        int j = it.fi;
        if(cd.del[j]) continue;
        val_cur[it.se]++;
        check[it.se] = 1;
        ans += (val[it.se] + cnt[it.se]) * cd.child[j];
        // cout << j  << ' '  << ans << ' ' << val[it.se] << ' ' << cd.child[j] << '\n';
        cal(j , root);
        // cout << j  << ' '  << ans << ' ' << val[it.se] << ' ' << cd.child[j] << '\n';
        val_cur[it.se]--;
        cnt[it.se] += cd.child[j];
        val[it.se] += cd.child[j];
        update(j , root);
        check[it.se] = 0;
        // cout << j  << ' '  << ans << ' ' << val[it.se] << ' ' << cd.child[j] << '\n';
        // cout << val[it.se] << '\n';
    }
    
    for(auto it : adj[root]){
        int j = it.fi;
        if(cd.del[j]) continue;
        val_cur[it.se]++;
        cal1(j , i , cd.child[root] - cd.child[j]);
        val_cur[it.se]--;
    }

    // cout << i << ' ' << root << ' ' << ans << '\n';

    clear(root , 0);
    
    for(auto it : adj[root]){
        int j = it.fi;
        if(cd.del[j]) continue;
        sol(j);
    }
}

void inp(){
    cin >> n;
    for(int i = 2 ; i <= n ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
}

void solve(){
    sol(1);

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

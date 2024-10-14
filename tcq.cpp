#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;

int n , q , sub , col[N] , a[N] , ans[N] , tree[N] , child[N];
vector <int> vt[N];
int cnt[N];
vector <int> adj[N];
vector <pii> query[N];

void update(int pos , int val){
    if(!pos) return;

    for(; pos <= n ; pos += pos & -pos){
        tree[pos] += val;
    }
}

int get(int pos){
    int res = 0;

    for(; pos > 0 ; pos -= pos & -pos){
        res += tree[pos];
    }

    return res;
}

void pre_dfs(int i , int p){
    child[i] = 1;

    for(auto j : adj[i]){
        if(j == p) continue;
        pre_dfs(j , i);
        child[i] += child[j];
    }
}

void dfs(int i , int p , int type){
    int Max = -1;
    int best_node = -1;
    for(auto j : adj[i]){
        if(j == p) continue;;
        if(child[j] > Max){
            Max = child[j];
            best_node = j;
        }
    }
    for(auto j : adj[i]){
        if(j == p || j == best_node) continue;
        dfs(j , i , 0);
    }

    if(best_node != -1) dfs(best_node , i , 1) , swap(vt[i] , vt[best_node]);
    
    vt[i].pb(i);
    update(cnt[col[i]] , -1);
    cnt[col[i]]++;

    update(cnt[col[i]] , 1);

    for(auto j : adj[i]){
        if(j == p || j == best_node) continue;;

        for(auto f : vt[j]){
            update(cnt[col[f]] , -1);
            cnt[col[f]]++;
            update(cnt[col[f]] , 1);
            vt[i].pb(f);
        }
    }

    // cout << i << ":\n";

    // cout << get(n) << '\n';

    // for(int f = 1 ; f <= n ; f++) cout << f << ' ' << cnt[f] << '\n';
    for(auto j : query[i]){
        ans[j.se] = get(n) - get(j.fi - 1); 
    }

    //cout << get(n) << '\n';

    if(!type)
        for(auto j : vt[i]){
            update(cnt[col[j]],-1);
            cnt[col[j]]--;
            update(cnt[col[j]],1);
        }
}

void inp(){
    cin >> sub;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> col[i];
    for(int i = 2 ; i <= n ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    cin >> q;

    for(int i = 1 ; i <= q ; i++){
        int v , k;
        cin >> v >> k;
        query[v].pb({k , i});
    }

    pre_dfs(1 , 0);
    // for(int i = 1 ; i <= n ; i++) cout << i << '  ' << child[i] << '\n';
    dfs(1 , 0 , 0);

    // cout << 1 << '\n';

    for(int i = 1 ; i <= q ; i++){
        cout << ans[i] << ' ';
    }
}

void run_with_file(){
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UMU      */
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
const int N = 4e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m, q, num_dfs, st[N], en[N], pos[N];
vector <int> adj[N];
ll res_l[N], res_r[N];

struct Query{
    int id, type;
    int node, val;
    int pos;

    void input(int num, int tmp){
        id = num;
        type = tmp;
        if(type == 1) cin >> node >> val, pos = num; 
        else{
            cin >> pos;
            // if(!tmp) pos--;
        }
    }

    bool operator<(Query b){
        if(pos == b.pos){
            return type < b.type;
        }
        return pos < b.pos;
    }
} query[N];

struct fenwick_tree{
    ll node[N];

    void update(int pos, int val){
        for(; pos <= n; pos += (pos & -pos)){
            node[pos] = node[pos] + val;
        }
    }

    ll get(int pos){
        ll res = 0;
        for(; pos > 0; pos -= (pos & -pos)){
            res = res + node[pos];
        }
        return res;
    }
} BIT;

void dfs(int i, int p){
    st[i] = ++num_dfs;
    pos[st[i]] = i;
    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j, i);
    }
    en[i] = num_dfs;
}

void inp(){
    cin >> n >> m >> q; 
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }
    for(int i = 1; i <= m; i++){
        query[i].input(i, 1);
    }
    for(int i = m + 1; i <= m + q; i++){
        query[i].input(i, 0);
        query[i + q].input(i, 2);
        int node;
        cin >> node;
        query[i].node = query[i + q].node = node;
    }
}

void solve(){
    dfs(1, 0);
    sort(query + 1, query + 1 + m + q * 2);
    for(int i = 1; i <= m + q * 2; i++){
        // cout << query[i].node << ' ' << st[query[i].node] << '\n';
        if(query[i].type == 1){
            int node = query[i].node;
            int val = query[i].val;
            BIT.update(st[node], val);
            BIT.update(en[node] + 1, -val);
        }
        if(query[i].type == 0){
            int id = query[i].id;
            int node = query[i].node;
            res_l[id - m] = BIT.get(st[node]);
        }
        if(query[i].type == 2){
            int id = query[i].id;
            int node = query[i].node;
            res_r[id - m] = BIT.get(st[node]);
        }
    }

    for(int i = 1; i <= q; i++) cout << res_r[i] - res_l[i] << '\n';
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
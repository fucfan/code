#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "str"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

struct Query{
    string s;
    int id;
};

int n , q , sz[N] , num_node[N] , ans[N];
vector <int> adj[N] ,vt[N];
vector <Query> query[N];
char c[N];

struct Trie{
    struct Node{
        int child[26];
        int exist , cnt;
    } node[N];

    int cur;

    Trie() : cur(0){
        mem(node[cur].child , -1);
        node[cur].cnt = node[cur].exist = 0;
    }

    int new_node(){
        cur++;
        mem(node[cur].child , -1);
        node[cur].cnt = node[cur].exist = 0;
        return cur;
    }

    int find_string(string s , int st){
        int pos = st;
        for(auto j : s){
            int c = j - 'a';
            if(node[pos].child[c] == -1){
                return 0;
            }
            pos = node[pos].child[c];
        }
        // cout << pos << ' ' << s << '\n';
        return node[pos].exist;
    }
}trie;

void getsz(int i , int p , int node){
    if(trie.node[node].child[c[i] - 'a'] == -1){
        trie.node[node].child[c[i] - 'a'] = trie.new_node();
    }
    num_node[i] = node;
    int nxt_node = trie.node[node].child[c[i] - 'a'];

    sz[i] = 1;
    for(auto j : adj[i]){
        if(j == p) continue;
        getsz(j , i , nxt_node);
        sz[i] += sz[j];
    }
}

void dfs(int i , int p , bool keep){
    int Max = -1;
    int best_node = -1;
    for(auto j : adj[i]){
        if(j != p && sz[j] > Max){
            Max = sz[j];
            best_node = j;
        }
    }

    for(auto j : adj[i]){
        if(j != p && j != best_node){
            dfs(j , i  , 0);
        }
    }

    if(best_node != -1){
        dfs(best_node , i , 1);
        swap(vt[i] , vt[best_node]);
    }

    vt[i].pb(i);
    int tmp = trie.node[num_node[i]].child[c[i] - 'a'];
    trie.node[tmp].exist++;
    
    for(auto j : adj[i]){
        if(j == p || j == best_node) continue;
        for(auto x : vt[j]){
            int tmp = trie.node[num_node[x]].child[c[x] - 'a'];
            trie.node[tmp].exist++;
            vt[i].pb(x);
        }
    }

    for(auto j : query[i]){
        ans[j.id] = trie.find_string(j.s , num_node[i]);
    }

    if(!keep){
        for(auto j : vt[i]){
            int tmp = trie.node[num_node[j]].child[c[j] - 'a'];
            trie.node[tmp].exist--;
        }
    }
}

void prepare(){
    getsz(1 , 0 , 0);
    dfs(1 , 0 , 0);
}

void inp(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++) cin >> c[i];
    for(int i = 2 ; i <= n ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 1 ; i <= q ; i++){
        string s;
        int node;
        cin >> node >> s;
        query[node].pb({s , i});
    }
}

void solve(){
    prepare();

    // for(int i = 1 ; i <= n ; i++){
    //     cout << num_node[i] << ' ';
    // }
    // nl;

    for(int i = 1 ; i <= q ; i++){
        cout << ans[i] << '\n';
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
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
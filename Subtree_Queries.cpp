#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , q , val[N] , en[N] , pos[N];
ll tree[4 * N];
vector <int> adj[N] , tour;
void build(int id , int l , int r){
    if(l == r){
        tree[id] = val[tour[l]];
        // cout << tree[id] << '\n';.
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
    // cout << tree[id] << ' ' << tree[id * 2] << ' ' << tree[id * 2 + 1] << ' ' << id << '\n';
}
void update(int id , int l , int r , int pos , int val){
    if(pos > r || pos < l) return;
    if(l == r){
        tree[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , pos , val);
    update(id << 1 | 1 , mid + 1 , r , pos , val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
ll get(int id , int l , int r , int u , int v){
    if(u > r || v < l) return 0;
    if(u <= l && r <= v) return tree[id];
    int mid = (l + r) >> 1;
    ll a = get(id << 1 , l , mid , u , v);
    ll b = get(id << 1 | 1 , mid + 1 , r , u , v);
    return a + b;
}
int dfs(int i , int par){
    pos[i] = tour.size();
    tour.pb(i);
    bool check = 1;
    if(i == 1) check = 0;
    for(int g = 0 ; g < adj[i].size() ; g++){
        int j = adj[i][g];
        if(j == par){
            check = 0;
            continue;
        }
        int nxt_node = dfs(j , i);
        if(g == adj[i].size() - 1 - check){
            en[i] = nxt_node;
            return nxt_node;
        }
    }
    en[i] = i;
    return i;
}
void inp()
{
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++){
        cin >> val[i];
    }
    for(int i = 1 ; i <= n - 1 ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1 , 0);
    // for(int i = 1 ; i <= n ; i++){
    //     cout << val[i] << ' ';
    // }
    // nl;
    // for(auto j : tour) cout << j << ' ';
    // nl;
    build(1 , 0 , tour.size() - 1);
    for(int i = 1 ; i <= q ; i++){
        int type;
        cin >> type;
        if(type == 1){
            int s , x;
            cin >> s >> x;
            val[s] = x;
            update(1 , 0 , tour.size() - 1 , pos[s] , x);
        }
        else{
            int s;
            cin >> s;
            // cout << tree[2] << "alabama\n";
            // cout << pos[s] << ' ' << pos[en[s]] << '\n';
            cout << get(1 , 0 , tour.size() - 1 , pos[s] , pos[en[s]]) << '\n';
        }
    }
    // for(int i = 0 ; i < n ; i++){
    //     cout << val[tour[i]] << ' ';
    // }
    // nl;
}

void solve()
{
    
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
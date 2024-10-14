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
#define file "sum0"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 4e5 + 5;
const int LOG = 18;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct monster{
    int pos , power;

    bool operator<(monster b){
        return pos < b.pos;
    }

    void inp(int type, int num){
        pos = num;
        cin >> power;
        if(type) power *= -1;
    }
} mons[N];

struct segment_tree{
    int node[1 << 20];

    void update(int id , int l , int r , int pos , int val){
        if(l > pos || pos > r) return;
        if(l == r){
            node[id] = val;
            return;
        }

        int mid = (l + r) >> 1;

        update(id << 1 , l , mid , pos , val);
        update(id << 1 | 1 , mid + 1 , r , pos , val);

        node[id] = max(node[id << 1] , node[id << 1 | 1]);
    }

    int get(int id , int l , int r , int u , int v){
        if(u > r || l > v) return 0;

        if(u <= l && r <= v){
            // cout << l << ' ' << r << ' ' << node[id] << "ff\n";
            return node[id];
        }
        
        int mid = (l + r) >> 1;

        return max(get(id << 1 , l , mid , u , v) , 
                   get(id << 1 | 1 , mid + 1 , r , u , v));
    }
} ST;

struct Query{
    int l , r , id;
    bool operator<(Query b){
        return r < b.r;
    }
} query[N / 2];

int n , m , q , ans[N / 2] , val[N] , st[N] , en[N] , num_node;
int par[N][LOG + 1];
map <ll , int> mp;
pii adj[N];


void dfs(int i , int p){
    st[i] = num_node++;
    if(adj[i].fi){
        int j = adj[i].fi;
        if(j){
            par[j][0] = i;
            val[j] = val[i];
            dfs(j , i);
        }
    }
    if(adj[i].se){
        int j = adj[i].se;
        if(j){
            par[j][0] = i;
            val[j] = val[i] + 1;
            dfs(j , i);
        }
    }
    en[i] = num_node - 1;
    // cout << i << ' ' << st[i] << ' ' << en[i] << "gg\n";
}

void prepare(){
    sort(mons + 1 , mons + 1 + n);
    ll sum = 0;
    int max_pos = -1;
    for(int i = 1 ; i <= n ; i++){
        // cout << mons[i].pos << ' ' << mons[i].power << '\n';
        sum += mons[i].power;
        int tmp = mp[sum];
        if((tmp || !sum) && max_pos < tmp){
            adj[tmp].se = i;
            // cout << i << ' ' << tmp << ' ' << 1 << '\n';
            max_pos = tmp;
        }
        else{
            adj[i - 1].fi = i;
            // cout << i << ' ' << i - 1 << ' ' << 0 << '\n';
        }
        mp[sum] = i;
    }
    mp.clear();
    dfs(0 , 0);
    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 0 ; i <= n + m ; i++){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int get_pos(int k , int type){
    int l = 1;
    int r = n + m;
    int res = r + 1;
    while(l <= r){
        // cout << k << ' ' << l << ' ' << r << ' ' << type << '\n';
        int mid = (l + r) >> 1;
        if(mons[mid].pos == k){
            if(!type) return mid;
        }
        if(mons[mid].pos > k){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

int jump(int l , int r){
    // cout << l << ' ' << r << '\n';
    for(int i = LOG ; i >= 0 ; i--){
            // cout << r << ' ' << i << ' ' << par[r][i] << "gg\n";
        if(par[r][i] >= l - 1){
            r = par[r][i];
        }
    }
    // cout << r << '\n';
    return r;
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        mons[i].inp(i > n, i);
    }
}

void solve(){
    prepare();
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int l , r;
        cin >> l >> r;
        // cout << l << ' ' << r << '\n';
        l = get_pos(l , 0);
        r = get_pos(r , 1) - 1;
        // cout << l << ' ' << r << '\n';
        // nl;
        query[i] = {l , r , i};
    }   
    sort(query + 1 , query + 1 + q);
    ST.update(1 , 0 , n + m , 0 , val[0]);
    // for(int i = 1 ; i <= n + m ; i++) cout << val[i] << ' ';
    // nl;
    for(int i = 1 ; i <= q ; i++){
        if(query[i].r != query[i - 1].r){
            for(int j = query[i - 1].r + 1 ; j <= query[i].r ; j++){
                ST.update(1 , 0 , n + m , st[j] , val[j]);
                // cout << j << ' ' << val[j] << '\n';
            }
        }
        int l = query[i].l;
        int r = query[i].r;
        int id = query[i].id;
        int tmp = jump(l , r);
        if(l <= r) ans[id] = ST.get(1 , 0 , n + m , st[tmp] , en[tmp]) - val[tmp];
        // cout << tmp << ' ' << l << ' ' << r << ' ' << ans[id] << '\n';
    }
    for(int i = 1 ; i <= q ; i++) cout << ans[i] << '\n';
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
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

const int oo = 2e9 + 7;
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

struct Point{
    int x , y;
    int id;

    bool operator<(Point b){
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
} p[N]; 

bool cmp(Point a , Point b){
    return a.id < b.id;
}

int n , m , l;
vector <int> compress;
vector <int> connect[N];
bool block[N];

struct DSU{
    int par[N];
    int sz[N];
    
    void make_set(){
        for(int i = 1 ; i <= m ; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int a){
        return (a == par[a] ? a : get(par[a]));
    }

    bool uni(int a , int b){
        a = get(a);
        b = get(b);

        if(a == b) return 0;

        if(sz[a] > sz[b]) swap(a , b);

        par[a] = b;
        sz[b] += sz[a];

        return 1;
    }
} dsu;

struct segment_tree{
    pii node_max[N << 2 | 1];

    void build(int id , int l , int r){
        node_max[id] = {-oo , -oo};
        
        if(l == r) return;

        int mid = (l + r) >> 1;

        build(id << 1 , l , mid);
        build(id << 1 | 1 , mid + 1 , r);
    }

    void update_max(int id , int l , int r , int pos , pii val){
        if(pos > r || l > pos) return;

        if(l == r){
            node_max[id] = val;
            return;
        }

        int mid = (l + r) >> 1;

        update_max(id << 1 , l , mid , pos , val);
        update_max(id << 1 | 1 , mid + 1 , r , pos , val);

        // if(node_max[id << 1].fi == node_max[id << 1 | 1].fi) node_max[id] = node_max[id << 1];
        node_max[id] = max(node_max[id << 1] , node_max[id << 1 | 1]);
    }

    pii get_max(int id , int l , int r , int u , int v){
        if(u > r || l > v) return {-oo , 0};

        if(u <= l && r <= v) return node_max[id];

        int mid = (l + r) >> 1;

        return max(get_max(id << 1 , l , mid , u , v) , 
                   get_max(id << 1 | 1 , mid + 1 , r , u , v));
    }
} st;

void prepare(){
    for(int i = 1 ; i <= m ; i++){
        compress.pb(p[i].x);
        compress.pb(p[i].y);
    }

    sort(all(compress));
    compress.erase(unique(all(compress)) , compress.end());
}

void inp(){
    cin >> n >> m >> l;
    for(int i = 1 ; i <= m ; i++){
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
}

void solve(){
    // cout << st.node_min[1].fi;
    dsu.make_set();
    prepare();
    sort(p + 1 , p + 1 + m);
    int sz = compress.size();
    st.build(1 , 1 , sz);

    for(int i = 1 ; i <= m ; i++){
        // int x = lower_bound(all(compress) , p[i].x) - compress.begin() + 1;
        int y = lower_bound(all(compress) , p[i].y) - compress.begin() + 1;

        int lef = lower_bound(all(compress) , p[i].y - l) - compress.begin() + 1;
        int rig = upper_bound(all(compress) , p[i].y + l) - compress.begin();

        pii tmp1 = st.get_max(1 , 1 , sz , lef , y);
        pii tmp2 = st.get_max(1 , 1 , sz , y + 1 , rig);

        if(tmp1.fi >= p[i].x - l){
            dsu.uni(p[i].id , tmp1.se);
        }

        if(tmp2.fi >= p[i].x - l){
            dsu.uni(p[i].id , tmp2.se);
        }

        st.update_max(1 , 1 , sz , y , {p[i].x , p[i].id});
    }
    for(int i = 1 ; i <= m ; i++){
        connect[dsu.get(i)].pb(i);
    }       

    sort(p + 1 , p + 1 + m , cmp);

    int cnt = 0;

    for(int i = 1 ; i <= m ; i++){
        int max_x = -oo;
        int max_y = -oo;
        int min_x = oo;
        int min_y = oo;

        for(auto j : connect[i]){
            // cout << p[j].x << ' ' << p[j].y << '\n';
            max_x = max(max_x , p[j].x + l);
            max_y = max(max_y , p[j].y + l);
            min_x = min(min_x , p[j].x - l);
            min_y = min(min_y , p[j].y - l);
        }

        // cout << max_x << ' ' << max_y << ' ' << min_x << ' ' << min_y << '\n';

        if((max_x >= n && (max_y >= n || min_x <= 0)) ||
           (min_y <= 0 && (max_y >= n || min_x <= 0))){
                // cout << "gg\n";
                for(auto j : connect[i]){
                    block[j] = 1;
                }
                cnt += connect[i].size();
            }
    }

    cout << cnt << '\n';

    for(int i = 1 ; i <= m ; i++){
        if(block[i]) cout << p[i].x << ' ' << p[i].y << '\n';
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
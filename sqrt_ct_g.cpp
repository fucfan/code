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
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}


struct Edge{
    int u, v;

    void input(){
        cin >> u >> v;
    }
} edge[N];

struct Query{
    int l, r, id;

    void input(int num){
        cin >> l >> r;
        id = num;
    }

    bool operator<(Query b){
        return (l < b.l);
    }

    bool operator>(Query b){
        return (r < b.r);
    }
} query[N];

int n, m, q, num_block, st[N], ans[N];
vector <Query> block[N];
stack <pair<pii, int>> change;

struct DSU{
    int par[N], sz[N];

    void make_set(){
        for(int i = 1; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int a){
        return (par[a] == a ? a : get(par[a]));
    }

    bool uni(int a, int b){
        a = get(a);
        b = get(b);
        if(a == b) return 0;
        if(sz[a] > sz[b]) swap(a, b);
        par[a] = b;
        sz[b] += sz[a];
        return 1;
    }

    void roll_back(int a, int b){
        if(sz[a] > sz[b]) swap(a, b);
        sz[b] -= sz[a];
        par[a] = a;
    }
} dsu;

void prepare(){
    sort(query + 1, query + 1 + q, greater<>());

    int tmp = 0;

    for(int i = 1; i <= q; i++){
        if(tmp < query[i].r){
            while(tmp < query[i].r){
                tmp += sqrt(m);
            }
            num_block++;
        }
        st[num_block] = min(tmp, m);
        block[num_block].pb(query[i]);
    }
}

void inp(){
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) edge[i].input();
    for(int i = 1; i <= q; i++) query[i].input(i);
}

void solve(){
    prepare();
    for(int i = 1; i <= num_block; i++){
        sort(all(block[i]));
        dsu.make_set();
        int scc = n;
        int lim = st[i] - sqrt(m); 
        while(change.size()) change.pop();
        for(int j = lim; j >= 1; j--){
            int u = dsu.get(edge[j].u);
            int v = dsu.get(edge[j].v);
            int tmp = dsu.uni(u, v);
            scc -= tmp;
            change.push({{u, v}, tmp});
            // cout << u << ' ' << v << ' ' << tmp << '\n';
        }
        // nl;
        // cout << i << ' ' << lim << ' ' << scc << '\n';
        int cur = 1;

        for(auto j : block[i]){
            while(cur < j.l){
                if(cur > lim) break;
                int u = change.top().fi.fi;
                int v = change.top().fi.se;
                int tmp = change.top().se;
                scc += tmp;
                if(tmp) dsu.roll_back(u, v);
                cur++;
                change.pop();
            }
            // cout << scc << '\n';
            while(cur > j.l){
                cur--;
                int u = edge[cur].u;
                int v = edge[cur].v;
                int tmp = dsu.uni(u, v);
                scc -= tmp;
                change.push({{u, v}, tmp});
            }
            int str = max(j.l, int(lim + 1));
            for(int p = str; p <= j.r; p++){
                int u = dsu.get(edge[p].u);
                int v = dsu.get(edge[p].v);
                // cout << p << ' ' << edge[p].u << ' ' << edge[p].v << '\n';
                int tmp = dsu.uni(u, v);
                scc -= tmp;
                change.push({{u, v}, tmp});
            }
            // cout << i << ' ' << j.l << ' ' << j.r << ' ' << cur << '\n'
            //      << ' ' << str << ' ' << lim << ' ' << scc << '\n';
            ans[j.id] = scc;
            for(int p = str; p <= j.r; p++){
                int u = change.top().fi.fi;
                int v = change.top().fi.se;
                int tmp = change.top().se;
                scc += tmp;
                if(tmp) dsu.roll_back(u, v);
                change.pop();
            }
        }
        block[i].clear();
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
    num_block = 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
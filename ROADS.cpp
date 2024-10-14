#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "roads"
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

struct Edge{
    int u , v , w;  
    int id;

    bool operator<(Edge a){
        return w < a.w;
    }

    bool operator>(Edge a){
        return w > a.w;
    }
} edge[N];

int n , m , k;
vector <int> ans;
vector <Edge> used;

struct dsu{
    int par[N] , sz[N];

    void make_set(){
        for(int i = 1 ; i <= n ; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int i){
        return (i == par[i] ? i : get(par[i]));
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

void inp(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].id = i;
    }
}

void solve(){
    sort(edge + 1 , edge + 1 + m);

    int scc = n;

    dsu.make_set();

    int check = 0;

    for(int i = 1 ; i <= m ; i++){
        if(dsu.uni(edge[i].u , edge[i].v)){
            scc--;
            check += edge[i].w;
            if(edge[i].w){
                used.pb(edge[i]);
                ans.pb(edge[i].id);
            }
        }
    }

    if(check > k){
        cout << -1;
        exit(0);
    }

    if(scc > 1){
        cout << -1;
        exit(0);
    }

    sort(edge + 1 , edge + 1 + m , greater<>());

    dsu.make_set();

    scc = n;
    check = 0;

    for(auto j : used){
        dsu.uni(j.u , j.v);
        scc--;
        check++;
    }

    for(int i = 1 ; i <= m ; i++){
        if(edge[i].w == 1 && check == k) continue;
        if(dsu.uni(edge[i].u , edge[i].v)){
            scc--;
            check += edge[i].w;
            ans.pb(edge[i].id);
        }
    }

    if(check != k){
        cout << -1;
        exit(0);
    }

    sort(all(ans));

    for(auto j : ans) cout << j << ' ';
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
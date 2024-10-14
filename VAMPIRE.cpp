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
#define file "vampire"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
#define pip pair <int , pii>
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

int n , m , hp;
vector <pip> adj[N];
int d[2001][4001];

struct segment_tree{
    int node[(4000) << 2 | 1];

    void update(int id , int l , int r , int pos , int val){
        if(pos > r || l > pos) return;

        if(l == r){
            node[id] = val;
            return;
        }

        int mid = (l + r) >> 1;

        update(id << 1 , l , mid , pos , val);
        update(id << 1 | 1 , mid + 1 , r , pos , val);

        node[id] = min(node[id << 1] , node[id << 1 | 1]);
    }

    int get(int id , int l , int r , int u , int v){
        if(l > v || u > r) return oo;

        if(u <= l && r <= v){
            return node[id];
        }

        int mid = (l + r) >> 1;

        return min(get(id << 1 , l , mid , u , v) , 
                   get(id << 1 | 1 , mid + 1 , r , u , v));
    }
} ST[2001];

void dijkstra(int s){
    mem(d , 0x3f);
    priority_queue <pip , vector <pip> , greater<pip>> q;

    for(int i = 1 ; i <= n ; i++){
        mem(ST[i].node , 0x3f);
    }

    d[s][0] = 0;
    ST[s].update(1 , 0 , hp , 0 , 0);

    q.push({0 , {s , 0}});

    while(q.size()){
        pii u = q.top().se;
        int dis = q.top().fi;

        // cout << u.fi << ' ' << u.se << '\n';

        q.pop();

        if(dis > d[u.fi][u.se]) continue;

        for(auto it : adj[u.fi]){
            int w = it.se.fi;
            pii v = {it.fi , u.se + it.se.se * w};

            if(v.se > hp) continue;

            if(d[v.fi][v.se] > d[u.fi][u.se] + w && d[u.fi][u.se] + w < ST[v.fi].get(1 , 0 , hp , 0 , v.se)){
                d[v.fi][v.se] = d[u.fi][u.se] + w;
                ST[v.fi].update(1 , 0 , hp , v.se , d[v.fi][v.se]);
                q.push({d[v.fi][v.se] , v});
            }
        }
    }

    // for(int i = 1 ; i <= n ; i++){
    //     cout << d[i][3] << ' ';
    // }

    int ans = oo;

    for(int i = 0 ; i <= hp ; i++){
        ans = min(ans , d[n][i]);
    }

    cout << (ans == oo ? -1 : ans);
}

void inp(){
    cin >> hp;
    cin >> n >> m;    
    for(int i = 1 ; i <= m ; i++){
        int u , v , type , w;
        cin >> u >> v >> w >> type;
        u++;
        v++;
        adj[u].pb({v , {w , type}});
        adj[v].pb({u , {w , type}});
    }
}

void solve(){
    dijkstra(1);
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
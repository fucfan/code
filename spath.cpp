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
#define file "spath"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 1e4 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct Query{
    int x , y;
} query[1000001];

int n , m , q , d[N][N];
bool adj[N][N];
vector <int> del[N];
int cnt[N] , nxt_cnt[N];

void bfs(int s){
    queue <int> q;
    queue <int> q1;

    for(int i = 1 ; i <= n ; i++){
        if(i != s) q.push(i);
    }

    mem(cnt , 0);
    mem(nxt_cnt , 0);

    int num_node = 1;
    int nxt_num = 0;

//    for(int i = 1 ; i < s ; i++){
//        for(auto j : del[i]) cnt[j]++;
//        if(d[i][s]) num_node++;
//    }

    for(auto t : del[s]){
//            cout << s << ' ' << t << '\n';
        cnt[t]++;
    }

    vector <int> vt;
    int dis = 1;
    bool check = 0;

    while(q.size()){
        int u = q.front();

        q.pop();

        if(cnt[u] < num_node){
            nxt_num++;
            d[s][u] = dis;
            for(auto v : del[u]){
                nxt_cnt[v]++;
            }
            check = 1;
        }
        else{
            q1.push(u);
        }
        if(q.empty() && check){
            dis++;
            num_node += nxt_num;
            nxt_num = 0;
            while(q1.size()){
                int u = q1.front();
                cnt[u] += nxt_cnt[u];
                nxt_cnt[u] = 0;
                q.push(u);
                q1.pop();
            }
            check = 0;
        }
    }
}

void prepare(){
    for(int i = 1 ; i <= n ; i++){
        bfs(i);
//        for(int j = 1 ; j <= n ; j++){
//            for(int f = 1 ; f <= n ; f++){
//                cout << d[j][f] << " \n"[f == n];
//            }
//        }
//        nl;
    }
}

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        u++;
        v++;
        adj[u][v] = adj[v][u] = 1;
//        if(u < v) del[u].pb(v);
//        if(v < u) del[v].pb(u);
        del[u].pb(v);
        del[v].pb(u);
    }
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        cin >> query[i].x >> query[i].y;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    // assert(n <= 2500);
    prepare();
    for(int i = 1 ; i <= q ; i++){
        int s = query[i].x;
        int t = query[i].y;
        s++;
        t++;
        if(s > t) swap(s , t);
        if(s == t){
            cout << 0 << '\n';
        }
        else{
            if(d[s][t]) cout << d[s][t] << '\n';
            else cout << -1 << '\n';
        }
    }
}

/*      UwU      */

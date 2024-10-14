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
#define file "rmoving"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m, pref[N][N], d[N][N];
char board[N][N];
pair <pii, pii> robot;
int x, y;
vector <pii> adj[N][N];
bool vst[N][N];
int ans = oo;

int get(int l, int r, int u, int v){
    return pref[u][v] - pref[l - 1][v] - pref[u][r - 1] + pref[l - 1][r - 1];
}

void bfs(pii st){
    queue <pii> q;
    q.push(st);
    vst[st.fi][st.se] = 1;
    while(q.size()){
        pii u = q.front();
        if(u.fi < 1 || u.se < 1 || u.fi + x - 1 >= n || u.se + y - 1 >= m){
            ans = min(ans, d[u.fi][u.se]);
        }

        // cout << u.fi << ' ' << u.se << '\n';

        q.pop();

        for(auto v : adj[u.fi][u.se]){
            if(vst[v.fi][v.se]) continue;
            vst[v.fi][v.se] = 1;
            d[v.fi][v.se] = d[u.fi][u.se] + 1;
            q.push(v);
        }
    }

    cout << (ans == oo ? -1 : ans);
}

void inp(){
    cin >> n >> m;
    robot.fi = {oo, oo};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (board[i][j] == '#');
            if(board[i][j] == 'R'){
                robot.fi.fi = min(robot.fi.fi, i);
                robot.fi.se = min(robot.fi.se, j);
                robot.se.fi = max(robot.se.fi, i);
                robot.se.se = max(robot.se.se, j);
            }
        }
    }
    x = robot.se.fi - robot.fi.fi + 1;
    y = robot.se.se - robot.fi.se + 1;
}

void solve(){
    for(int i = 1; i + x - 1 <= n; i++){
        pii pre = {i, 0};
        for(int j = 1; j + y - 1 <= m; j++){
            if(get(i, j, i + x - 1, j)){
                pre = {i, j + 1};
            }
            else adj[i][j].pb(pre);
        }

        pre = {i, m - y + 2};

        for(int j = m; j - y + 1 >= 1; j--){
            if(get(i, j, i + x - 1, j)){
                pre = {i, j - y};
            }
            else adj[i][j - y + 1].pb(pre);
            // cout << pre.fi << ' ' << pre.se << ' ' << i << ' ' << y << '\n';
        }
    }

    for(int j = 1; j <= m; j++){
        pii pre = {0, j};
        for(int i = 1; i + x - 1 <= n; i++){
            if(get(i, j, i, j + y - 1)){
                pre = {i + 1, j};
            }
            else adj[i][j].pb(pre);
        }

        pre = {n - x + 2, j};
        
        for(int i = n; i - x + 1 >= 1; i--){
            if(get(i, j, i, j + y - 1)){
                pre = {i - x, j};
            }
            else adj[i - x + 1][j].pb(pre);
        }
    }

    bfs(robot.fi);
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
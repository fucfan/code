#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<ll , ll>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "robot"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
const int LOG = 20;
const pii MOVE[] = {{0 , -1} , {-1 , 0} , {0 , 1} , {1 , 0}};

int n , x , y , s , d[N][N][10];
bool vst[N][N][10];
char a[N][N];

pii dfs(ll u , ll v , int side , int second){
    if(side == 0) if(v < 1) return {u + MOVE[side].fi * second , v + MOVE[side].se * second};
    if(side == 1) if(u < 1) return {u + MOVE[side].fi * second , v + MOVE[side].se * second};
    if(side == 2) if(v > n) return {u + MOVE[side].fi * second , v + MOVE[side].se * second};
    if(side == 3) if(u > n) return {u + MOVE[side].fi * second , v + MOVE[side].se * second};

    if(u > 0 && v > 0 && u <= n && v <= n)vst[u][v][side] = 1;
    if(!second) return {u , v};
    for(int i = 0 ; i < 3 ; i++){
        int nxt_side = (side + i) % 4;
        ll nxt_u = u + MOVE[nxt_side].fi;
        ll nxt_v = v + MOVE[nxt_side].se;
        if(nxt_u <= n && nxt_v <= n && nxt_u > 0 && nxt_v > 0){
            if(a[nxt_u][nxt_v] == '#') continue;
            if(vst[nxt_u][nxt_v][nxt_side]){
                if(second > n * n){
                    second %= d[u][v][side] - d[nxt_u][nxt_v][nxt_side] + 1;
                    if(!second) return {u , v};
                }
            }
            else{
                d[nxt_u][nxt_v][nxt_side] = d[u][v][side] + 1;
            }
        }
        return dfs(nxt_u , nxt_v , nxt_side , second - 1);
    }

    return {u , v};
}

void inp(){
    cin >> n >> x >> y >> s;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[j][i];
        }
    }
}

void solve(){
    pii ans = dfs(x , y , 0 , s);
    cout << ans.fi << ' ' << ans.se;
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
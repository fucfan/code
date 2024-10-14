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
const int N = 1e3 + 5;
const int LOG = 20;
const int base = 31;
const pii dir[] = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
const pii dir_box[] = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , m;
pii pos_box , pos_sokoban , pos_end;
char a[N][N];
bool vst[N][N];
bool vst_move[N][N];

void dfs(int x , int y){
    vst[x][y] = 1;
    for(int i = 0 ; i < 4 ; i++){
        int nxt_x = x + dir[i].fi;
        int nxt_y = y + dir[i].fi;
        if(!vst[nxt_x][nxt_y] && a[nxt_x][nxt_y] != '#') dfs(nxt_x , nxt_y);
    }
}

void dfs_tmp(pii centre , int x , int y){
    if()
}

void dfs_move(int x , int y , int cur_dir){
    bool tmp_vst[3][3];
    mem(tmp_vst , 0);
    pii pos_sokoban_tmp = {x + dir[cur_dir].fi , y + dir[cur_dir].se};
    for(int i = 0 ; i < 4 ; i++){
        int nxt_x = x + dir[i].fi;
        int nxt_y = y + dir[i].fi;
        if(a[nxt_x][nxt_y] != '#' && !vst[nxt_x][nxt_y])
    }
}

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
            if(a[i][j] == 'B') pos_box = {i , j};
            if(a[i][j] == 'G') pos_end = {i , j};
            if(a[i][j] == 'S') pos_sokoban = {i , j};
        }
    }
}

void solve(){
    dfs(pos_sokoban.fi , pos_sokoban.se);
    for(int i = 0 ; i < 4 ; i++){
        pii tmp;
        tmp.fi = pos_box.fi + dir[i].fi;
        tmp.se = pos_box.se + dir[i].se;
        if(vst[tmp.fi][tmp.se]){

        }
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
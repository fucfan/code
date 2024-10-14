#include <bits/stdc++.h>
#define ll long long
#define BIT(x , i) (((x) >> (i)) & 1)
#define flip(x , i) ((x) ^ (1 << (i)))
#define fi first
#define se second
#define pii pair<ll , ll>
#define pb push_back
#define nl cout << '\n';
#define add(x , y) ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
#define all(c) (c).begin() , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(a))
#define file "test"

using namespace std;

const int N = 4e5 + 5;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int base = 31;
const int LOG = 20;
const int MOVE[] = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

int n;
bool vst[N][N];
vector <pii> reset;

int bfs(int x , int y , int r){
    queue <pii> q;
    vst[x][y] = 1;
    q.push({x , y});
    reset.pb({x , y});

    int cnt = 1;

    while(q.size()){
        int u = q.front().fi;
        int v = q.front().se;
        cnt++
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int s = u + MOVE[i].fi;
            int t = v + MOVE[i].se;

            if(s > n || t > n || s < 1 || t < 1 || vst[s][t] || a[s][t] - a[u][v] != r) continue;

            vst[s][t] = 1;
            q.push(s , t);
            reset.pb(s , t);
        }
    }

    return cnt;
}

void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j];
        }
    }
}

void solve()
{
    int ans = 0;
    for(int k = 1 ; k <= 1e6 ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(!vst[i][j]){
                    ans = max(ans , bfs(i , j , k));
                }
            }
        }
        while(reset.size()){
            vst[reset.back().fi][reset.back().se] = 0;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
//    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

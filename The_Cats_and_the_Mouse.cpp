#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const pair <int , int> MOVE[5] = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
int n , m , k , mx[107] , my[107] , c1x[107] , c1y[107] , c2x[107] , c2y[107]; 
int a[107][107] , u , v , val[107][107] ;
bool vst[107][107] , check;
queue <pair <int , int>> q;
void BFS(int x , int y , int g){
    q.push({x , y});
    val[x][y] = 0;
    a[x][y] = g;
    vst[x][y] = true;
    if((x == n || y == m || x == 1 || y == 1) && a[x][y] == 1){
        cout << "YES \n";
        check = true;
        return;
    }
    while(!q.empty()){
        for(int i = 0 ; i < 4 ; i++){
            u = q.front().fi + MOVE[i].fi;
            v = q.front().se + MOVE[i].se;
            if(u > 0 && v > 0 && u <= n && v <= m && !vst[u][v]){
                vst[u][v] = true;
                int k = val[q.front().fi][q.front().se] + 1;
                if(g == 2){
                    if(a[u][v] != 0){
                        val[u][v] = min(k , val[u][v]);
                    }
                    if(a[u][v] == 0){
                        a[u][v] = g;
                        val[u][v] = k;
                    }
                }
                if(g == 1){
                    if(k < val[u][v]){
                        a[u][v] = 1;
                        val[u][v] = min(k , val[u][v]);
                    }
                }
                if((u == n || v == m || u == 1 || v == 1) && a[u][v] == 1){
                    cout << "YES \n";
                    check = true;
                    while(!q.empty()) q.pop();
                    return;
                }
                q.push({u , v});
            }
        }
        q.pop();
    }
}
void inp()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i <= k ; i++){
        cin >> mx[i] >> my[i];
        cin >> c1x[i] >> c1y[i];
        cin >> c2x[i] >> c2y[i];
    }
}

void solve()
{
    for(int i = 1 ; i <= k ; i++){
        check = false;
        mem(a , 0);
        mem(val , 0);
        mem(vst , 0);
        BFS(c1x[i] , c1y[i] , 2);
        mem(vst , 0);
        BFS(c2x[i] , c2y[i] , 2);
        mem(vst , 0);   
        BFS(mx[i] , my[i] , 1);
        if(!check) cout << "NO \n";
    }
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 1;  j <= m ; j++){
    //         cout << val[i][j] << " ";
    //     }
    //     nl;
    // }
}

void run_with_file()
{
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
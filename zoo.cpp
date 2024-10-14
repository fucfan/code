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
pair <int , int> MOVE[5] = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
int n , m , u , v , x , y , s , t;
ll cnt;
bool vst[1007][1007] , vst1[1007][1007] , check;
queue <pair <int , int>> q , q1;
char a[1007][1007] , c;
void BFS(int i , int j , char g){
    check = false;
    if(q1.empty()){
        // if(g == 'T') a[i][j] = 'B';
        // else a[i][j] = 'T';
        mem(vst , false);
        q.push({i , j});
    }
    else while(!q1.empty()){
        // cout << q1.front().fi << ' ' << q1.front().se << '\n';
        q.push(q1.front());
        q1.pop();
    }
    while(!q.empty()){
        x = q.front().fi;
        y = q.front().se;
        vst[x][y] = true;
        q.pop();
        for(int k = 0 ; k < 4 ; k++){
            u = x + MOVE[k].fi;
            v = y + MOVE[k].se;
            if(a[u][v] == g && u > 0 && v > 0 && u <= n && v <= m && !vst[u][v]){
                vst[u][v] = true;
                // if(g == 'T'){
                //     a[u][v] = 'B';
                // }
                // else a[u][v] = 'T';
                q.push({u , v});
            }
            if(a[u][v] != '*' && a[u][v] != g && u > 0 && v > 0 && u <= n && v <= m && !vst[u][v]){
                // cout << u << ' ' << v << ' ' << a[u][v] << ' ' << g << '\n';
                // cout << a[u][v] << " op" << '\n';
                if(!vst1[u][v]){
                    vst1[u][v] = true;
                    q1.push({u , v});
                    s = u;
                    t = v;
                    c = a[u][v];
                    check = true;
                }
            }
        }
    }
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }
}

void solve()
{
    
    // BFS(1 , 1 , a[1][1]);
    s = 1;
    t = 1;
    c = a[s][t];
    check = true;
    while(check){
        cnt++;
        BFS(s , t , c);
        // for(int i = 1 ; i <= n ; i++){
        //     for(int j = 1 ; j <= m ; j++){
        //         cout << a[i][j];
        //     }
        // nl;
        // }
    }
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 1 ; j <= m ; j++){
    //         cout << a[i][j];
    //     }
    //     nl;
    // }
    cout << cnt;
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}

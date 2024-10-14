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
int n , m , x , y , s , t , z , d , a[25][25];
bool vst[25][25];
pair <int , int> par[25][25] , MOVE[25];
queue <pair <int , int>> q;
void inp()
{   
    cin >> n >> m;
    d = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }
    cin >> s >> t;
    x = 1;
    y = 1;
    q.push({x , y});
}

void solve()
{
    mem(par , -1);
    while(!q.empty()){
        x = q.front().fi;
        y = q.front().se;
        q.pop();
        if(a[x + 1][y] == 0 && vst[x + 1][y] == false){
            q.push({x + 1 , y});
            vst[x + 1][y] = true;
            par[x + 1][y].fi = x;
            par[x + 1][y].se = y;
        }
        if(a[x][y + 1] == 0 && vst[x][y + 1] == false){
            q.push({x , y + 1});
            vst[x][y + 1] = true;
            par[x][y + 1].fi = x;
            par[x][y + 1].se = y;
        }
    }
    // cout << par[1][1].fi;
    while(s != -1){ 
        d++;
        MOVE[d].fi = s;
        MOVE[d].se = t;
        z = par[s][t].fi;
        t = par[s][t].se;
        s = z;
    }
    cout << d << '\n';
    for(int i = d ; i >= 1 ; i--){
        cout << MOVE[i].fi << " " << MOVE[i].se << '\n';
    }
}

void run_with_file()
{
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
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
 
const ll oo = 1e18 + 7;
const ll mod = 1e10 + 7;
const int N = 3e5 + 5;
int n , m , q , a , b;
pair <int , int> qu[N];
ll x[1007][1007] , c;
void inp()
{
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n + 1 ; i++){
        for(int j = 1 ; j <= n + 1 ; j++){
            x[i][j] = oo;
            if(i == j) x[i][j] = 0;
        }
    }
    for(int i = 1 ; i <= m ; i++){
        cin >> a >> b >> c;
        x[a][b] = min(x[a][b] , c);
        x[b][a] = min(x[b][a] , c);
    }
    for(int i = 1 ; i <= q ; i++){
        cin >> qu[i].fi >> qu[i].se;
    }
}
 
void solve()
{
    for(int i = 1 ; i <= n ; i++){
        for(int u = 1 ; u <= n ; u++){
            for(int v = 1 ; v <= n ; v++){
                if(x[u][v] > x[u][i] + x[i][v] && x[u][v] != -1){
                    x[u][v] = x[u][i] + x[i][v];
                }
                // cout << u << " " << v << " " << x[u][v] << '\n';
            }
        }
    }
    for(int i = 1; i <= q ; i++){
        // cout << qu[i].fi << " " << qu[i].se << '\n';
        if(x[qu[i].fi][qu[i].se] < oo)
        cout << x[qu[i].fi][qu[i].se] << '\n';
        else cout << -1 << '\n';
    }
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
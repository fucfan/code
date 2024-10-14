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
#define file "tram"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , q , par[N] , lev[N] , ans;
bool im[N] , removed[N];
queue <int> del;
vector <int> adj[N];
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n - 1 ; i++){
        int a , b;
        cin >> a >> b;
        adj[b].pb(a);
        adj[a].pb(b);
        lev[a]++;
        lev[b]++; 
    }
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int x , y;
        cin >> x >> y;
        im[x] = true;
        im[y] = true;
    }
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
            // cout << lev[i] << '\n';
        if(!im[i] && lev[i] == 1 && !removed[i]){
            removed[i] = true;
            del.push(i);
        }
    }
    while(del.size()){
        int u = del.front();
            ans++;
            del.pop();
        for(auto v : adj[u]){
            lev[v]--;
            if(lev[v] == 1 && !im[v]){
                del.push(v);
            }
        }
    }
    if(ans == n) ans--;
    cout << ans;
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
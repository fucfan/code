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
int n;
long u , v , w;
ll dis[N];
bool vst[N] , cor[N];
vector <pair <int , long>> x[N];
void DFS(int i , ll d){
    dis[i] = d;
    vst[i] = true;
    for(auto j : x[i]){
        if(!vst[j.fi]){ 
            DFS(j.fi , d + j.se);
        }
    }
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n - 1 ; i++){
        cin >> u >> v >> w;
        x[u].pb({v , w});
        x[v].pb({u , w});
    }
}

void solve()
{
    DFS(1 , 0);
    for(int i = 1 ; i <= n ; i++){
        if(dis[i] % 2 == 0) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
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
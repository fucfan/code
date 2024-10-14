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
ll n,m,a[1007][1007],b,cnt;

bool vst[1007][1007];
char g;
vector<pii> gg;
void dfs(int x,int y,int g){
    vst[x][y]=true;
    a[x][y]=g;
    for(auto g : gg){
        int u=g.fi+x;
        int v=g.se+y;
        if(u <= 0 || u > n || v <= 0 || v > m || vst[u][v] || a[u][v]==-1 || a[u][v] != g) continue;
        dfs(u,v,g);
    }
}
void dfs1(int x,int y){
    vst[x][y]=true;
    a[x][y]=g;
    for(auto g : gg){
        int u=g.fi+x;
        int v=g.se+y;
        if(u <= 0 || u > n || v <= 0 || v > m || vst[u][v] || a[u][v]==-1) continue;
        dfs1(u,v);
    }
}
void inp()
{
    cin>>n>>m;
    mem(vst , false);
    gg.pb({1,0});
    gg.pb({-1,0});
    gg.pb({0,1});
    gg.pb({0,-1});
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g;
            if(g=='T') a[i][j]=0;
            if(g=='B') a[i][j]=1;
            if(g=='*') a[i][j]=-1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vst[i][j] && a[i][j] == a[1][1]){
                dfs(i,j,!a[1][1]);cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vst[i][j]){
                dfs1(i,j);cnt++;
            }
        }
    }
    cout<<cnt;
}

void solve()
{
    
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
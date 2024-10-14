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
int n , m , k , par[N] , sz[N];
struct path{
    int u , v;
};
void make_set(){
    for(int i = 1 ; i <= n ; i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int get(int a){
    if(a != par[a]) return get(par[a]);
    return a;
}
void uni(int a , int b){
    a = get(a);
    b = get(b);
    if(sz[a] > sz[b]) swap(a , b);
    par[a] = b;
    sz[b] += sz[a];
}
vector <path> edge[2];
void inp()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        int a , b , c;
        cin >> a >> b >> c;
        edge[c].pb({a , b});
    }
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
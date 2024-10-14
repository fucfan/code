#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const long long oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , m , a , b ;
long c;
vector <pair <int , long>> x[N];
void dijkstra(int s){
    priority_queue <pii , vector <pii> , greater <pii>> q;
    vector <ll> d(n + 1 , oo);
    d[s] = 0;
    q.push({0 , s});
    while(!q.empty()){
        int u = q.top().se;
        int dis = q.top().fi;
        q.pop();
        if(dis > d[u]) continue;
        for(auto it : x[u]){
            int v = it.fi;
            int w = it.se;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v] , v});
            }
        }
    }
    for(int i = 1; i <= n ; i++){
        cout << d[i] << " ";
    }
}
void inp()
{
    cin >> n >> m ;
    for(int i = 1; i <= m ;i++){
        cin >> a >> b >> c;
        x[a].pb({b , c});
    }
}

void solve()
{
    dijkstra(1);
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
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
#define file "taitrong"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int n , m , s , t , x , y , z;
vector <pii> a[N];
void djsktra(int s , int t){
    vector <ll> d(n + 1 , -oo);
    priority_queue <pii , vector <pii>> q;
    d[s] = oo * 2;
    q.push({d[s] , s});
    while(!q.empty()){
        int u = q.top().se;
        ll dis = q.top().fi;
        q.pop();
        if(dis < d[u]) continue;
        for(auto it : a[u]){
            int v = it.fi;
            ll w = it.se;
            if(d[v] < min(d[u] , w)){
                d[v] = min(d[u] , w);
                q.push({w , v});
            }
        }
    }
    cout << d[t];
}
void inp()
{
    cin >> n >> m >> s >> t;
    for(int i = 1 ; i <= m ; i++){
        cin >> x >> y >> z;
        a[x].pb({y , z});
        a[y].pb({x , z});
    }
}

void solve()
{
    djsktra(s , t);
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
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int , int>
#define pb push_back
#define name "shgy"
#define mem(a , b) memset((a) , (b) , sizeof((a)))

const int LOG = 20;
const int N = 2e5 + 5;
const int oo = 1e9 + 7;

using namespace std;

int n , m , d[1003] , cty[N];
ll ans1 , ans2;
vector <int> adj[N];
string s;

void dijsktra(int st){
    mem(d , 0x3f);
    d[st] = 0;
    priority_queue<pii , vector<pii> , greater<pii>> q;
    q.push({0 , st});
    while(q.size()){
        int u = q.top().se;
        int dis = q.top().fi;
        q.pop();
        if(dis > d[u]) continue;
        for(auto v : adj[u]){
            int len = d[u] + 1;
            if(cty[v] != cty[st]) len += 3;
            if(d[v] > len){
                d[v] = len;
                q.push({d[v] , v});
            }
        }
    }
    for(int i = st + 1 ; i <= n ; i++){
        if(cty[i] == cty[st]){
            if(cty[st]) ans1 += d[i];
            else ans2 += d[i];
        }
    }
}

int main(){
    freopen(name".inp" , "r" , stdin);
    freopen(name".out" , "w" , stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == 'Y')cty[i + 1] = 1;
    }
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1 ; i <= n ; i++) dijsktra(i);
    cout << ans2 << ' ' << ans1;
}

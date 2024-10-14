#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll , ll>
#define fi first
#define se second
#define pb push_back
#define all(c) (c).begin() , (c).end()
#define name "school"

const int N = 1e5 + 5;
const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;

using namespace std;

int n , m , k , house[N];
ll x;
vector <pii> adj[N];

int sub1(int i){
    vector <ll> d(n + 5 , oo);
    priority_queue<pii , vector<pii> , greater<pii>> q;
    q.push({0 , i});
    d[i] = 0;
    while(q.size()){
        int u = q.top().se;
        ll dis = q.top().fi;
        q.pop();
        if(dis > d[u]) continue;
        for(auto it : adj[u]){
            int v = it.fi;
            ll w = it.se;
            if(d[v] > d[u] + w && d[u] + w <= x){
                d[v] = d[u] + w;
                q.push({d[v] , v});
            }
        }
    }
    int res = 0;
    for(int i = n ; i >= 1 ; i--){
        if(d[i] <= x){
            res = i;
            break;
        }
    }
    return res;
}

int sub3(){
    vector <ll> d(n + 5 , oo);
    priority_queue<pii , vector<pii> , greater<pii>> q;
    int Max = 0;
    int ans = n + 1;
    for(int j = 1 ; j <= k ; j++){
        int i = house[j];
        q.push({0 , i});
        d[i] = 0;
        while(q.size()){
            int u = q.top().se;
            ll dis = q.top().fi;
            q.pop();
            if(dis > d[u]) continue;
            for(auto it : adj[u]){
                int v = it.fi;
                ll w = it.se;
                if(d[u] + w <= x){
                    d[v] = d[u] + w;
                    q.push({d[v] , v});
                }
            }
        }
        int res = 0;
        for(int i = n ; i >= 1 ; i--){
            if(d[i] <= x){
                res = i;
                break;
            }
        }
        ans = min(ans , res);
    }
    cout << ans;
}

int main(){
    freopen(name".inp" , "r" , stdin);
    freopen(name".out" , "w" , stdout);
    cin >> n >> m >> k >> x;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
    for(int i = 1 ; i <= k ; i++){
        cin >> house[i];
    }
    if(k == 1) cout << sub1(house[1]);
    else{
        int ans = n + 1;
        for(int i = 1 ; i <= k ; i++){
            ans = min(ans , sub1(house[i]));
        }
        cout << ans;
    }
}

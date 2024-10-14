#include <bits/stdc++.h>
#define BIT(x , i) (((x) >> (i)) & 1)
#define flip(x , i) ((x) ^ (1 << (i)))
#define ll long long
#define fi first
#define se second
#define pii pair <int , int>
#define all(c) (c).begin() , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(a))
#define nl cout << '\n';
#define pb push_back
#define file "test"

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

int n , m , k;
int st[N] , en[N] , type[N] , num_st[N] , num_en[N];
vector <pii> adj[N];
vector <int> order;
ll d[21][N];
ll dp[N][50] , dp1[N];

void dijsktra(int s , int num){
    priority_queue <pii , vector<pii> , greater<pii>> q;
    q.push({0 , s});
    mem(d[num] , 0x3f);
    d[num][s] = 0;

    while(q.size()){
        int u = q.top().se;
        ll dis = q.top().fi;

        q.pop();

        if(dis > d[num][u]) continue;

        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            if(d[num][v] > d[num][u] + w){
                d[num][v] = d[num][u] + w;
                q.push({d[num][v] , v});
            }
        }
    }
}

void sub1(){

    ll ans = 0;

    for(int i = 1 ; i <= n ; i++){
        bool check1;
        bool check2;
        check1 = check2 = 0;
        for(auto it : adj[i]){
            int j = it.fi;
            int w = it.se;

            if(d[num_en[1]][j] + d[num_st[1]][i] + w == d[num_st[1]][en[1]]) check1 = 1;
            if(d[num_en[2]][j] + d[num_st[2]][i] + w == d[num_st[2]][en[2]]) check2 = 1;
        }

        if(d[num_en[1]][i] + d[num_st[1]][i] == d[num_st[1]][en[1]]) check1 = 1;
        if(d[num_en[2]][i] + d[num_st[2]][i] == d[num_st[2]][en[2]]) check2 = 1;

        if(check1 && check2){
            ans = max(ans , d[num_st[1]][i]);
        }
    }

    cout << ans;
}

int ok(int u , int v , ll w){
    if(d[num_st[1]][u] + d[num_en[1]][v] + w != d[num_st[1]][en[1]]) return 0;

    for(int i = 2 ; i <= k ; i++){
        if(d[num_st[i]][u] + d[num_en[i]][v] + w == d[num_st[i]][en[i]]) return 1;
    }

    return 2;
}

ll sol1(int i){
    if(dp1[i] != -1) return dp1[i];

    ll res = 0;

    for(auto it : adj[i]){
        int j = it.fi;
        int w = it.se;

        // cout << j << ' ' << d[num_st[1]][en[1]] << ' ' << st[1] << ' ' << en[1] << "gg\n";

        // cout << d[num_st[1]][i] << ' ' << d[num_en[1]][j] << ' ' << w << '\n';

        int tmp = ok(i , j , w);

        if(tmp == 1){
            res = max(res , sol1(j) + w);
        }
        else if(tmp) res = max(res , sol1(j));
    }

    return dp1[i] = res;
}

ll sol2(int i , int mask){
    // cout << i << ' ' << mask << '\n';
    if(dp[i][mask] != -1) return dp[i][mask];

    ll res = 0;

    for(auto it : adj[i]){
        int j = it.fi;
        int w = it.se;
        int cnt = 0;

        bool check = 0;
            
        if(d[num_st[1]][i] + d[num_en[1]][j] + w != d[num_st[1]][en[1]]) continue;

        for(int f = 2 ; f <= k ; f++){
            cnt += type[f];
            if(d[num_st[f]][i] + d[num_en[f]][j] + w == d[num_st[f]][en[f]]){
                if(type[f]){
                    if(BIT(mask , cnt - 1)) check = 1;
                }
                else if(d[num_st[f]][i] == d[num_st[1]][i]){
                    check = 1;
                }
            }
        }

        cnt = 0;

        if(check) res = max(res , sol2(j , mask) + w);
        else{
            res = max(res , sol2(j , mask));

            for(int f = 2 ; f <= k ; f++){
                cnt += type[f];
                if(d[num_st[f]][i] + d[num_en[f]][j] + w == d[num_st[f]][en[f]]){
                    if(type[f]){
                        if(!BIT(mask , cnt - 1)) 
                            res = max(res , sol2(j , flip(mask , cnt - 1)) + w);
                    }
                }
            }
        }
    }

    return dp[i][mask] = res;
}

void sub23(){
    mem(dp , -1);
    mem(dp1 , -1);
    ll ans = 0;

    if(type[2]){
        // for(int i = 1 ; i <= n ; i++){
        //     ans = max(ans , sol1(i));
        // }

        ans = max(ans , sol1(st[1]));
    }    
    else{
        for(int i = 1 ; i <= n ; i++){
            if(d[num_st[1]][i] == d[num_st[2]][i]){
                ans = max(ans , sol1(i));
            }
        }
    }

    cout << ans;
}

void sub4(){
    mem(dp , -1);

    ll ans = 0;
    int mask = 0;

    ans = max(sol2(st[1] , 0) , ans);

    cout << ans;
}

void inp()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
    cin >> st[1] >> en[1];
    for(int i = 2 ; i <= k ; i++){
        cin >> type[i] >> st[i] >> en[i];
    }
}

void solve()
{
    order.pb(0);
    for(int i = 1 ; i <= k ; i++){
        order.pb(st[i]);
        order.pb(en[i]);
    }

    sort(all(order));
    for(int i = 1 ; i <= k ; i++){
        num_st[i] = lower_bound(all(order) , st[i]) - order.begin();
        num_en[i] = lower_bound(all(order) , en[i]) - order.begin();
    }

    for(int i = 1 ; i < order.size() ; i++){
        dijsktra(order[i] , i);
    }

    // sub4();
     if(k == 2){
        if(st[2] == st[1]) sub1();
        else sub23();
     }
     else sub4();
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
//    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

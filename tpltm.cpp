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
int n , m , low[N] , num[N] , d , cnt;
vector <int> adj[N] , scc[N];
stack <int> node;
pair <pii , int> res[N];
bool check[N];
int ans;
bool cmp(pair<pii , int> a , pair <pii , int> b){
    if(a.fi.fi == b.fi.fi){
        return a.fi.se < b.fi.se;
    }
    return a.fi.fi < b.fi.fi;
}
void dfs(int i){
    node.push(i);
    num[i] = low[i] = d;
    d++;
    for(auto j : adj[i]){
        if(check[j]) continue;
        if(!num[j]){
            dfs(j);
            low[i] = min(low[i] , low[j]);
        }
        else low[i] = min(low[i] , num[j]);
    }
    // if(low[i] == num[i]){
    //     cout << i << '\n';
    //     for(auto j : node) cout << j << ' ';
    //     cout << "--\n";
    // }
    if(low[i] == num[i]){
        cnt++;
        // cout << i << '\n';
        // cout << node.top() << ' ';
        int cmp = i;
        while(node.size()) {
            check[node.top()] = true;
            if(node.top() == i){
                scc[cnt].pb(i);
                node.pop();
                break;
            }
            scc[cnt].pb(node.top());
            cmp = min(cmp , node.top());
            node.pop();
        }
        res[cnt].se = cnt;
        res[cnt].fi.fi = scc[cnt].size();
        res[cnt].fi.se = cmp;
    }
    // nl;
}
void inp()
{
    cin >> n >> m;
    d = 1;
    for(int i = 1 ; i <= m ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
    }
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        if(!num[i]){
            dfs(i);
        // cout << i << ' ' << cnt << '\n';
        }
        // cout << low[i] << ' ';
    }
    cout << cnt << '\n';
    // for(int i = 1 ; i <= cnt ; i++){
    //     for(auto j : scc[i]){
    //         cout << j << ' ';
    //     }
    //     nl;
    // }
    // for(int i = 1 ; i <= cnt ; i++){
    //     // cout << res[i].fi.fi << '\n';
    //     // for(auto j : scc[res[i].se]){
    //     //     cout << j << ' ';
    //     // }
    //     // nl;
    // }
    sort(res + 1 , res + 1 + cnt , cmp);
    for (int i = 1; i <= cnt; i++)
    {
        int tmp = res[i].se;
        sort(all(scc[res[i].se]));
        cout << scc[tmp].size() << "\n";
        for (auto v : scc[tmp])
        {
            cout << v << " ";
        }
        nl;
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
    // run_with_file();
    inp();
    solve();
}
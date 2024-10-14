#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getbit(a , b) ((a) & (1 << (b)))
#define turnon(a , b) ((a) | (1 << (b)))
#define turnoff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "sconnect"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , m , low[N] , num[N] , d;
bool vst[N];
stack <int> node;
vector<int> adj[N];
void dfs(int i){
    // cout << i << '\n';
    node.push(i);
    num[i] = low[i] = ++d;
    for(auto j : adj[i]){
        if(vst[j]) continue;
        if(!num[j]){
            dfs(j);
            low[i] = min(low[i] , low[j]);
        }
        else low[i] = min(low[i] , num[j]);
    }
    if(low[i] == num[i]){
        while(node.size()){
            vst[node.top()] = 1;
            if(low[node.top()] == num[node.top()]){
                cout << node.top() << '\n';
                node.pop();
                break;
            }
            cout << node.top() << ' ';
            node.pop();
        }
    }
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
    }
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        if(!num[i]) dfs(i);
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
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UwU      */
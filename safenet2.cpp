#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int n , m , num[N] , low[N] , num_node , num_group , group[N] , cnt[N] , ans;
bool vst[N];
vector <int> adj[N];
stack <int> node;

void dfs(int i){
    // cout << i << '\n';
    num[i] = low[i] = ++num_node;
    node.push(i);
    for(auto j : adj[i]){
        if(!num[j]){
            dfs(j);
            low[i] = min(low[i] , low[j]);
        }
        else low[i] = min(low[i] , num[j]);
    }

    if(low[i] == num[i]){
        num_group++;
        while(node.size()){
            int v = node.top();
            cout << v << ' ';
            group[v] = num_group;
            cnt[num_group]++;
            ans = max(ans , cnt[num_group]);
            node.pop();
            if(v == i) break;
        }
        nl;
    }
}

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        // adj[v].pb(u);
    }
}

void solve(){
    dfs(1);
    cout << min(ans + 1 , n);
}

void run_with_file(){
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UMU      */
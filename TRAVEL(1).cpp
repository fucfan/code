#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "travel"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , m , k , num[N] , low[N] , scc , num_scc[N] , num_node , child[N] , depth[N] , sz[N];
vector <int> adj[N] , big_adj[N] , vt[N];
stack <int> node;
ll ans = 0;
bool vst[N];

void dfs(int i , int p){
    low[i] = num[i] = num_node++;
    node.push(i);

    int cnt = 0;

    for(auto j : adj[i]){
        if(j == p && !cnt){
            cnt++;
            continue;
        }
        if(vst[j]) continue;
        if(!num[j]){
            dfs(j , i);
            low[i] = min(low[i] , low[j]);
        }
        else{
            low[i] = min(low[i] , num[j]);
        }
    }

    if(low[i] == num[i]){
        scc++;

        // cout << scc << " :\n";
        
        while(node.size()){
            int u = node.top();

            // cout << u << ' ';
            
            node.pop();

            num_scc[u] = scc;
            vst[u] = 1;
            sz[scc]++;

            for(auto v : adj[u]){
                if(num_scc[v] && num_scc[v] != num_scc[u]){
                    big_adj[num_scc[u]].pb(num_scc[v]);
                    big_adj[num_scc[v]].pb(num_scc[u]);
                }
            }

            if(low[u] == num[u]) break;
        }
        // nl;
    }
}

struct fenwick_tree{
    ll node[N];

    void update(int pos , int val){
        for(; pos <= n ; pos += (pos & -pos)){
            node[pos] += val;
        }
    }

    ll get(int pos){
        ll res = 0;
        for(; pos >= 1 ; pos -= (pos & -pos)){
            res += node[pos];
        }
        return res;
    }
} BIT;

void dfs_child(int i , int p){
    child[i] = 1;

    for(auto j : big_adj[i]){
        if(j == p) continue;
        depth[j] = depth[i] + 1;
        dfs_child(j , i);
        child[i] += child[j];
    }
}

void sack(int i , int p , int keep){
    int Max = -1;
    int best_node = -1;

    for(auto j : big_adj[i]){
        if(j == p) continue;
        if(child[j] > Max){
            Max = child[j];
            best_node = j;
        }
    }

    for(auto j : big_adj[i]){
        if(j == p || j == best_node) continue;
        sack(j , i , 0);
    }

    if(best_node != -1) sack(best_node , i , 1);

    swap(vt[i] , vt[best_node]);

    vt[i].pb(i);
    ans += 1ll * sz[i] * (BIT.get(n) - BIT.get(depth[i] + k - 1));
    BIT.update(depth[i] , sz[i]);

    // cout << i << " :\n";

    for(auto j : big_adj[i]){
        if(j == p || j == best_node) continue;
        for(auto x : vt[j]){
            ans += 1ll * sz[x] * (BIT.get(n) - BIT.get(depth[i] + k - (depth[x] - depth[i]) - 1));
        }

        for(auto x : vt[j]){
            BIT.update(depth[x] , sz[x]);
            vt[i].pb(x);
        }
    }

    // for(int i = 1 ; i <= n ; i++) cout << BIT.get(i) << ' ';
    // nl;

    // for(auto j : vt[i]) cout << j << ' ';
    // nl;

    if(!keep){
        for(auto j : vt[i]){
            BIT.update(depth[j] , -sz[j]);
        }
    }
}

void prepare(){
    depth[1] = 1;

    dfs(1 , 0);
    dfs_child(1 , 0);

    // for(int i = 1 ; i <= scc ; i++){
    //     cout << i << " :";
    //     for(auto j : big_adj[i]) cout << j << ' ';
    //     nl;
    // }

    sack(1 , 0 , 0);
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    prepare();
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
/*#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".ans", "w" , stdout);
    }
}

int n , m , k , num[N] , low[N] , scc , num_scc[N];
int num_node , child[N] , depth[N] , sz[N] , par[N][LOG + 5];
vector <int> adj[N] , big_adj[N] , vt[N];
stack <int> node;
ll ans = 0;
bool vst[N];

void dfs(int i , int p){
    low[i] = num[i] = num_node++;
    node.push(i);

    int cnt = 0;

    for(auto j : adj[i]){
        if(j == p && !cnt){
            cnt++;
            continue;
        }
        if(vst[j]) continue;
        if(!num[j]){
            dfs(j , i);
            low[i] = min(low[i] , low[j]);
        }
        else{
            low[i] = min(low[i] , num[j]);
        }
    }

    if(low[i] == num[i]){
        scc++;

        // cout << scc << " :\n";
        
        while(node.size()){
            int u = node.top();

            // cout << u << ' ';
            
            node.pop();

            num_scc[u] = scc;
            vst[u] = 1;
            sz[scc]++;

            for(auto v : adj[u]){
                if(num_scc[v] && num_scc[v] != num_scc[u]){
                    big_adj[num_scc[u]].pb(num_scc[v]);
                    big_adj[num_scc[v]].pb(num_scc[u]);
                }
            }

            if(low[u] == num[u]) break;
        }
        // nl;
    }
}

void dfs_child(int i , int p){
    child[i] = 1;

    for(auto j : big_adj[i]){
        if(j == p) continue;
        depth[j] = depth[i] + 1;
		par[j][0] = i;
        dfs_child(j , i);
        child[i] += child[j];
    }
}

void prepare(){
    depth[1] = 1;

    dfs(1 , 0);
    dfs_child(1 , 0);
	
	for(int j = 1 ; j <= LOG ; j++){
		for(int i = 1 ; i <= n ; i++){
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}

int lca(int u , int v){
	if(depth[u] > depth[v]) swap(u , v);
	
	for(int i = LOG ; i >= 0 ; i--){
		if(depth[par[v][i]] >= depth[u])
			v = par[v][i];
	}

	if(u == v) return u;

	for(int i = LOG ; i >= 0 ; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void solve(){
    prepare();
	
	for(int i = 1 ; i < scc ; i++){
		for(int j = i + 1 ; j <= scc ; j++){
			int ancestor = lca(i , j);

			if(depth[i] + depth[j] - 2 * depth[ancestor] >= k){
				ans += 1ll * sz[i] * sz[j];
			}
		}
	}

	cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
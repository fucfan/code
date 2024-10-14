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
#define file "phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 4e5 + 5;
int n , q , en[N] , pos[N] , par[N][22] , h[N] , cnt_child[N] , tree[4 * N];
int par_not1[N] , closed[N];
set <pii> s[N];
vector <int> adj[N] , tour;
void update(int id , int l , int r , int pos , int val){
    if(pos < l || pos > r) return;
    if(l == r){
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 , l , mid , pos , val);
    update(id * 2 + 1 , mid + 1 , r , pos , val);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
int get(int id , int l , int r , int u , int v){
    if(u > r || l > v) return 0;
    if(u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    int a = get(id * 2 , l , mid , u , v);
    int b = get(id * 2 + 1 , mid + 1 , r , u , v);
    return a + b;
}
pii dfs(int i , int p , int group){
    tour.pb(i);
    pos[i] = tour.size() - 1;
    bool check = 1;
    if(i == 1) check = 0;
    for(int g = 0 ; g < adj[i].size() ; g++){
        int j = adj[i][g];
        if(j != p){
            par[j][0] = i;
			// cout << j << ' ' << par[j][0] << '\n';
			if(par[j][0] == 1) group = j;
			par_not1[j] = group;
            h[j] = h[i] + 1;
            pii new_node = dfs(j , i , group);
			cnt_child[i] += new_node.se;
            if(g + check == adj[i].size() - 1){
                en[i] = new_node.fi;
				cnt_child[i]++;
                return {new_node.fi , cnt_child[i]};
            }
        }
        else check = false;
    }
    en[i] = i;
	cnt_child[i] = 1;
    return {i , 1};
}
void prepare(){
    for(int j = 1 ; j <= 21 ; j++){
        for(int i = 1 ; i <= n ; i++){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
int lca(int u , int v){
    if(h[u] > h[v]) swap(u , v);
    int k = h[v] - h[u];
    for(int i = 0 ; 1 << i <= k ; i++){
        if((k >> i) & 1) v = par[v][i];
    }
    // cout << u << ' ' << v << '\n';
    if(u == v) return u;
    for(int i = 21 ; i >= 0 ; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    if(u != v) u = par[u][0];
    return u;
}
void inp()
{
	int theta;
	cin >> theta;
    cin >> n >> q;
    for(int i = 2 ; i <= n ; i++){
        int a;
        cin >> a;
        adj[i].pb(a);
        adj[a].pb(i);
    }
}

void solve()
{
    dfs(1 , 0 , 1);
    prepare();
	int res = 0;
	int ans = 0;
	// for(int i = 1 ; i <= n ;i++) cout << i << ' ';
    // nl;
	for(int i = 1 ; i <= q ; i++){
        // cout << i << '\n';
		char a;
		int x;
		cin >> a >> x;
		if(a == '+'){
            s[par_not1[x]].insert({pos[x] , x});
			if(!closed[par_not1[x]]){
				update(1 , 0 , tour.size() - 1 , pos[x] , 1);
				res++;
				closed[par_not1[x]] = x;
				ans += cnt_child[x] - 1;
                // cout << x << ' ' << cnt_child[x] << '\n';
			}
			else{
				int u = par_not1[x];
				ans -= (cnt_child[closed[u]] - get(1 , 0 , tour.size() - 1 , pos[closed[u]] , pos[en[closed[u]]]));
				closed[u] = lca(x , closed[u]);
				update(1 , 0 , tour.size() - 1 , pos[x] , 1);
				ans += (cnt_child[closed[u]] - get(1 , 0 , tour.size() - 1 , pos[closed[u]] , pos[en[closed[u]]]));
			}
		}
		else{
			int u = par_not1[x];
            ans -= cnt_child[closed[u]] - get(1 , 0 , tour.size() - 1 , pos[closed[u]] , pos[en[closed[u]]]);
            update(1 , 0 , tour.size() - 1 , pos[x] , 0);
            s[u].erase({pos[x] , x});
            if(s[u].empty()){
                closed[u] = 0;
                res--;
            }
            else{
                pii p = *s[u].begin();
                int node1 = p.se;
                p = *s[u].rbegin();
                int node2 = p.se;
                int lca_par = lca(node1 , node2);
                // cout << node1 << ' ' << node2 << '\n';
                ans += cnt_child[lca_par] - get(1 , 0 , tour.size() - 1 , pos[lca_par] , pos[en[lca_par]]);
                closed[u] = lca_par;
            }
		}
		cout << res << ' ' << ans << '\n';
	}
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
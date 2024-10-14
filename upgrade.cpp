#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "upgrade"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

struct Edge{
	int u , v , w , id;
} edge[N];

bool cmp(Edge a , Edge b){
	return a.w > b.w;
}

bool cmp1(Edge a , Edge b){
	return a.id < b.id;
}

int n , m , k , ans , par[N] , sz[N] , q;
bool used[N];
pii up_edge;
vector <pair <int , pii>> adj[N];

void make_set(){
	for(int i = 1 ; i <= n ; i++){
		par[i] = i;
		sz[i] = 1;
	}
}

int get(int i){
	return (i == par[i] ? i : get(par[i]));
}

bool uni(int a , int b){
	a = get(a);
	b = get(b);
	if(a == b) return 0;
	if(sz[a] > sz[b]) swap(a , b);	
	par[a] = b;
	sz[b] += sz[a];
	return 1;
}

bool update(int i , int p , int node){
	if(!i) return 0;
	bool res = 0;

	for(auto j : adj[i]){
		if(j.fi == p) continue;
		if(update(j.fi , i , node)){
			up_edge = min(up_edge , j.se);
			res = 1;
		}
	}

	if(i == node) return 1;

	return res;
}

void inp()
{
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int u , v , w;
		cin >> u >> v >> w;
		edge[i] = {u , v , w , i};
	}
}

void solve()
{
	sort(edge + 1 , edge + 1 + m , cmp);

	make_set();

	for(int i = 1 ; i <= m ; i++){
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int id = edge[i].id;

		if(uni(u , v)){
			used[id] = 1;
			// cout << id << '\n';
			adj[u].pb({v , {w , id}});
			adj[v].pb({u , {w , id}});
			ans += w;
		}
	}

	sort(edge + 1 , edge + 1 + m , cmp1);

	cin >> q;

	for(int i = 1 ; i <= q ; i++){
		int id , val;
		cin >> id >> val;
		edge[id].w += val;
		// cout << edge[id].u << ' ' << edge[id].v << ' ' << used[id] << '\n';
		if(used[id]){
			int u = edge[id].u;
			for(auto &it : adj[u]){
				int v = it.fi;
				if(v == edge[id].v){
					it.se.fi += val;
					break;
				}
			}

			u = edge[id].v;

			for(auto &it : adj[u]){
				int v = it.fi;
				if(v == edge[id].u){
					it.se.fi += val;
					break;
				}
			}

			ans += val;
			cout << ans << '\n';
		}
		else{
			up_edge = {k + 1 , m + 1};
			update(edge[id].u , 0 , edge[id].v);

			// cout << ans << ' ' << edge[id].w << ' ' << up_edge.fi << ' ' << up_edge.se << '\n';

			if(up_edge.fi < edge[id].w){
				ans -= up_edge.fi;
				ans += edge[id].w;

				used[edge[id].id] = 1;
				used[up_edge.se] = 0;

				int u = edge[up_edge.se].u;
				for(auto &it : adj[u]){
					int v = it.fi;
					if(v == edge[up_edge.se].v){
						it = {0 , {0 , 0}};
						break;
					}
				}

				u = edge[up_edge.se].v;

				for(auto &it : adj[u]){
					int v = it.fi;
					if(v == edge[up_edge.se].u){
						it = {0 , {0 , 0}};
						break;
					}
				}

				adj[edge[id].u].pb({edge[id].v , {edge[id].w , id}});
				adj[edge[id].v].pb({edge[id].u , {edge[id].w , id}});
			}

			cout << ans << '\n';
		}
	}
}

void run_with_file()
{
    if (fopen(file".inp", "r"))
    {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
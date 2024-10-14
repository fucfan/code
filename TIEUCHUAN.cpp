#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "tieuchuan"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 100 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int d[N][N * N];
int n, m, s, t;
vector <pair<int, pii>> adj[N];

void dijkstra(int st){
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
	mem(d, 0x3f);
	d[st][0] = 0;

	q.push({0, {st, 0}});
	// cout << d[t][0] << '\n';

	while(q.size()){
		pii u = q.top().se;
		int dis = q.top().fi;

		q.pop();

		if(dis > d[u.fi][u.se]) continue;
		// cout << u.fi << ' ' << u.se << ' ' << dis << '\n';

		for(auto it : adj[u.fi]){
			pii v;
			int w = it.se.se;
			v.fi = it.fi;
			v.se = u.se + it.se.fi;

			if(v.se > 10000) continue;

			if(d[v.fi][v.se] > d[u.fi][u.se] + w){
				d[v.fi][v.se] = d[u.fi][u.se] + w;
				q.push({d[v.fi][v.se], v});
			}
		}
	}

	int cnt = 0; 
	int Min = oo;
	// cout << d[t][0] << '\n';
	for(int i = 0; i <= 10000; i++){
		if(d[t][i] >= Min) d[t][i] = oo;
		Min = min(Min, d[t][i]);
	}

	for(int i = 0; i <= 10000; i++){
		if(d[t][i] < oo){
			// cout << i << ' ' << d[t][i] << '\n';
			cnt++;
		}
	}

	cout << cnt;
}

void inp(){
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
    	int u, v, w1, w2;
    	cin >> u >> v >> w1 >> w2;
    	adj[u].pb({v, {w1, w2}});
    	adj[v].pb({u, {w1, w2}});
    }
}

void solve(){
    dijkstra(s);
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
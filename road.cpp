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
#define file "road"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 500 + 5;
const int LOG = 20;
int n , m;
double d[N][N] , d1[N][N] , adj[N][N];
bool used_ij[N][N];
struct edges{
	int u , v , w;
} edge[20001];
void prepare(){
	mem(used_ij , 1);
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i == j){
				adj[i][j] = 0;
				d[i][j] = 0;
				d1[i][j] = 0;
			}
			else{
				d[i][j] = oo;
				d1[i][j] = oo;
			}
			if(adj[i][j] != -1) d[i][j] = adj[i][j];
			if(i == j) d[i][j] = 0;
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(adj[i][k] != -1 && adj[k][j] != -1 && i != k && k != j) 
				d1[i][j] = min(d1[i][j] , adj[i][k] + adj[k][j]);
			}
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(d[i][j] > d[i][k] + d[k][j]) used_ij[i][j] = 0;
 				d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
 				d1[i][j] = min(d1[i][j] , d1[i][k] + d1[k][j]);
			}
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				
			}
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cout << d1[i][j] << ' ';
		}
		nl;
	}
}
void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++) adj[i][j] = -1;
	}
	for(int i = 1 ; i <= m ; i++){
		int a , b , c;
		cin >> a >> b >> c;
		edge[i] = {a , b , c};
		adj[a][b] = adj[b][a] = c;
	}
}

void solve()
{
	prepare();
	double ans = 0;
	for(int i = 1 ; i < n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			for(int k = 1 ; k <= m ; k++){
				// if(i == edge[k].u || i == edge[k].v || j == edge[k].u || j == edge[k].v) continue;
				int u = edge[k].u;
				int v = edge[k].v;
				if(d1[u][v] < oo)
					ans = max(ans ,  (d[i][u] + d[v][j] + d1[u][v]) / (d[i][u] + d[v][j] + edge[k].w));
			}
		}
	}
	cout << setprecision(4) << fixed << ans;
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
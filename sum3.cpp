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
#define file "sum3"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , q , up[N][LOG + 5] , h[N];
ll rmq[N][LOG + 5] , val[N];
vector <int> adj[N];
void dfs(int i , int p){
	for(auto j : adj[i]){
		if(j == p) continue;
		h[j] = h[i] + 1;
		up[j][0] = i;
		dfs(j , i);
	}
}
void prepare(){
	h[0] = -1;
	for(int j = 1 ; j <= LOG ; j++){
		for(int i = 1 ; i <= n ; i++){
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
}
int lca(int u , int v , int val){
	int f_u = u;
	int f_v = v;
	if(h[u] > h[v]){
		swap(u , v);
		swap(f_u , f_v);
	}
	for(int i = LOG ; i >= 0 ; i--){
		if(h[up[v][i]] >= h[u]){
			// cout << v << ' ' << i << '\n';
			rmq[v][i] += val;
			v = up[v][i];
		}
	}
	// nl;
	// cout << u << ' ' << v << '\n';
	for(int i = LOG ; i >= 0 ; i--){
		if(up[u][i] != up[v][i]){
			rmq[u][i] += val;
			rmq[v][i] += val;
			u = up[u][i];
			v = up[v][i];
		}
	}
	if(u != v){
		rmq[u][0] += val;
		rmq[v][0] += val;
		return up[u][0];
	}
	return v;
// 	if(u != f_u) rmq[f_u][0] += val;
// 	if(v != f_v) rmq[f_v][0] += val;
}
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> val[i];
	}
	for(int i = 1 ; i < n ; i++){
		int a , b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1 , 0);
	prepare();
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int a , b , c;
		cin >> a >> b >> c;
		int node = lca(a , b , c);
		rmq[node][0] += c;
	}
	for(int j = LOG ; j >= 1 ; j--){
		for(int i = 1 ; i <= n ; i++){
			// rmq[i][0] += rmq[i][j];
			rmq[i][j - 1] += rmq[i][j];
			rmq[up[i][j - 1]][j - 1] += rmq[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		cout << rmq[i][0] + val[i] << ' ';
	}
}

void solve()
{

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
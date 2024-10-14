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
#define file "test"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e2 + 5;
const int LOG = 20;

int n , adj[21][21] , dp[21][(1 << 20)];
int par[21][(1 << 20)] , path[21][21];

void prepare(){
	for(int k = 0 ; k <= 2 * n ; k++){
		for(int i = 0 ; i <= 2 * n ; i++){
			for(int j = 0 ; j <= 2 * n ; j++){
				if(adj[i][j] > adj[i][k] + adj[k][j]){
					adj[i][j] = adj[i][k] + adj[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

int sol(int i , int mask){	
	if(mask == (1 << (2 * n)) - 1) return adj[i][0];

	if(dp[i][mask] != -1) return dp[i][mask];

	int res = oo;

	for(int j = 1 ; j <= 2 * n ; j++){

		if(BIT(mask , j - 1)) continue;

		if(j > n){
			if(BIT(mask , j - n - 1)){
				int tmp = sol(j , mask ^ (1 << (j - 1))) + adj[i][j];
				if(res > tmp){
					res = tmp;
					par[i][mask] = j;
				}
			}
		}
		else{
			int tmp = sol(j , mask ^ (1 << (j - 1))) + adj[i][j];
			if(res > tmp){
				res = tmp;
				par[i][mask] = j;
			}
		}
	}

	return dp[i][mask] = res;
}

void inp()
{
	cin >> n;
	for(int i = 0 ; i <= 2 * n ; i++){
		for(int j = 0 ; j <= 2 * n ; j++){
			cin >> adj[i][j];
			path[i][j] = i;
		}
	}
}

void solve()
{
	prepare();
	mem(par , -1);
	mem(dp , -1);

	cout << sol(0 , 0) << '\n';

	queue <int> trace;

	int i = 0 , mask = 0;

	while(i != -1){
		trace.push(i);

		if(par[i][mask] != -1){
			stack <int> st;

			int nxt_i = path[i][par[i][mask]];

			while(nxt_i != i){
				st.push(nxt_i);
				nxt_i = path[i][nxt_i];
			}

			while(st.size()){
				trace.push(st.top());
				st.pop();
			}
		}
		else{
			int tmp = 0;

			stack <int> st;

			while(tmp != i){
				st.push(tmp);
				tmp = path[i][tmp];
			}

			while(st.size()){
				trace.push(st.top());
				st.pop();
			}
		}

		i = par[i][mask];

		if(i != -1) mask ^= (1 << (i - 1));
	}

	cout << trace.size() << '\n';

	while(trace.size()){
		cout << trace.front() << ' ';
		trace.pop();
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
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
const int N = 2e6 + 5;
const int LOG = 20;

string s;
int n , cur , dp[N][5] , dp1[N][5];
vector <int> adj[N];

void inp()
{
	cin >> s;
	 n = s.size();
	 if(n == 0){
	 	cout << 0;
	 	exit(0);
	 }
}

void dfs(int i , int p){
	if(i == 0) return;

	for(auto j : adj[i]){
		if(j == p) continue;
		dfs(j , i);
	}

	if(adj[i].size() < 2){
		dp[i][1] = dp1[i][1] = 1;
		dp[i][2] = dp1[i][2] = 0;
		dp[i][3] = dp1[i][3] = 0;
		// dp[i][1] = min({dp[i][1] , dp[adj[i][0]][2] + 1 , dp[adj[i][0]][3] + 1});
		// dp[i][2] = min({dp[i][2] , dp[adj[i][0]][1] , dp[adj[i][0]][3]});
		// dp[i][3] = min({dp[i][3] , dp[adj[i][0]][1] , dp[adj[i][0]][2]});


		// dp1[i][1] = max({dp1[i][1] , dp1[adj[i][0]][2] + 1 , dp1[adj[i][0]][3] + 1});
		// dp1[i][2] = max({dp1[i][2] , dp1[adj[i][0]][1] , dp1[adj[i][0]][3]});
		// dp1[i][3] = max({dp1[i][3] , dp1[adj[i][0]][1] , dp1[adj[i][0]][2]});

		return;
	}
	if(adj[i].size() < 3){
		dp[i][1] = min({dp[i][1] , dp[adj[i][1]][2] + 1 , dp[adj[i][1]][3] + 1});
		dp[i][2] = min({dp[i][2] , dp[adj[i][1]][1] , dp[adj[i][1]][3]});
		dp[i][3] = min({dp[i][3] , dp[adj[i][1]][1] , dp[adj[i][1]][2]});

		dp1[i][1] = max({dp1[i][1] , dp1[adj[i][1]][2] + 1 , dp1[adj[i][1]][3] + 1});
		dp1[i][2] = max({dp1[i][2] , dp1[adj[i][1]][1] , dp1[adj[i][1]][3]});
		dp1[i][3] = max({dp1[i][3] , dp1[adj[i][1]][1] , dp1[adj[i][1]][2]});
	}
	else{
		dp[i][1] = min({dp[i][1] , dp[adj[i][1]][2] + dp[adj[i][2]][3] + 1 , dp[adj[i][1]][3] + dp[adj[i][2]][2] + 1});
		dp[i][2] = min({dp[i][2] , dp[adj[i][1]][1] + dp[adj[i][2]][3] , dp[adj[i][1]][3] + dp[adj[i][2]][1]});
		dp[i][3] = min({dp[i][3] , dp[adj[i][1]][2] + dp[adj[i][2]][1] , dp[adj[i][1]][1] + dp[adj[i][2]][2]});


		dp1[i][1] = max({dp1[i][1] , dp1[adj[i][1]][2] + dp1[adj[i][2]][3] + 1 , dp1[adj[i][1]][3] + dp1[adj[i][2]][2] + 1});
		dp1[i][2] = max({dp1[i][2] , dp1[adj[i][1]][1] + dp1[adj[i][2]][3] , dp1[adj[i][1]][3] + dp1[adj[i][2]][1]});
		dp1[i][3] = max({dp1[i][3] , dp1[adj[i][1]][2] + dp1[adj[i][2]][1] , dp1[adj[i][1]][1] + dp1[adj[i][2]][2]});
	}
}

void solve()
{	
	stack <int> st;

	cur = 1;
	st.push(cur);
	adj[1].pb(0);

	for(auto j : s){
		int c = j - '0';
		int v = st.top();
		st.pop();	

		for(int i = c ; i >= 1 ; i--){
			st.push(cur + i);
			adj[v].pb(cur + i);
			adj[cur + i].pb(v);
		}

		cur += c;
	}

	mem(dp , 0x3f);

	dfs(1 , 0);
	cout << max({dp1[1][1] , dp1[1][2] , dp1[1][3]}) << ' ' << min({dp[1][1] , dp[1][2] , dp[1][3]});
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
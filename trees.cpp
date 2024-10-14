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
#define file "trees"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , st[2][N] , en[2][N];
vector <int> adj1[N] , adj[N] , tour[2];
set <int> s[5][N];
void dfs(int i , int p){
	st[0][i] = tour[0].size();
	tour[0].pb(i);
	for(auto j : adj[i]){
		if(j == p) continue;
		dfs(j , i);
	}	
	en[0][i] = tour[0].size();
}
void dfs1(int i , int p){
	st[0][i] = tour[0].size();
	tour[0].pb(i);
	for(auto j : adj1[i]){
		if(j == p) continue;
		dfs1(j , i);
	}
	en[0][i] = tour[0].size() - 1;
}
// void dfs2(int i , int p , set<int> t1 , set<int> t2){
// 	for(auto j : adj[i]){
// 		if(j == p) continue;

// 	}

// }
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n - 1 ; i++){
		int x;
		cin >> x;
		adj[i].pb(x + 1);
		adj[x + 1].pb(i);
	}
	for(int i = 1 ; i <= n - 1 ; i++){
		int x;
		cin >> x;
		adj1[i].pb(x + 1);
		adj1[x + 1].pb(i);
	}
}

void solve()
{
	dfs(1 , 0);
	dfs1(1 , 0);
	ll ans = 0;
	for(int i = 2 ; i <= n ; i++){
		int cnt1 = 0 , cnt2 = 0;	
		ll val = 0;		
		for(int j = 2 ; j <= n ; j++){
			if(en[0][i] - st[0][i] + 1 <= n / 2){
				for(int k = st[0][i] ; k <= en[0][i] ; k++){
					if(st[1][j] <= st[1][tour[0][k]] && en[1][tour[0][k]] <= en[1][j]){
						cnt1++;
					}
					else cnt2++;
				}
			}
			else{
				for(int k = 1 ; k < st[0][i] ; k++){
					if(st[1][j] <= st[1][tour[0][k]] && en[1][tour[0][k]] <= en[1][j]){
						cnt1++;
					}
					else cnt2++;
				}
				for(int k = en[0][i] + 1 ; k < (int)tour[1].size() ; k++){
					if(st[1][j] <= st[1][tour[0][k]] && en[1][tour[0][k]] <= en[1][j]){
						cnt1++;
					}
					else cnt2++;
				}
			}
			int sz1 = en[1][j] - st[1][j] + 1;
			val = max(max(cnt1 , cnt2) , max(sz1 - cnt1 , (n - sz1) - cnt2));
			cout << i << ' ' << j << ' ' << val << '\n';
		}
		ans += val * val;
	}
	cout << ans;
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
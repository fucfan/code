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

int n , m , k , group[N] , cnt[N] , num_group , cnt_edge[N] , dp[N][3] , ans; 
vector <int> adj[N];
bool vst[N];

struct Edge{
    int u , v;
} edge[N];

void dfs(int i , int num){
	vst[i] = 1;
	group[i] = num;
    cnt[num]++;
	
	for(auto j : adj[i]){
		if(vst[j]) continue;
		dfs(j , num);
	}
}

void inp()
{
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int u , v;
		cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edge[i] = {u , v};
	}
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        if(!vst[i]) dfs(i , ++num_group);
    }

    for(int i = 1 ; i <= m ; i++){
        cnt_edge[group[edge[i].u]]++;
    }

    for(int i = 1 ; i <= num_group ; i++){
        // cout << cnt_edge[i] - cnt[i] + 1 << ' ';
        ans ^= (cnt_edge[i] - cnt[i] + 1) % (k + 1);
    } 

    cout << (ans != 0) << '\n';

    mem(cnt_edge , 0);
    mem(group , 0);
    mem(cnt , 0);
    mem(vst , 0);
    num_group = 0;
    ans = 0;
    for(int i = 1 ; i <= n ; i++) adj[i].clear();
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
    int test_case = 4;
    // cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
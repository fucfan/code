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
#define file "rsgraph"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , m , dis[N] , d[N] , num_dis[N] , num_edge[N];
bool vst[N];
vector <int> adj[N];
vector <pii> node;
ll ans , gt[N] , p_gt[N];
ll Pow(ll a , ll b){
	if(b == 0) return 1;
	b--;
	ll tmp = a;
	while(b){
		if(b & 1) (a *= tmp) %= mod;
		(tmp *= tmp) %= mod;
		b >>= 1;
	}
	return a;
}
void prepare(){
	gt[0] = 1;
	p_gt[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		gt[i] = (gt[i - 1] * i) % mod;
		p_gt[i] = Pow(gt[i] , mod - 2);
	}
}
ll nCk(int n , int k){
	return (gt[n] * ((p_gt[n - k] * p_gt[k]) % mod)) % mod;
}
void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i < n ; i++){
		cin >> d[i + 1];
		// d[i + 1] = rand() % 8 + 1;
		node.pb({d[i + 1] , i + 1});
	}
	for(int i = 1 ; i <= m ; i++){
		int a , b;
		cin >> a >> b;
		if(abs(d[a] - d[b]) > 1){
			cout << 0;
			exit(0);
		}
		if(d[a] == d[b]) num_edge[d[a]]++;
		adj[a].pb(b);	
		adj[b].pb(a);
	} 	
	mem(dis , -1);	
}

void solve()
{
	prepare();
	dis[1] = 0;
	num_dis[0]++;
	ans = 1;
	sort(all(node));
	int tmp = 0;
	// mem(tmp1 , 0);6
	for(auto j : node){
		if(j.fi != tmp){
			if(j.fi - tmp > 1){
				cout << 0;
				exit(0);
			}
			tmp = j.fi;
		}
		if(dis[j.se] == -1){
			int val = num_dis[tmp - 1];
			dis[j.se] = d[j.se];
			num_dis[d[j.se]]++;
			int check = 1;
			for(auto f : adj[j.se]){
				if(d[f] == d[j.se] - 1){
				    val--;
				    check = 0;
				}
			}
			(ans *= Pow(2 , val) - check) %= mod;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(num_dis[i])
			(ans *= Pow(2 , (1ll * num_dis[i] * (num_dis[i] - 1) / 2) - num_edge[i])) %= mod;
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
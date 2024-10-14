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
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

ll cost[50];
int n, l, r, k, a[N];
pair<ll, int> dp[30][N][2][2];

void prepare(){
	for(int i = 0; i <= 30; i++){
		for(int j = 1; j <= n; j++){
			if(BIT(a[j], i)) cost[i] += (1 << i); 
		}
	}
}

pair <ll, int> sol(int i, int m, bool check1, bool check2){
	if(i < 0){
		if(!m) return {0, 1};
		return {-loo, 1};
	}
	if(dp[i][m][check1][check2].se) return dp[i][m][check1][check2];

	ll res = -loo;
	int cnt = 0;
	for(int j = (check1 ? 0 : BIT(l, i)); j <= (check2 ? 1 : BIT(r, i)); j++){
		bool nxt_check1 = check1;
		bool nxt_check2 = check2;
		if(j > BIT(l, i)) nxt_check1 = 1;
		if(j < BIT(r, i)) nxt_check2 = 1;

		ll val = (j ? ((1ll << i) * n) - cost[i] : cost[i]);
		pair <ll, int> tmp = sol(i - 1, (m + (1ll << i) * j) % k, nxt_check1, nxt_check2);

		// cout << i << ' ' << j << ' ' << val << "gg\n";

		tmp.fi += val;

		if(tmp.fi == res){
			cnt += tmp.se;
		}
		else if(maxi(res, tmp.fi)){
			cnt = tmp.se;
		}
	}

	// cout << i << ' ' << m << ' ' << check1 << ' ' << check2 << ' ' << res << ' ' << cnt << '\n'; 

	return dp[i][m][check1][check2] = {res, cnt};
}

void sol1(){
	prepare();
	pair <ll, int> res = sol(29, 0, 0, 0);
	cout << res.fi << '\n' << res.se;
}

void sol2(){
	ll res = -1;
	int cnt = 0;
	for(int i = (l + (k - 1)) / k * k; i <= r; i += k){
		ll val = 0;
		for(int j = 1; j <= n; j++){
			val += (i ^ a[j]);
		}
		if(maxi(res, val)){
			cnt = 1;
		}
		else if(res == val) cnt++;
	}
	cout << res << '\n' << cnt; 
}

void inp(){
    cin >> n >> l >> r >> k;
    for(int i = 1; i <= n; i++){
    	// cin >> a[i]; 	
    	a[i] = rand() % 20;
    }
}

void solve(){
    if(k <= N) sol1();
    else sol2();
    // sol1();
    // sol2();
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
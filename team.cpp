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
const int mod = 918052004;
const int N = 2e5 + 5;
const int LOG = 20;

int n , m , le , ri , a[N] , pre_pos[N] , lazy[N] , pos[N];
ll dp[N];
pii tree[N];

void down(int id){
	tree[id << 1].fi += lazy[id];
	tree[id << 1].se += lazy[id];

	lazy[id << 1] += lazy[id];

	tree[id << 1 | 1].fi += lazy[id];
	tree[id << 1 | 1].se += lazy[id];

	lazy[id << 1 | 1] += lazy[id];	

	lazy[id] = 0;
}

void build(int id , int l , int r){
	if(l == r){
		tree[id] = {0 , 0};
		return;
	}
	int mid = (l + r) >> 1;
	down(id);
	build(id << 1 , l , mid);
	build(id << 1 | 1 , mid + 1 , r);
	tree[id].fi = max(tree[id << 1].fi , tree[id << 1 | 1].fi);
	tree[id].se = min(tree[id << 1].se , tree[id << 1 | 1].se);
}

void update(int id , int l , int r , int u , int v , int val){
	if(u > r || l > v) return;
	if(u <= l && r <= v){
		tree[id].fi += val;
		tree[id].se += val;
		lazy[id] += val;
		return;
	}
	down(id);
	int mid = (l + r) >> 1;
	update(id << 1 , l , mid , u , v , val);
	update(id << 1 | 1 , mid + 1 , r , u , v , val);
	tree[id].fi = max(tree[id << 1].fi , tree[id << 1 | 1].fi);
	tree[id].se = min(tree[id << 1].se , tree[id << 1 | 1].se);
}

int get_l(int id , int l , int r , int u , int v , int k){
	if(tree[id].se > k) return -1;
	if(u > r || l > v) return -1;
	if(l == r){
		return l;
	}	
	down(id);
	int mid = (l + r) >> 1;
	int res = get_l(id << 1 , l , mid , u , v , k);
	if(res == -1) return get_l(id << 1 | 1 , mid + 1 , r , u , v , k);
	return res;
}


int get_r(int id , int l , int r , int u , int v , int k){
		// cout << l << ' ' << r << ' ' << tree[id].fi << ' ' << k << "gg\n";
	if(tree[id].fi < k) return -1;
	if(u > r || l > v) return -1;
	if(l == r){
		return r;
	}	
	down(id);
	int mid = (l + r) >> 1;
	int res = get_r(id << 1 | 1 , mid + 1 , r , u , v , k);
	if(res == -1) return get_r(id << 1 , l , mid , u , v , k);
	return res;
}

void inp()
{
	cin >> n >> m >> le >> ri;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve()
{
	build(1 , 1 , n);
	mem(dp , 0);
	mem(pos , 0);
	dp[0] = 1;
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++){
		dp[i] += dp[i - 1];
		if(!pos[a[i]]){
			cnt++;
			update(1 , 1 , n , max(1 , pos[a[i]]) , i , 1);
			pos[a[i]] = i + 1;
			if(le <= le && cnt <= ri) dp[i]++;
			if(cnt > ri) break;
		}
	}
	for(int i = cnt + 1 ; i <= n ; i++){
		update(1 , 1 , n , max(1 , pos[a[i]]) , i , 1);
		pos[a[i]] = i + 1;
		int left = get_l(1 , 1 , n , 1 , i , ri);
		int right = get_r(1 , 1 , n , 1 , i , le);
		if(left < 2) (dp[i] += dp[right - 1]) %= mod;
		else (dp[i] += (dp[right - 1] - dp[left - 2] + mod) % mod) %= mod;
		// cout << left << ' ' << right << ' ' << i << ' ' << dp[i] << '\n';
		dp[i] += dp[i - 1];
	}
	cout << (dp[n] - dp[n - 1] + mod) % mod << '\n';
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
    cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
} 
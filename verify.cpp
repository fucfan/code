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

int n , q , tree[N] , lazy[N];
pii a[N] , b[N];
int pos[N] , ans[N];
set <int> qu;

void down(int id){
	if(!lazy[id]) return;

	tree[id << 1] = lazy[id];
	lazy[id << 1] = lazy[id];
	tree[id << 1 | 1] = lazy[id];
	lazy[id << 1 | 1] = lazy[id];

	lazy[id] = 0;
}

void update(int id , int l , int r , int u , int v , int val){
	if(u > r || l > v) return;

	if(u <= l && r <= v){
		tree[id] = val;
		lazy[id] = val;
		return;
	}

	int mid = (l + r) >> 1;

	down(id);

	update(id << 1 , l , mid , u , v , val);
	update(id << 1 | 1 , mid + 1 , r , u , v , val);

	tree[id] = min(tree[id << 1] , tree[id << 1 | 1]);
}

int get(int id , int l , int r , int u , int v){
	if(u > r || l > v) return oo;

	if(u <= l && r <= v) return tree[id];

	down(id);

	int mid = (l + r) >> 1;
	return min(get(id << 1 , l , mid , u , v) , get(id << 1 | 1 , mid + 1 , r , u , v));
}

void inp()
{
	cin >> n >> q;

	for(int i = 1 ; i <= q ; i++){
		int l , r , x;
		cin >> l >> r >> x;
		l++;
		r++;
		x++;
		if(!a[x].fi){
			a[x] = {l , r};
			b[x] = {l , r};
		}
		else{
			a[x].fi = max(a[x].fi , l);
			a[x].se = min(a[x].se , r);
			b[x].fi = min(b[x].fi , l);
			b[x].se = max(b[x].se , r);
		}

		if(a[x].fi && (b[x].se - b[x].fi > n - x)){
			// cout << a[x].fi << ' ' << a[x].se << ' ' << x << '\n';
			for(int k = 1 ; k <= n ; k++) cout << -1 << ' ';
			exit(0);
		}
	}
}

void solve()
{
	for(int i = 1 ; i <= n ; i++){
		if(!a[i].fi) continue;
		else{
			// cout << i << ' ' << a[i].fi << ' ' << a[i].se << '\n';
			update(1 , 1 , n , a[i].fi , a[i].se , i);
		}
	}

	for(int i = 1 ; i <= n ; i++){
		// cout << i << ' ' << get(1 , 1 , n , i , i) << '\n';
		pos[get(1 , 1 , n , i , i)] = i;
	}

	for(int i = 1 ; i <= n ; i++)
		ans[pos[i]] = i;

	for(int i = 1 ; i <= n ; i++){
		if(!pos[i] && a[i].fi){
			// cout << i << ' ' << pos[i] << '\n';
			for(int j = 1 ; j <= n ; j++) cout << -1 << ' ';
			exit(0);
		}
		if(!a[i].fi){
			qu.insert(i);
			// cout << i << '\n';
		}
	}

	for(int i = 1 ; i <= n ; i++){
		if(!ans[i]){
			int num = *upper_bound(all(qu) , get(1 , 1 , n , i , i));
			cout << num - 1 << ' ';
			qu.erase(num);
		}	
		else cout << ans[i] - 1 << ' ';
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
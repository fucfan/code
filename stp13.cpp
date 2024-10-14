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
#define file "stp13"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , m , a[N];
int tree[4 * N];
void build(int id , int l , int r){
	if(l == r){
		tree[id] = a[l];
		// cout << id << ' ' << l << ' ' << r << ' ' << tree[id].fi << '\n';
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1 , l , mid);
	build(id << 1 | 1 , mid + 1 , r);
	tree[id] = __gcd(tree[id << 1] , tree[id << 1 | 1]);
}
void update(int id , int l , int r , int pos , int val){
	if(pos > r || l > pos) return;
	if(l == r){
		tree[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1 , l , mid , pos , val);
	update(id << 1 | 1 , mid + 1 , r , pos , val);
	tree[id] = __gcd(tree[id << 1] , tree[id << 1 | 1]);
}
int get(int id , int l , int r , int u , int v){
	if(u > r || l > v) return 0;
	if(u <= l && r <= v){
		// cout << id << ' ' << l << ' ' << r << ' ' << tree[id].fi << ' ' << tree[id].se << '\n';
		return tree[id];
	}
	int mid = (l + r) >> 1;
	int x = get(id << 1 , l , mid , u , v);
	int y = get(id << 1 | 1 , mid + 1 , r , u , v);
	return __gcd(x , y);
}
void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	build(1 , 1 , n);
	// cout << tree[5].fi << ' ' << tree[5].se << "gg\n";
	for(int i = 1 ; i <= m ; i++){
		int type , l , r;
		cin >> type >> l >> r;
		if(type == 1) update(1 , 1 , n , l , r);
		else{
			cout << get(1 , 1 , n , l , r) << '\n';
		}
	}
}	

void solve()
{

}

void run_with_file()
{
    if (fopen(file".in", "r"))
    {
        freopen(file".in", "r", stdin);
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
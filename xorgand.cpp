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
#define file "xorgand"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , q , a[N];
ll tree[N][64];
void merge(int id){
	for(int i = 0 ; i < 63 ; i++){
		tree[id][i] = tree[id << 1][i] + tree[id << 1 | 1][i];
		// if(i) tree[id][i] += tree[id][i - 1];
	}
}
void build(int id , int l , int r){
	if(l == r){
		tree[id][63 - __builtin_clzll(a[l])]++;	
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1 , l , mid);
	build(id << 1 | 1 , mid + 1 , r);
	merge(id);
}
int get(int id , int l , int r , int u , int v , int num_bit){
	if(u > r || l > v) return 0;
	if(u <= l && r <= v) return tree[id][num_bit];
	int mid = (l + r) >> 1;
	return get(id << 1 , l , mid , u , v,  num_bit) + get(id << 1 | 1 , mid + 1 , r , u , v , num_bit);
}
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	build(1 , 1 , n);
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int l , r;
		ll x;	
		cin >> l >> r >> x;
		cout << (r - l + 1) - get(1 , 1 , n , l , r , 63 - __builtin_clzll(x)) << '\n';
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
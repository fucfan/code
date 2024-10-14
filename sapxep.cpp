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
#define file "sapxep"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , a[N] , lazy[N] , pos[N];
pii tree[N] , tree1[N];

void down(int id){
	tree[id << 1].se += lazy[id];
	lazy[id << 1] += lazy[id]; 

	tree[id << 1 | 1].se += lazy[id]; 
	lazy[id << 1 | 1] += lazy[id]; 

	tree1[id << 1].se += lazy[id];
	tree1[id << 1 | 1].se += lazy[id]; 

	lazy[id] = 0;
}

void merge(int id){
	tree[id] = min(tree[id << 1] , tree[id << 1 | 1]);
	tree1[id] = max(tree1[id << 1] , tree1[id << 1 | 1]);

	if(tree[id << 1].fi == -1) tree[id] = tree[id << 1 | 1];
	if(tree[id << 1 | 1].fi == -1) tree[id] = tree[id << 1];

	if(tree1[id << 1].fi == -1) tree1[id] = tree1[id << 1 | 1];
	if(tree1[id << 1 | 1].fi == -1) tree1[id] = tree1[id << 1];
}

void build(int id , int l , int r){
	if(l == r){
		tree[id] = {a[l] , l};
		tree1[id] = {a[l] , r};

		return;
	}
	int mid = (l + r) >> 1;

	build(id << 1 , l , mid);
	build(id << 1 | 1 , mid + 1 , r);

	tree[id] = min(tree[id << 1] , tree[id << 1 | 1]);
	tree1[id] = max(tree1[id << 1] , tree1[id << 1 | 1]);
}

void update(int id , int l , int r , int u , int v , int val){
	if(u > r || l > v) return;
	if(u <= l && r <= v){
		tree[id].se += val;
		tree1[id].se += val;
		lazy[id] += val;

		return;
	}
	int mid = (l + r) >> 1;

	down(id);

	update(id << 1 , l , mid , u , v , val);
	update(id << 1 | 1 , mid + 1 , r , u , v, val);

	merge(id);
}

void update1(int id , int l , int r , int pos , int val){
	if(pos > r || l > pos) return;
	if(l == r){
		tree[id].fi = val;
		tree1[id].fi = val;

		return;
	}
	int mid = (l + r) >> 1;

	down(id);

	update1(id << 1 , l , mid , pos , val);
	update1(id << 1 | 1 , mid + 1 , r , pos , val);

	merge(id);
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
}

void solve()
{
	build(1 , 1 , n);
	for(int i = 1 ; i <= n ; i++){
		pii tmp;
		if(i & 1){
			tmp = tree[1];
			update(1 , 1 , n , 1 , pos[tmp.fi] , 1);
		}
		else{
			tmp = tree1[1];
			update(1 ,1 , n , pos[tmp.fi] , n , -1);
		}

		for(int i = 1 ; i <= n ; i++){

		}

		cout << abs(tmp.fi - tmp.se) << '\n';

		update1(1 , 1 , n , pos[tmp.fi] , -1);
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
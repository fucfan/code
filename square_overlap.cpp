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
#define file "squares"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e6 + 10;
const int LOG = 20;
const int root = 1e6 + 5e5 + 2;
int n , k;
int tree[4 * N] , tree1[4 * N];
vector <pair <pii , pii>> event;
void down(int id){
	tree[id << 1] += tree1[id];
	tree[id << 1 | 1] += tree1[id];
	tree1[id << 1] += tree1[id];
	tree1[id << 1 | 1] += tree1[id];
	tree1[id] = 0;
}
void update1(int id , int l , int r , int u , int v , int val){
	if(u > r || v < l) return;
	if(u <= l && r <= v){
		tree1[id] += val;
		tree[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	down(id);
	update1(id << 1 , l , mid , u , v , val);
	update1(id << 1 | 1 , mid + 1 , r , u , v , val);
	tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
}
void update(int id , int l , int r , int u , int v , int val){
	if(u > r || v < l) return;
	if(u <= l && r <= v){
		tree1[id] += val;
		if(tree1[id]) tree[id] = (r - l + 1);
		else if(l != r) tree[id] = tree[id << 1] + tree[id << 1 | 1];
		else tree[id] = 0;
		// if(tree1[id]) tree[id] = 1;
		// else tree[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1 , l , mid , u , v , val);
	update(id << 1 | 1 , mid + 1 , r , u , v , val);
	if(tree1[id]) tree[id] = (r - l + 1);
	else tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
void inp()
{
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		int x , y;
		cin >> x >> y;
		int x1 = root + x - k / 2;
		int x2 = root + x + k / 2;
		int y1 = root + y - k / 2;
		int y2 = root + y + k / 2;
		event.pb({{x1 , 1} , {y1 , y2}});
		event.pb({{x2 , -1} , {y1 , y2}});
	}
}

void solve()
{
	ll val = 0;
	sort(all(event));
	int last = 0;
	for(auto j : event){
		update1(1 , 1 , root + root , j.se.fi , j.se.se , j.fi.se);
		if(tree[1] > 2){
			cout << -1;
			exit(0);
		}
	}
	mem(tree1 , 0);
	mem(tree , 0);
	for(auto j : event){
		// cout << j.fi.fi << ' ' << j.fi.se << ' ' << j.se.fi << ' ' << j.se.se << ' ' << tree[1] << '\n';
		val += 1ll * tree[1] * (j.fi.fi - last);
		// cout << val << ' ' << last << '\n';
		update(1 , 1 , root + root , j.se.fi , j.se.se - 1 , j.fi.se);
		// cout << tree[1] << ' ' << j.fi.se * (j.se.se - j.se.fi) << '\n';
		last = j.fi.fi;
	}
	cout << 1ll * k * k * n - val;
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
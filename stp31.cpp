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
#define file "stp31"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , tree[4 * N];
int a[N];
void update(int id , int l , int r , int pos){
	if(pos > r || pos < l) return;
	if(l == r){
		// cout << l << ' ' << r << ' ' << tree[id] << "hh\n";
		tree[id]++;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1 , l , mid , pos);
	update(id << 1 | 1 , mid + 1 , r , pos);
	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
int get(int id , int l , int r , int u , int v){
	if(u > r || l > v) return 0;
	if(u <= l && r <= v){
		// cout << l << ' ' << r << ' ' << tree[id] << "gg\n";
		return tree[id];
	}
	int mid = (l + r) >> 1;
	return get(id << 1 , l , mid , u , v) + get(id << 1 | 1 , mid + 1 , r , u , v);
}
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
}

void solve()
{
	for(int i = 1 ; i <= n ; i++){
		// cout << a[i].fi << ' ' << a[i].se << '\n';
		cout << get(1 , 1 , n , a[i] , n) << ' ';
		update(1 , 1 , n , a[i]);
	}
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
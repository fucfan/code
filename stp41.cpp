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
#define file "stp41"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , m;
ll tree[4 * N];
void down(int id){
	tree[id << 1] += tree[id]; 
	tree[id << 1 | 1] += tree[id];
	tree[id] = 0;
}
void update(int id , int l , int r , int u , int v , int val){
	if(u > r || l > v) return;
	if(u <= l && r <= v){
		tree[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	down(id);
	update(id << 1 , l , mid , u , v , val);
	update(id << 1 | 1 , mid + 1 , r , u , v , val);
	// tree[id] = tree[id << 1] 
}
ll get(int id , int l , int r , int pos){
	if(l == r) return tree[id];
	int mid = (l + r) >> 1;
	down(id);
	if(pos <= mid) return get(id << 1 , l , mid , pos);
	return get(id << 1 | 1 , mid + 1 , r , pos);
}
void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int type;
		cin >> type;
		if(type == 1){
			int l , r , val;
			cin >> l >> r >> val;
			update(1 , 1 , n , l , r , val);
		}
		else{
			int pos;
			cin >> pos;
			cout << get(1 , 1 , n , pos) << '\n';
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
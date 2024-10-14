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
int n , a[N] , num_block , block[N] , q , tree[N];
ll res = 0;
vector <int> num[N];

void update(int pos , int val){
	// cout << res << ' ';
	for(int i = 1 ; i < block[pos] ; i++){
		int sz = num[i].size();
		int tmp = upper_bound(all(num[i]) , a[pos]) - num[i].begin();
		// for(auto j : num[i]) cout << j << ' ';
		// 	cout << "gg\n";
		// 	nl;
		// cout << tmp << '\n';
		res -= sz - tmp;
	}

	for(int i = block[pos] + 1 ; i <= num_block ; i++){
		int tmp = lower_bound(all(num[i]) , a[pos]) - num[i].begin();
		// for(auto j : num[i]) cout << j << ' ';
		// 	nl;
		// cout << tmp << '\n';
		res -= tmp;
	}

	for(int i = pos - 1 ; block[i] == block[pos] ; i--){
		// cout << i << ' ' << a[i] << ' ' << a[pos] << ' ' << res << '\n'; 
		if(a[i] > a[pos]) res--;
	}
	for(int i = pos + 1 ; block[i] == block[pos] ; i++){
		if(a[i] < a[pos]) res--;
	}

	// cout << res << ' ';

	int chg_pos = lower_bound(all(num[block[pos]]) , a[pos]) - num[block[pos]].begin();
	num[block[pos]][chg_pos] = val;

	while(num[block[pos]][chg_pos] > num[block[pos]][chg_pos + 1]){
		if(chg_pos >= (int)num[block[pos]].size() - 1) break;
		swap(num[block[pos]][chg_pos] , num[block[pos]][chg_pos + 1]);
		chg_pos++;
	}
	while(num[block[pos]][chg_pos] < num[block[pos]][chg_pos - 1]){
		if(chg_pos < 1) break;
		swap(num[block[pos]][chg_pos] , num[block[pos]][chg_pos - 1]);
		chg_pos--;
	}

		// for(auto j : num[block[pos]]) cout << j << ' ';
		// 	cout << "gg\n";
		// 	nl;

	a[pos] = val;


	for(int i = pos ; block[i] == block[pos] ; i--){
		if(a[i] > a[pos]) res++;
	}
	for(int i = pos ; block[i] == block[pos] ; i++){
		if(a[i] < a[pos]) res++;
	}

	for(int i = 1 ; i < block[pos] ; i++){
		int sz = num[i].size();
		int tmp = upper_bound(all(num[i]) , a[pos]) - num[i].begin();
		res += sz - tmp;
	}
	// cout << res << '\n';
	for(int i = block[pos] + 1 ; i <= num_block ; i++){
		int tmp = lower_bound(all(num[i]) , a[pos]) - num[i].begin();
		// for(auto j : num[i]) cout << j << ' ';
		// 	nl;
		// cout << tmp << '\n';
		res += tmp;
	}
	// cout << res << '\n';
}

void prepare(){
	for(int i = 1 ; i <= n ; i += sqrt(n)){
		num_block++;
		for(int j = i ; j <= min(n , i + (int)sqrt(n) - 1) ; j++){
			block[j] = num_block;
			num[num_block].pb(a[j]);
		}
		sort(all(num[num_block]));
	}
}

void update0(int id , int l , int r , int pos){
	if(pos > r || pos < l) return;
	if(l == r){
		tree[id]++;
		return;
	}
	int mid = (l + r) >> 1;
	update0(id << 1 , l , mid , pos);
	update0(id << 1 | 1 , mid + 1 , r , pos);
	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int get(int id , int l , int r , int u , int v){
	if(l > v || u > r) return 0;
	if(u <= l && r <= v) return tree[id];
	int mid = (l + r) >> 1;
	return get(id << 1 , l , mid , u , v) + get(id << 1 | 1 , mid + 1 , r , u , v);
}

void inp()
{
	cin >> n;
	// update(1 , 2);
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		// cout << res << '\n';
	}
	for(int i = n ; i >= 1 ; i--){
		res += get(1 , 1 , 5e4 + 2 , 1 , a[i] - 1);
		update0(1 , 1 , 5e4 + 2 , a[i]);
	}
	prepare();
	// cout << res << '\n';
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int x , y;
		cin >> x >> y;
		// for(int j = 1 ; j <= num_block ; j++){
		// 	for(auto k : num[j]) cout << k << ' ';
		// 	nl;
		// }
		update(x , y);
		cout << res << '\n';
	}
	// for(int j = 1 ; j <= num_block ; j++){
	// 	for(auto k : num[j]) cout << k << ' ';
	// 	nl;
	// }
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
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

int n , q , a[N] , num_block , block[N];
ll val_block[N];	
vector <int> val[N];

void prepare(){
	for(int i = 1 ; i <= n ; i += sqrt(n)){
		num_block++;
		for(int j = i ; j <= min(n , i + (int)sqrt(n) - 1) ; j++){
			val[num_block].pb(a[j]);
			block[j] = num_block;
			val_block[num_block] += a[j];
		}
		val[num_block].pb(oo);
		sort(all(val[num_block]));
	}
}

void update(int pos , int value){
	int change = lower_bound(all(val[block[pos]]) , a[pos]) - val[block[pos]].begin();
	val[block[pos]][change] = value;

	while(val[block[pos]][change] < val[block[pos]][change + 1]) 
		swap(val[block[pos]][change] , val[block[pos]][change + 1]) , change++;

	val_block[block[pos]] -= 1ll * a[pos] - value;
	a[pos] = value;
}

ll get(int l , int r){
	int i = l , j = r;
	ll res = 0;
	while(block[i] == block[l] && i <= j){
		res += a[i];
		i++;
	}
	while(block[j] == block[r] && i <= j){
		res += a[j];
		j--;
	}
	for(int k = block[l] + 1 ; k <= block[r] - 1 ; k++) res += val_block[k];
		return res;
}

void inp()
{
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	prepare();
	for(int i = 1 ; i <= q ; i++){
		int type , x , y;
		cin >> type >> x >> y;
		if(type == 1){
			update(x , y);
		}
		else cout << get(x , y) << '\n';
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
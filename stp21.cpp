#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "stp21"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , m , a[N];
pair <pii , pii> tree[4 * N];
void change(int id){
    ll x = tree[id << 1].fi.fi;
    ll y = tree[id << 1 | 1].fi.fi;
    ll z = tree[id << 1].se.se + tree[id << 1 | 1].se.fi;
    tree[id].fi.fi = max(max(x , y) , z);
    tree[id].fi.se = tree[id << 1].fi.se + tree[id << 1 | 1].fi.se;
    tree[id].se.fi = max(tree[id << 1].se.fi , tree[id << 1 | 1].se.fi + tree[id << 1].fi.se);
    tree[id].se.se = max(tree[id << 1 | 1].se.se , tree[id << 1].se.se + tree[id << 1 | 1].fi.se);
}
void build(int id , int l , int r){
	if(l == r){
		tree[id] = {{a[l] , a[l]} , {a[l] , a[l]}};
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1 , l , mid);
	build(id << 1 | 1 , mid + 1 , r);
    change(id);
}
void update(int id , int l , int r , int pos , int val){
    if(pos > r || pos < l) return;
    if(l == r){
        tree[id] = {{val , val} , {val , val}};
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , pos , val);
    update(id << 1 | 1 , mid + 1 , r , pos , val);
    change(id);
}
void inp()  
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
    build(1 , 1 , n);
    cout << max(0ll , tree[1].fi.fi) << '\n';
    for(int i = 1 ; i <= m ; i++){
        int pos , val;
        cin >> pos >> val;
        update(1 , 1 , n , pos , val);
        cout << max(0ll , tree[1].fi.fi) << '\n';
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
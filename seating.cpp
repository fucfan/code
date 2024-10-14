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
#define file "phuc"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , k , chair[N];
pii child[N];
vector <int> event;
pair <int , pii> tree[N];
map <int , priority_queue<pii , vector<pii> , greater<pii>>> length;
map <int , int> cnt;

void merge(int id){
	tree[id].fi = max({tree[id << 1].fi , tree[id << 1 | 1].fi , tree[id << 1].se.se + tree[id << 1 | 1].se.fi});
	tree[id].se.fi = tree[id << 1].se.fi;
	tree[id].se.se = tree[id << 1 | 1].se.se;
}

void update(int id , int l , int r , int pos){
	if(l > pos || pos > r) return;
	if(l == r){
		tree[id] = {1 , {1 , 1}};
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1 , l , mid);	
	update(id << 1 | 1 , mid + 1 , r);
	merge(id);
}

void inp()
{
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> child[i].fi >> child[i].se;
		event.pb(child[i].fi , 1);
		event.pb(child[i].se , -1);
	}
}

void solve()
{
	set <int> s , s1;
	set<int> s;
	s.insert(k);
	length[k].pb(1 , n);
	for(auto j : event){
		if(j.se == 1){
			int l = 1 , r = k;
			int Max = 1;
			while(l <= k){
				int mid = (l + r) >> 1;
				if(upper_bound(all(s) , mid) != s.end()){
					l = mid + 1;
					Max = mid;
				}
				else r = mid - 1;
			}
			pii tmp = length[Max].top();
			cnt[Max]--;
			if(!cnt[Max]) s.erase(Max);
			length[Max].pop();
			length[(Max + 1) / 2 - 1].push(tmp.fi , (tmp.se + 1) / 2 - 1);
			length[Max - (Max + 1) / 2].push((tmp.se + 1) / 2 + 1 , tmp.se);
		}
		else{
			
		}
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
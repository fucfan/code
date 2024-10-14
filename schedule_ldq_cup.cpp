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

struct Work{
	ll k , s , t;
	friend bool operator<(Work a , Work b){
		// Work a = *this;
		if(a.s == b.s){
			return a.t < b.t;
		}
		return a.s < b.s;
	}
	// bool operator>(Work b){
	// 	Work a = *this;
	// 	if(a.s == b.s){
	// 		return a.t > b.t;
	// 	}
	// 	return a.s > b.s;
	// }
} work[N];

struct cmp{
	bool operator()(Work a , Work b){
		if(a.s == b.s){
			return a.t > b.t;
		}
		return a.s > b.s;
	}
};

int n;
ll m , st = oo;
vector <ll> compress;

void inp()
{
	cin >> n >> m;

	for(int i = 1 ; i <= n ; i++){
		cin >> work[i].k >> work[i].s >> work[i].t;
		compress.pb(work[i].s);
	}

	compress.pb(m);
	compress.pb(m + 1);
	sort(all(compress));
	compress.erase(unique(all(compress)) , compress.end());

	ll l = 1 , r = 1e18 , ans = 0;

	while(l <= r){
		ll mid = (l + r) >> 1;
		ll i = 0;
		bool check = 1;

		priority_queue <Work , vector <Work> , cmp> q;

		for(int i = 1 ; i <= n ; i++) q.push(work[i]);

		cout << mid << '\n';

		while(q.size() && check){
			Work tmp = q.top();
			int pos = lower_bound(all(compress) , tmp.s) - compress.begin() + 1;
			ll left = mid * (compress[pos] - tmp.s);
			i = max(i , tmp.s);
			while (q.size() && left >= tmp.k && tmp.s == i){
			cout << left << ' ' << tmp.k << ' ' << tmp.s << ' ' << tmp.t << ' ' << q.size() << '\n';
				left -= tmp.k;
				q.pop();
				if(q.empty()) break;
				tmp = q.top();
			}
			if(q.empty()) break;
			if(left < tmp.k && tmp.s == i){
				tmp.k -= left;
				tmp.s = compress[pos];
				if(tmp.s > tmp.t) check = 0;
				q.pop();
				q.push(tmp);
			}	
			i = compress[pos];
			if(i > m) break;
			if(q.empty()) break;
			tmp = q.top();
			q.pop();
			while(tmp.s < i){
				tmp.s = i;
				if(tmp.s > tmp.t) check = 0;
				q.push(tmp);
				tmp = q.top();
				q.pop();
			}
			q.push(tmp);
		}
		nl;
		// cout << q.size() << '\n';
		if(check && i <= m){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
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
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

int n , a[N] , ans = oo;
pii book[N];

void out(){
	int length[3] = {0 , 0 , 0};
	int high[3] = {0 , 0 , 0};

	for(int i = 1 ; i <= n ; i++){
		length[a[i]] += book[i].se;
		high[a[i]] = max(high[a[i]] , book[i].fi);
	}

	ans = min(ans , max({length[1] , length[2] , length[0]}) * (high[0] + high[1] + high[2]));
}

void btr(int i){
	for(int j = 0 ; j <= 2 ; j++){
		a[i] = j;
		if(i == n) out();
		else btr(i + 1);
	}
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> book[i].fi >> book[i].se;
	}
}

void solve()
{
	btr(1);
	cout << ans;
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
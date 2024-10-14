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

int n , m , inc , num_set;
string s;
map <ll , int> bin;
int ans;

void btr(int i , int cnt , ll t , int type){
	if(i > n){
		if(cnt) return;
		bin[t]++;
		// cout << t << '\n';
		if(type == m && bin[t] == m) ans++;
		return;
	}
	if(cnt) btr(i + 1 , cnt - 1 , t + (1 - (s[i] - '0')) * (1ll << (i - 1)) , type);
	btr(i + 1 , cnt , t + (s[i] - '0') * (1ll << (i - 1)) , type);
}

void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		cin >> s >> inc;
		s = " " + s;
		num_set++;
		btr(1 , inc , 0 , i);
	}
}

void solve()
{
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
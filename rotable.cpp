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
template<class T1, class T2> void Maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e2 + 5;
const int LOG = 20;

int n , m , a[N][N], val[N][N];
pii dp[N][N];
bool vst[N][N];

void prepare(){
	for(int pre = 0; pre < m; pre++){
		for(int i = 2; i <= n; i++){
			for(int j = 0; j < m; j++){
				val[i][pre] += abs(a[i][j] - a[i - 1][(j + pre) % m]);
			}
		}
	}
}

pii cal(int i, int pre){
	if(i > n){
		return {0, 0};
	}
	
	if(vst[i][pre]) return dp[i][pre];

	pii res = {oo, oo};

	for(int j = 0; j < m; j++){
		pii tmp = cal(i + 1, j);
		tmp.fi += val[i][(pre - j + m) % m];
		tmp.se += min(j, m - j);
		res = min(res, tmp);
	}

	vst[i][pre] = 1;
	return dp[i][pre] = res;
}

void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j];
		}
	}
}

void solve(){
	prepare();
	pii ans = {oo, oo};
	for(int i = 0; i < m; i++){
		pii tmp = cal(2, i);
		tmp.se += min(i, m - i);
		ans = min(ans, tmp);
	}
	cout << ans.fi << ' ' << ans.se;
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
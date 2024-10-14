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
#define file "sum"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , k;
ll gt[N];
ll POW(ll a , ll b){
	b--;
	ll ans = a;
	while(b){
		if(b & 1) (ans *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ans;
}
void prepare(){
	gt[0] = 1;
	for(int i = 1 ; i <= N - 1 ; i++){
		gt[i] = (gt[i - 1] * i) % mod;
	}
}
int nCk(int n , int k){
	return (gt[n] * POW((gt[k] * gt[n - k]) % mod , mod - 2)) % mod;
}
void inp()
{
	cin >> n >> k;
	if(n > k){
		cout << 0 << '\n';
		return;
	}
	cout << nCk(k - 1 , n - 1) << '\n';
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
    prepare();
    int test_case = 1;
    cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
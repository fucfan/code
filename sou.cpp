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
#define file "sou"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e7 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n;
ll ans1 = 1 , ans2 = 1 , val[N] , cnt[N];
bool not_prime[N];
vector<ll> prime;

int get_exp(ll p , int n){
	ll pw = p;
	int res = 0;
	while(pw <= n){
		res += n / pw; 
		pw *= p;
	}
	return res;
}

void sieve(){
	for(int i = 2 ; 1ll * i * i < N ; i++){
		if(not_prime[i]) continue;
		for(int j = i * i ; j < N ; j += i){
			not_prime[j] = 1;
		}
	}
	for(int i = 2 ; i < N ; i++){
		if(!not_prime[i]) prime.pb(i);
	}
	for(int i = 0 ; i < prime.size() ; i++){
		cnt[i] = get_exp(prime[i] , n);
		ll tmp = 1;
		for(int j = 0 ; j <= cnt[i] ; j++){
			(val[i] += tmp) %= mod;
			(tmp *= prime[i]) %= mod;
		}
	}
}

void inp()
{
	cin >> n;
	sieve();
	for(int i = 0 ; i < prime.size() ; i++){
		// cout << prime[i] << ' ' << cnt[i] << ' ' << val[i] << '\n';
		(ans1 *= val[i]) %= mod;
		(ans2 *= (cnt[i] + 1)) %= mod;
		if(!cnt[i]) break;
	}
	cout << ans2 << '\n' << ans1;
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
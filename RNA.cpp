#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "rna"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

string s[N];
int n, m, sz[N];
pair <string, string> query[N];

int decode(char x){
	if(x == 'A') return 1;
	if(x == 'G') return 2;
	if(x == 'U') return 3;
	if(x == 'C') return 4;
	return -1;
}

namespace sub2{
	bool check(){
		return (n <= 5000 && m <= 5000);
	}

	int pw[N];
	vector <int> hashS[N];

	int get_hash(int i, int l, int r){
		// cout << i << ' ' << l << ' ' << r << ' ' << (hashS[i][r] - (1ll * hashS[i][l - 1] * pw[r - l + 1] % mod) + mod) % mod << "gg\n";
		return (hashS[i][r] - (1ll * hashS[i][l - 1] * pw[r - l + 1] % mod) + mod) % mod;
	}

	void prepare(){
		int mx = 0;
		for(int i = 1; i <= n; i++){
			sz[i] = s[i].size();
			s[i] = " " + s[i];
			mx = max(mx, sz[i]);
			hashS[i] = vector<int>(sz[i] + 5, 0);
			for(int j = 1; j <= sz[i]; j++){
				hashS[i][j] = (1ll * hashS[i][j - 1] * base + (s[i][j] - 'A' + 1)) % mod; 
			}
		}

		pw[0] = 1;

		for(int i = 1; i <= mx + 5; i++){
			pw[i] = 1ll * pw[i - 1] * base % mod;
		}
	}

	void solve(){
		prepare();
		for(int i = 1; i <= m; i++){
			int cnt = 0;

			string p = " " + query[i].fi;
			string q = " " + query[i].se;
			int hash_p = 0;
			int hash_q = 0;
			int sz_p = query[i].fi.size();
			int sz_q = query[i].se.size();

			for(int j = 1; j <= sz_p; j++)
				hash_p = (1ll * hash_p * base + (p[j] - 'A' + 1)) % mod;
			for(int j = 1; j <= sz_q; j++)
				hash_q = (1ll * hash_q * base + (q[j] - 'A' + 1)) % mod;

			// cout << hash_p << ' ' << hash_q << '\n';

			for(int j = 1; j <= n; j++){
				if(sz[j] < sz_p || sz[j] < sz_q) continue;
				int st1 = 1;
				int st2 = sz[j] - sz_q + 1;
				if(get_hash(j, st1, sz_p) == hash_p && get_hash(j, st2, sz[j]) == hash_q){
					cnt++;
				}
			}

			cout << cnt << '\n';
		}
	}
}

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= m; i++){
    	cin >> query[i].fi >> query[i].se;
    }
}

void solve(){
    if(sub2::check()) return sub2::solve();
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
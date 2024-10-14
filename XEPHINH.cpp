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
#define file "test"
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

int n, cnt[N];
bool not_prime[N];
vector <int> prime;

bool check(vector<int> vt){
	for(int i = 0; i < (int)vt.size(); i++){
		if(i + 1 != vt[i]) return 0;
	}
	return 1;
}

vector <int> doo(vector <int> vt, vector <int> vt1){
	vector <int> res = vt;
	for(int i = 0; i < (int)vt.size(); i++){
		res[vt[i] - 1] = vt1[i];
	}
	return res;
}

void sieve(){
	for(int i = 2; i * i < N; i++){
		if(not_prime[i]) continue;
		for(int j = i * i; j < N; j += i){
			not_prime[j] = 1;
		}
	}

	for(int i = 2; i < N; i++){
		if(!not_prime[i]) prime.pb(i);
	}
}

void get_exp(int num){
	for(auto j : prime){
		if(num % j == 0){
			while(num % j == 0){
				num /= j; 
				cnt[j]++;
			}
		}
		if(j > num) return;
	}
}

void inp(){
    cin >> n;
}

void solve(){
	sieve();
	ll res = 1;
    vector <int> vt, vt1;
    for(int i = 1; i <= n; i++) vt.pb(i), vt1.pb(i);

   	do{
   		int cnt = 1;
   		vt1 = doo(vt, vt1);
   		while(!check(vt1)){
   			vt1 = doo(vt, vt1);
   			cnt++;
   		}
   		get_exp(cnt);
   		// cout << cnt << ' ' << res << '\n';
   		res = res * cnt % mod;
   	}	
   	while(next_permutation(all(vt)));

   	for(auto j : prime){
   		cout << j << ' ' << cnt[j] << '\n';
   	}
   	cout << res;
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
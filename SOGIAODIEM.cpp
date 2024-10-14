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
#define file "sogiaodiem"
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

int n;
string s;
vector <int> vt;

void inp(){
    cin >> n >> s;
}

void solve(){
	int res = 0;

	for(int i = 1; i <= 2 * n; i++) vt.pb(i);

	do{
		bool ok = 1;
		for(int i = 0; i < 2 * n; i += 2){
			if(s[vt[i]] == s[vt[i + 1]]) ok = 0;
		}
		if(!ok) continue;

		int cnt = 0;
		for(int i = 0; i < 2 * n; i += 2){
			for(int j = i + 2; j < 2 * n; j += 2){
				int l1 = vt[i];
				int l2 = vt[j];
				int r1 = vt[i + 1];
				int r2 = vt[j + 1];

				if(l1 > r1) swap(l1, r1);
				if(l2 > r2) swap(l2, r2);

				if((l1 <= l2 && l2 <= r1 && r2 > r1) || 
				   (l1 <= r2 && r2 <= r1 && l2 < l1)) cnt++;
			}
		}
		res = max(res, cnt);
	}
	while(next_permutation(all(vt)));

	cout << res;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    // cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
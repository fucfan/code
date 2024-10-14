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
#define file "sonnha"
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
vector<int> pos[N];
map<string, pair<bool, int>> vst[101];

char paint(char x, int step){
	if(step == 1){
		if(x == 'T') return 'X';
		if(x == 'X') return 'V';
		if(x == 'V') return 'T';
	}
	if(step == 2){
		if(x == 'T') return 'V';
		if(x == 'X') return 'T';
		if(x == 'V') return 'X';
	}

	return x;
}

int sol(int i, string t){
	if(i > n){
		for(int j = 1; j <= n; j++){
			if(t[j] != 'T') return oo;
		}
		return 0;
	}
	// cout << i << ' ' << t << '\n';
	if(vst[i][t].fi) return vst[i][t].se;
	int res = oo;
	string tmp = t;
	res = min(res, sol(i + 1, t));
	for(int step = 1; step <= 2; step++){
		// cout << tmp << ' ' << i << '\n';
		for(auto j : pos[i]){
			// cout << tmp[j] << '\n';
			tmp[j] = paint(tmp[j], 1);
		}
		// cout << tmp << ' ' << i << '\n';
		res = min(res, sol(i + 1, tmp) + step);
	}
	vst[i][t].fi = 1;
	return vst[i][t].se = res;
}

void inp(){
    cin >> n >> s;
    s = ' ' + s;
	cin.ignore();
   	for(int i = 1; i <= n; i++){
   		string tmp;
   		getline(cin, tmp);
   		for(int j = 0; j < (int)tmp.size(); j++){
   			if(tmp[j] != ' '){
   				if(j){
   					if(tmp[j - 1] == ' ') pos[i].pb(tmp[j] - '0');
   					else pos[i].back() = pos[i].back() * 10 + (tmp[j] - '0');
   				}
   				else{
   					pos[i].pb(tmp[j] - '0');
   				}
   			}
   		}
   	}	
}

void solve(){
    cout << sol(1, s);
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
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
#define file "str2n"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int LOG = 20;
struct Trie{
	struct nodes{
		int child[27];
		int cnt , exist , num;
	} node[N];
	int cur;
	Trie() : cur(0){
		mem(node[0].child , 0);
		node[0].cnt = node[0].exist = 0;
	}
	int new_node(){
		cur++;
		mem(node[cur].child , 0);
		node[cur].cnt = node[cur].exist = 0;
		return cur;
	}
	void add_string(string s , int n){
		int pos = 0;
		for(auto f : s){
			int c = f - 'a';
			if(!node[pos].child[c]) node[pos].child[c] = new_node();
			pos = node[pos].child[c];
			node[pos].cnt++;
		}
		node[pos].exist++;
		node[pos].num = n;
	}
	bool delete_string(int pos , string s , int i){
		// cout << pos << ' ' << s << ' ' << i << '\n';
		if(i != int(s.size())){
			int c = s[i] - 'a';
			if(delete_string(node[pos].child[c] , s , i + 1))
				node[pos].child[c] = 0;
		}
		else node[pos].exist--;
		if(pos){
			node[pos].cnt--;
			if(!node[pos].cnt) return true;
		}
		return false;
	}
	pair <string , int> find_string(string s){
		int pos = 0;
		string t = "";
		for(auto f : s){
			int c = f - 'a';
			if(!node[pos].child[c]) return {"-1" , -1};
			pos = node[pos].child[c];
			t += f;
		}
		if(node[pos].exist) return {t , node[pos].num};
		while(1){
			for(int i = 0 ; i < 26 ; i++){
				if(node[pos].child[i] != 0){
					t += char(i + 'a');
					pos = node[pos].child[i];
					break;
				}
			}		
		// cout << s << ' '<< node[pos].exist << ' ' << t << '\n';
			if(node[pos].exist) return {t , node[pos].num};
		}
	}
} trie;
int n;
pair <string , int> s[N];
bool cmp(pair <string , int> s1 , pair<string , int> s2){
	return s1.fi.size() > s2.fi.size();
}
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= 2 * n ; i++){
		cin >> s[i].fi;
		s[i].se = i;
	}
	sort(s + 1 , s + 1 + 2 * n , cmp);
}

void solve()
{
	for(int i = 1 ; i <= 2 * n ; i++){
		pair <string , int> par = trie.find_string(s[i].fi);
		// cout << s[i].fi << ' ' << par.fi << '\n';
		if(par.fi == "-1") trie.add_string(s[i].fi , s[i].se);
		else{
			trie.delete_string(0 , par.fi , 0);
			cout << par.se << ' ' << s[i].se << '\n';
		}
	}
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
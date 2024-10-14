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
#define file "xor"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
struct Trie{
	struct Nodes{
		int exist , cnt;
		int child[3];
	} node[N];
	int cur;
	Trie() : cur(0){
		mem(node[0].child , 0);
		node[0].exist = node[0].cnt = 0;
	}
	int new_node(){
		cur++;
		mem(node[cur].child , 0);
		node[cur].exist = node[cur].cnt = 0;	
		return cur;
	}
	void add_num(int s){
		int pos = 0;
		for(int i = 30 ; i >= 0 ; i--){
			int c = BIT(s , i);
			if(!node[pos].child[c]) node[pos].child[c] = new_node();
			pos = node[pos].child[c];
			node[pos].cnt++;
		}
		node[pos].exist++;
	}
	int find_num(int s){
		int pos = 0;
		int ans = 0;
		for(int i = 30 ; i >= 0 ; i--){
			int c = BIT(s , i);
			if(node[pos].child[1 - c]){
				if(!c)ans += (1 << i);
				// cout << node[pos].child[1 - c] << ' ' << i << ' ' << c << '\n';
				pos = node[pos].child[1 - c];
			}
			else{
				pos = node[pos].child[c];
				if(c) ans += (1 << i);
			}
		}
		// nl;
		return ans;
	}
} trie;
int n , a[N];
void inp()
{
	mem(trie.node[0].child , 0);
	cin >> n;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		if(i >= 2) ans = max(ans , (trie.find_num(x) ^ x));
		trie.add_num(x);
	}
	cout << ans << '\n';
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
    cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
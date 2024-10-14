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
#define file "square"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 60 + 5;
const int LOG = 20;

int n;
vector<vector<char>> a , u;
vector<char> v;
map <vector<vector<char>> , bool> vst;

vector<vector<char>> swap_cus(vector<vector<char>> inv , int x , int y , int type){
	for(int i = 1 ; i <= n ; i++){
		if(type == 1) swap(inv[i][x] , inv[i][y]);
		else swap(inv[x][i] , inv[y][i]);
	}
	return inv;
}

bool check(vector<vector<char>> inv){
	for(int i = 1 ; i <= n ; i++){
		if(inv[i][i] != 'X') return 0;
		if(inv[i][n - i + 1] != 'X') return 0;
	}
	return 1;
}

void bfs(){
	vst.clear();
	queue<vector<vector<char>>> q;
	q.push(a);
	vst[a] = 1;
	while(q.size()){
		u = q.front();
		if(check(u)){
			cout << "POSSIBLE\n";
			return;
		}
		q.pop();

		for(int i = 1 ; i < n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				vector<vector<char>> tmp = swap_cus(u , i , j , 1);


	// 		cout << i << ' ' << j << '\n';

	// for(int i = 1 ; i <= n ; i++){
	// 	for(int j = 1 ; j <= n ; j++){
	// 		cout << tmp[i][j];
	// 	}
	// 	nl;
	// }
	// nl;
				if(!vst[tmp]){
					// cout << "gg\n";
					if(check(tmp)){
						cout << "POSSIBLE\n";
						return;
					}
					q.push(tmp);
					vst[tmp] = 1;
				}

				tmp = swap_cus(u , i , j , 2);
				if(!vst[tmp]){
					if(check(tmp)){
						cout << "POSSIBLE\n";
						return;
					}
					// cout << "gg\n";
					q.push(tmp);
					vst[tmp] = 1;
					if(check(tmp)){
						cout << "POSSIBLE\n";
						return;
					}
				}
			}
		}
	}

	cout << "IMPOSSIBLE\n";
}

void inp()
{
	cin >> n;
	a.pb(v);
	for(int i = 1 ; i <= n ; i++){
		a.pb(v);
		for(int j = 1 ; j <= n ; j++){
			char x;
			cin >> x;
			a[i].pb(x);
		}
	}


	// for(int i = 1 ; i <= n ; i++){
	// 	for(int j = 1 ; j <= n ; j++){
	// 		cout << a[i][j];
	// 	}
	// 	nl;
	// }
}

void solve()
{
	bfs();
	// cout << 1;
	a.clear();
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
	v.pb('0');
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
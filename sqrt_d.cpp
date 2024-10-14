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
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

struct Point{
	int x , y , id;
} p[N];

bool cmp(Point a , Point b){
	return a.y < b.y;
}

bool cmp1(Point a , Point b){
	return a.x < b.x;
}

int n , num_block = 1;
vector<Point> path[N];

void prepare(){
	sort(p + 1 , p + 1 + n , cmp);

	int tmp = 0;

	for(int i = 1 ; i <= n ; i++){
		if(p[i].y > tmp) num_block++;
		while(p[i].y > tmp){
			tmp += 1e3;
		}
		path[num_block].pb(p[i]);
	}
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	prepare();
}

void solve()
{
	for(int i = 1 ; i <= num_block ; i++){
		sort(all(path[i]) , cmp1);
		if(i % 2 == 0) reverse(all(path[i]));
		for(auto j : path[i]) cout << j.id << ' ';
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
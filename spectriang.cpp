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
#define file "spectriang"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
struct Point{
	int x , y;
}p[N];
int n;
ll cnt;
bool cmp(Point a , Point b){
	return a.x < b.x;
}
vector <int> col[N] , row[N];
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> p[i].x >> p[i].y;
	}
}

void solve()
{
	sort(p + 1 , p + 1 + n , cmp);
	for(int i =1 ;  i<= n ; i++){
		col[p[i].x].pb(p[i].y);
		row[p[i].y].pb(p[i].x);
		sort(all(col[p[i].x]));
		sort(all(row[p[i].y]));
	}
	for(int i = 1 ; i < n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			if(p[i].x == p[j].x){
				int pos1 = lower_bound(all(row[p[i].y]) , p[j].x) - row[p[i].y].begin();
				int pos2 = lower_bound(all(row[p[j].y]) , p[i].x) - row[p[j].y].begin();
				int pos3 = upper_bound(all(row[p[i].y]) , p[j].x) - row[p[i].y].begin();
				int pos4 = upper_bound(all(row[p[j].y]) , p[i].x) - row[p[j].y].begin();
				// nl;
				// cout << p[i].x << ' ' << p[i].y << '\n';
				// cout << p[j].x << ' ' << p[j].y << '\n';
				// cout << row[p[j].y][pos4] << ' ' << p[j].y << '\n';
				if(abs(row[p[i].y][pos1 - 1] - p[i].x) == abs(p[j].y - p[i].y)) cnt++;
				if(abs(row[p[j].y][pos2 - 1] - p[j].x) == abs(p[j].y - p[i].y)) cnt++;
				if(abs(row[p[i].y][pos3] - p[i].x) == abs(p[j].y - p[i].y)) cnt++;
				if(abs(row[p[j].y][pos4] - p[j].x) == abs(p[j].y - p[i].y)) cnt++;
			}
		}
	}
	cout << cnt;
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
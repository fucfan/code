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
#define file "rect2"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
struct rec{
	ll x1 , x2 , y1 , y2;
} rect[N];
int n;
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> rect[i].x1 >> rect[i].x2 >> rect[i].y1 >> rect[i].y2;
	}
}

void solve()
{
	ll ans = 0;
	for(int mask = 1 ; mask < (1 << n) ; mask++){
		ll tmp = -1;
		if(__builtin_popcount(mask) & 1) tmp = 1;
		ll bot1 = 0 , bot2 = 0;
		ll top1 = oo , top2 = oo;
		bool check = 1;
		for(int j = 0 ; j < n ; j++){
			if(!BIT(mask , j))continue;
			int new_bot1 = max(bot1 , rect[j + 1].x1);
			int new_bot2 = max(bot2 , rect[j + 1].x2);
			int new_top1 = min(top1 , rect[j + 1].y1);
			int new_top2 = min(top2 , rect[j + 1].y2);
			// cout << new_bot1 << ' ' << new_top1 << ' '  << new_bot2 << ' ' << new_top2 << '\n';
			if(new_bot1 <= new_top1 && new_bot2 <= new_top2){
				bot1 = new_bot1;
				bot2 = new_bot2;
				top1 = new_top1;
				top2 = new_top2;
			}
			else{
				check = 0;
				break;
			}
		}
		if(check){
			ans += (top1 - bot1) * (top2 - bot2) *tmp;
		}
	}
	cout << ans;
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
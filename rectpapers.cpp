#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "rectpapers"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , a[5] , c[5];
pii rect[N][2];
set <pii> s;
void out(){
	// cout << a[1] << ' ' << a[2] << ' ' << a[3] << '\n';
	for(int mask = 0 ; mask < 8 ; mask++){
		pii new_rect = rect[a[1]][BIT(mask , a[1] - 1)];
		// cout << new_rect.fi << ' ' << new_rect.se << "gg\n";
		if(new_rect.fi == rect[a[2]][BIT(mask , a[2] - 1)].fi){
			new_rect.se += rect[a[2]][BIT(mask , a[2] - 1)].se;
		}
		else if(new_rect.se == rect[a[2]][BIT(mask , a[2] - 1)].se){
			new_rect.fi += rect[a[2]][BIT(mask , a[2] - 1)].fi;
		}
		else continue;
		// cout << new_rect.fi << ' ' << new_rect.se << '\n';
		// cout << rect[a[3]][BIT(mask , a[3] - 1)].fi << ' '
		// 	 << rect[a[3]][BIT(mask , a[3] - 1)].se << "gg\n";
		if(new_rect.fi == rect[a[3]][BIT(mask , a[3] - 1)].fi){
			new_rect.se += rect[a[3]][BIT(mask , a[3] - 1)].se;
			s.insert({min(new_rect.fi , new_rect.se) ,
					  max(new_rect.fi , new_rect.se)});
			new_rect.se -= rect[a[3]][BIT(mask , a[3] - 1)].se;
		}
		if(new_rect.se == rect[a[3]][BIT(mask , a[3] - 1)].se){
			new_rect.fi += rect[a[3]][BIT(mask , a[3] - 1)].fi;
			s.insert({min(new_rect.fi , new_rect.se) ,
					  max(new_rect.fi , new_rect.se)});
			new_rect.fi -= rect[a[3]][BIT(mask , a[3] - 1)].fi;
		}
	}
}
void btr(int i){
	for(int j = 1 ; j <= 3 ; j++){
		if(c[j]) continue;
		c[j] = 1;
		a[i] = j;
		if(i == 3) out();
		else btr(i + 1);
		c[j] = 0;
	}
}
void inp()
{
	s.clear();
	mem(a , 0);
	cin >> rect[1][0].fi >> rect[1][0].se;
	cin >> rect[2][0].fi >> rect[2][0].se;
	cin >> rect[3][0].fi >> rect[3][0].se;
	rect[1][1].fi = rect[1][0].se;
	rect[1][1].se = rect[1][0].fi;
	rect[2][1].fi = rect[2][0].se;
	rect[2][1].se = rect[2][0].fi;
	rect[3][1].fi = rect[3][0].se;
	rect[3][1].se = rect[3][0].fi;
	btr(1);
	cout << s.size() << '\n';
	// for(auto j : s) cout << j.fi << ' ' << j.se << '\n';
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
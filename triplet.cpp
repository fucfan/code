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
#define file "triplet"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int minA , maxA , minB , maxB , minC , maxC , res;

int cal(int k){
	int res = 0;

	for(int i = 1 ; i <= sqrt(k) ; i++){
		if(k % i) continue;

		if(minA <= i && i <= maxA && minB <= k / i && k / i <= maxB){
			res++;
		}

		if(i * i == k) continue;

		if(minB <= i && i <= maxB && minA <= k / i && k / i <= maxA){
			res++;
		}
	}

	return res;
}

void inp()
{
	cin >> minA >> maxA >> minB >> maxB >> minC >> maxC;
}

void solve()
{
	for(int i = minC ; i <= maxC ; i++){
		res += cal(i);
	}

	cout << res;
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
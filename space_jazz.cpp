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
#define file "phuc"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
string s;
int dp[502][502];
void inp()
{	
	cin >> s;
}	

void solve()
{
	for(int j = 0 ; j < (int)s.size() ; j++){
		for(int i = 0 ; i < (int)s.size() - j ; i++){
			dp[i][i + j] = dp[i + 1][j + i] + 1;
			for(int k = i + 1 ; k <= i + j ; k++){
				if(s[i] == s[k]){
					dp[i][i + j] = min(dp[i][j + i] , dp[i + 1][k - 1] + dp[k + 1][j + i]);
				}
			}
		}
	}
	cout << dp[0][s.size() - 1];
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
    // run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
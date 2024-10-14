#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "vrestore"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , a[N] , cnt[200] , tmp[200] , Max;
map <int , map<vector<int> , pii>> dp;
vector <int> st;

ll sol(int i , vector <int> chosen){
    // cout << i << '\n';

    // for(auto j : chosen) cout << j << ' ';
    //  cout << "gg\n";

    if(i > n){
        if(st.size() < 3) st = chosen;

	    for(int j = 1 ; j <= Max ; j++) tmp[j] = cnt[j];

	    for(int j = 1 ; j < i - 1 ; j++){
	        for(int k = j + 1 ; k < i ; k++){
	            tmp[chosen[j] + chosen[k]]--;
	            if(tmp[chosen[j] + chosen[k]] < 0) return 0;
	        }
	    }
        // for(auto j : chosen) cout << j << ' ';
        //     nl;
        return 1;
    }

    if(dp[i][chosen].se) return dp[i][chosen].fi;

    int res = 0;

    for(int j = chosen.back() + 1 ; j <= Max ; j++){
        chosen.pb(j);
        res += sol(i + 1 , chosen);
        chosen.pop_back();
    }

    dp[i][chosen].se = 1;

    return dp[i][chosen].fi = res;
}

void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n * (n - 1) / 2 ; i++){
        cin >> a[i];
        Max = max(Max , a[i]);
        cnt[a[i]]++;
    }
}

void solve()
{
    st.pb(0);
    cout << sol(1 , st) << '\n';
    for(int i = 1 ; i < st.size() ; i++) cout << st[i] << ' ';
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
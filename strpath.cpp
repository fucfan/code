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
#define add(x , y) ((x) = ((x) + (y) >= d ? (x) + (y) - d : (x) + (y)))
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "test"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 200 + 5;
const int LOG = 20;

int n , m , d , sz;
string s;
ll dp[151][151][151][21];
char a[N][N];

ll sol(int i , int j , int u , int v , int pos){
    if(a[i][j] == '#' || a[u][v] == '#') return 0;

    if(u < i || v < j) return 0;

    if(a[i][j] != a[u][v]) return 0;

    // cout << i << ' ' << j << ' ' << u << ' ' << v << ' ' << pos << '\n';

    if(dp[i][j][u][pos] != -1) return dp[i][j][u][pos];

    if(u - i + v - j >= 0 && u - i + v - j <= 1){
        if(pos + (a[i][j] == s[pos]) >= sz) return 1;
        return 0;
    }

    ll res = 0;

    int nxt_pos = pos;
    if(nxt_pos < sz){
	    if(a[i][j] == s[pos]) nxt_pos++;
	    else nxt_pos = (a[i][j] == s[0]);
	}

    (res += sol(i + 1 , j , u - 1 , v , nxt_pos)) %= d;
    (res += sol(i + 1 , j , u , v - 1 , nxt_pos)) %= d;
    (res += sol(i , j + 1 , u - 1 , v , nxt_pos)) %= d;
    (res += sol(i , j + 1 , u , v - 1 , nxt_pos)) %= d;

    return dp[i][j][u][pos] = res;
}

void inp()
{
    cin >> n >> m >> d >> s;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++) cin >> a[i][j];
    }

    sz = s.size();
}

void solve()
{
    mem(dp , -1);
    cout << sol(1 , 1 , n , m , (a[1][1] == s[0]));
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
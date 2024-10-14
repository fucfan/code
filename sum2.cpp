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
const int N = 550 + 5;
const int LOG = 10;
int n , m , q;
ll a[N][N];
ll rmq[N][N][LOG + 2][LOG + 2];
void inp()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> a[i][j];
		}
	}
	cin >> q;
	for(int g = 1 ; g <= q ; g++){
		int l1 , r1 , l2 , r2 , x;
		cin >> l1 >> r1 >> l2 >> r2 >> x;
		// int last = 0;
		for(int i = LOG ; i >= 0 ; i--){
			for(int j = LOG ; j >= 0 ; j--){
				if(l1 + MASK(i) - 1 <= l2 &&
				   r1 + MASK(j) - 1 <= r2){ 
					rmq[l1][r1][i][j] += x;
					if(l1 + MASK(i) <= l2){
						rmq[l1 + MASK(i)][r1][0][j] += x;
					}
					if(r1 + MASK(j) <= r2){
						rmq[l1][r1 + MASK(j)][i][0] += x;
					}
					l1 += MASK(i);
					r1 += MASK(i);
					// last = i;
				}
			}
		}
	}
	for(int k1 = LOG ; k1 >= 0 ; k1--){
		for(int k2 = LOG ; k2 >= 0 ; k2--){
			for(int i = 1 ; i <= n ; i++){
				for(int j = 1 ; j <= m ; j++){
							// cout << i << ' ' << j << ' ' << k1 << ' ' << k2 << ' ' << rmq[i][j][k1][k2] << '\n';					// if(k1 && k2){
					// 	rmq[i][j][k1 - 1][k2 - 1] += rmq[i][j][k1][k2];
					// 	if(i + MASK(k1 - 1) - 1 <= n && j + MASK(k2 - 1) - 1 <= m){
					// 	// cout << i + MASK(k1 - 1) << '\n';
					// 		rmq[i + MASK(k1 - 1)][j][k1 - 1][k2 - 1] += rmq[i][j][k1][k2];
					// 		rmq[i][j + MASK(k2 - 1)][k1 - 1][k2 - 1] += rmq[i][j][k1][k2];
					// 		rmq[i + MASK(k1 - 1)][j + MASK(k2 - 1)][k1 - 1][k2 - 1] += rmq[i][j][k1][k2];
					// 	}
					// }
					if(k1){
						if(i + MASK(k1 - 1) - 1 <= n){
							rmq[i][j][k1 - 1][k2] += rmq[i][j][k1][k2];
							rmq[i + MASK(k1 - 1)][j][k1 - 1][k2] += rmq[i][j][k1][k2];
						}
					}
					else if(k2){
						if(j + MASK(k2 - 1) - 1 <= m){
							rmq[i][j][k1][k2 - 1] += rmq[i][j][k1][k2];
							rmq[i][j + MASK(k2 - 1)][k1][k2 - 1] += rmq[i][j][k1][k2];
						}
					}
					// if(k1 && k2)rmq[i][j][k1 - 1][k2 - 1] -= rmq[i][j][k1][k2];
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cout << rmq[i][j][0][0] + a[i][j] << ' ';
		}
		nl;
	}
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
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
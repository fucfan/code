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
int n;
ll sum , sub , a[N] , min_rmq[N][LOG + 5] , max_rmq[N][LOG + 5];
void prepare(){
	for(int j = 1 ; j <= LOG ; j++){
		for(int i = 1 ; i <= n ; i++){
			max_rmq[i][j] = max(max_rmq[i][j - 1] , max_rmq[i + (1 << (j - 1))][j - 1]);
			min_rmq[i][j] = min(min_rmq[i][j - 1] , min_rmq[i + (1 << (j - 1))][j - 1]);
		}
	}
}
void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		min_rmq[i][0] = a[i];
		max_rmq[i][0] = a[i]; 
	}
	prepare();
}

void solve()
{
	for(int i = 1 ; i <= n ; i++){
		int tmp = i + 1;
		for(int j = LOG ; j >= 0 ; j--){
			if(max_rmq[tmp][j] <= a[i]) tmp += (1 << j);
		}
		int tmp1 = i - 1;
		for(int j = LOG ; j >= 0 ; j--){
			if(tmp1 - (1 << j) < 0) continue;
			if(max_rmq[tmp1 - (1 << j) + 1][j] < a[i]) tmp1 -= (1 << j);
		}
		tmp1 = max(tmp1 , 0);
		tmp = min(tmp , n + 1);
		tmp1++; tmp--;
		// cout << tmp1 << ' ' << tmp << '\n';	
		sum += 1ll * (tmp - i + 1) * (i - tmp1 + 1) * a[i];
		// cout << (tmp - i + 1) * (i - tmp1 + 1) << '\n';
	}		
	for(int i = 1 ; i <= n ; i++){
		int tmp = i + 1;
		for(int j = LOG ; j >= 0 ; j--){
			if(min_rmq[tmp][j] >= a[i]) tmp += (1 << j);
		}
		int tmp1 = i - 1;
		for(int j = LOG ; j >= 0 ; j--){
			if(tmp1 - (1 << j) < 0) continue;
			if(min_rmq[tmp1 - (1 << j) + 1][j] > a[i]) tmp1 -= (1 << j);
		}
		tmp1 = max(tmp1 , 0);
		tmp = min(tmp , n + 1);
		tmp1++; tmp--;
		// cout << tmp1 << ' ' << tmp << '\n';	
		sub += 1ll * (tmp - i + 1) * (i - tmp1 + 1) * a[i];
		// cout << (tmp - i + 1) * (i - tmp1 + 1) << '\n';
	}		
	cout << sum - sub;
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
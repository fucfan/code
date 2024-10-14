#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
long a[N] , ans;
long solve(int i , int dis , long cnt){
    if(i > n){
        return cnt;
    }
    cnt = cnt + a[i];
    if(dis < 1) return max(solve(i + 2 , 0 , cnt),solve(i + 1 , 1 , cnt));
    else return solve(i + 2 , 0 , cnt);
}
void inp()
{
    cin >> n ;
    for(int i = 1 ; i<= n ; i++){   
        // cin >> a[i];
        a[i] = 1;
    }
}

void solve()
{
    cout << solve(0 , 0 , 0);
}

void run_with_file()
{
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
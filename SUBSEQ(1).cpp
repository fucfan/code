#include<bits/stdc++.h>
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , k , d;
long a[1000001] , b[1000001] , MIN[1000001];
long long s , g , h;
void inp()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
}

void solve() 
{
    MIN[0] = 0;
    b[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        b[i] = a[i] + b[i - 1];
        MIN[i] = min(MIN[i - 1] , b[i]);
    }
    for(int i = k; i <= n ; i++){
        s = b[i] - MIN[i - k];
        // cout << s << " " << i - k + 1 << " ";
        g = max(g , s);
    }
    cout << g;
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
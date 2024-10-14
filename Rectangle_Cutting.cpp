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
int a , b , d , g , f[507][507];
ll ans;
ll cut(int a , int b){
    // cout << a << ' ' << b << ' ' << move << '\n';
    if(a == b){
        return 0;
    }
    if(f[a][b] != -1) return f[a][b];
    ll x = 1e9;
    ll y = 1e9;
    for(int i = 1 ; i <= g ; i++){
        if(i < a) x = min(cut(i , b) +  cut(a - i , b) + 1 , x);
        if(i < b) y = min(cut(a , i) +  cut(a , b - i) + 1 , y);
    }
    f[a][b] = min(x , y);
    return f[a][b];
}
void inp()
{
    cin >> a >> b;
    g = max(a , b);
}

void solve()
{
    mem(f , -1);
    cout << cut(a , b);
    // cout << ans;
}

void run_with_file()
{
//    if(fopen(file".inp","r")){
//        freopen(file".inp","r", stdin);
//        freopen(file".out", "w", stdout);
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
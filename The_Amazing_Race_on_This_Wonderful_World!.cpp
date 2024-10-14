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
const ll race = 100;
const ll length_t = 10;
int t;
ll tx , sx , ty , sy , time1 , time2;
void inp()
{
    cin >> t;
    for(int i = 1 ; i <= t ; i++){
        cin >> tx >> sx >> ty >> sy;
        ll num = (tx + sx) * (ty + sy) * tx * ty * sx * sy;
        ll dis1 = ((tx + sx) * ((length_t * num)/sx));
        ll dis2 = ((ty + sy) * ((length_t * num)/sy));
        if(dis1 >= race * num) time1 = (race * num) / (tx + sx);
        else time1 = ((length_t * num) / sx) + ((race * num - dis1) / tx);
        if(dis2 >= race * num) time2 = (race * num) / (ty + sy);
        else time2 = ((length_t * num) / sy) + ((race * num - dis2) / ty);
        // cout << (time1 - time2) << '\n';
        if(time1 - time2 > 0) cout << "Yunyun\n";
        if(time1 - time2 < 0) cout << "Megumin\n";
        if(time1 - time2 == 0) cout << "Draw\n";
    }
}

void solve()
{
    
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
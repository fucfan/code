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
#define file "water"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int x , y , k , m , ans;
bool check[200][200][200];
void sol(int i , int water1 , int water2){
    ans = min(ans , abs(m - water1 - water2));
    if(i > k){
        return;
    }
    if(check[i][water1][water2]){
        return;
    }
    check[i][water1][water2] = true;
    sol(i + 1 , 0 , water2);
    sol(i + 1 , water1 , 0);
    sol(i + 1 , x , water2);
    sol(i + 1 , water1 , y);
    sol(i + 1 , min(water1 + water2 , x) , max(0 , water2 - (x - water1)));
    sol(i + 1 , max(0 , water1 - (y - water2)) , min(water1 + water2 , y));
}
void inp()
{
    cin >> x >> y >> k >> m;
}

void solve()
{
    ans = 1e9;
    sol(1 , 0 , 0);
    cout << ans;
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
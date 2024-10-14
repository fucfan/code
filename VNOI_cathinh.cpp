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
long pres[1007][1007];
long g[1007][1007] , n , m , k , x , y , u , v , minc , minl;
int bsn(int l , int r , long x , int a , int b , int u , int v){
    int mid = (l + r)/2;
    long chot = pres[mid][v] - pres[a - 1][v] - pres[mid][b - 1] + pres[a - 1][b - 1];
    return chot;
    if(x == chot)return 0;
    if(x > chot) return bsn(mid , r , x , a , b , u , v);
    if(x < chot) return bsn(l , mid , x , a , b , u , v);
}
void inp()
{
    mem(g , 0);
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            cin >> g[i][j];
            pres[1][1] = g[1][1];
            pres[i][j] = g[i][j] + pres[i - 1][j] + pres[i][j - 1] - pres[i - 1][j - 1];
        }
    }
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cout << pres[i][j] << ' ';
        }
        nl;
    }
    long k =  pres[4][3] - pres[4][1] - pres[1][3] + pres[1][1];
    // cout << pres[1][4];
    cout << bsn(2 , 4 , k , 2 , 2 , 4 , 3);
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
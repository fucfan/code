#include <bits/stdc++.h>
#define ll long long
#define name "rmindist"

const int N = 500 + 5;
const ll oo = 1e18 + 7;

using namespace std;

int n , m , l , r , a[N][N];
ll pref[N][N];

ll get(int x , int y , int u , int v){
    return pref[u][v] - pref[u][y - 1] - pref[x - 1][v] + pref[x - 1][y - 1];
}

int main(){
    freopen(name".inp" , "r" , stdin);
    freopen(name".out" , "w" , stdout);
    cin >> n >> m >> l >> r;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
    ll ans = oo;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            for(int x = i ; x <= n ; x++){
                for(int y = j ; y <= m ; y++){
                    ll val = get(i , j , x , y);
                    ans = min(ans , abs(val - l) + abs(val - r));
                }
            }
        }
    }
    cout << ans;
}

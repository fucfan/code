#include <bits/stdc++.h>
#define BIT(x , i) (((x) >> (i)) & 1)
#define flip(x , i) ((x) ^ (1 << (i)))
#define ll long long
#define fi first
#define se second
#define pii pair <int , int>
#define all(c) (c).begin() , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(a))
#define nl cout << '\n';
#define pb push_back
#define file "test"

using namespace std;

const int N = 5e2 + 5;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

int n , m , q , R , D;
int a[N][N] , pref[N][N];

void update(int num_r , int num_d){
    int new_pos[N][N];

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            new_pos[i][(j - num_r - 1 + m * 1000) % m + 1] = a[i][j];
        }
    }
//
//    for(int f = 1 ; f <= n ; f++){
//        for(int g = 1 ; g <= m ; g++){
//            cout << new_pos[f][g] << ' ';
//        }
//        nl;
//    }
//    nl;

    for(int j = 1 ; j <= m ; j++){
        for(int i = 1 ; i <= n ; i++){
            a[(i - num_d - 1 + n * 1000) % n + 1][j] = new_pos[i][j];
        }
    }

//    for(int f = 1 ; f <= n ; f++){
//        for(int g = 1 ; g <= m ; g++){
//            cout << a[f][g] << ' ';
//        }
//        nl;
//    }
//    nl;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
}

int get(int u , int v , int s , int t){
    return pref[s][t] - pref[s][v - 1] - pref[u - 1][t] + pref[u - 1][v - 1];
}

void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
}

void solve()
{
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int type;
        cin >> type;
        if(!type){
            int x , y;
            cin >> x >> y;
            R += x;
            D += y;
        }
        else{
            int u , v , s , t;
            cin >> u >> v >> s >> t;
            u = (1ll * u - D - 1 + 1ll * n * 50000000) % n;

            cout << get(u , v , s , t) << '\n';
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
//    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

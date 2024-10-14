#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair <int , int>
#define all(c) (c).begin() , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(a))
#define pb push_back
#define BIT(x , i) (((x) >> (i)) & 1)
#define FLIP(x , i) ((x) ^ (1 << (i)))
#define nl cout << '\n';
#define file "three"

using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;
const int base = 31;
const int LOG = 20;
const int mod = 1e9 + 7;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

int n , m , q , test_case;

struct item{
    int x , y;
    ll w;
} a[N];

struct Query{
    int id;
    ll up;
} query[N];

namespace sub3{
    ll pref1[501][501];
    ll pref2[501][501];
    ll board[501][501];

    bool check(){
        return ((n <= 500) && (m <= 500) && (q <= 500) && (test_case == 1));
    }

    void prepare(){
        mem(pref1 , 0);
        mem(pref2 , 0);

        for(int i = 1 ; i <= m ; i++){
            pref1[a[i].x][a[i].y] = a[i].w;
            pref2[a[i].x][a[i].y] = a[i].w;
            board[a[i].x][a[i].y] = a[i].w;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                pref1[i][j] += pref1[i - 1][j];
                pref2[i][j] += pref2[i][j - 1];
            }
        }
//
//        for(int i = 1 ; i <= n ; i++){
//            cout << pref1[n][i] << ' ';
//        }
//
//        nl;
//
//        for(int i = 1 ; i <= n ; i++){
//            cout << pref2[i][n] << ' ';
//        }
    }

    void solve(){
        prepare();

            ll ans = 0;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k = 1 ; k <= n ; k++){
                    ll sum = 0;
                    sum += pref2[i][n] + pref1[n][j] - board[i][j];
                    if(k != j) ans = max(ans , sum + pref1[n][k] - board[i][k]);
                    if(k != i) ans = max(ans , sum + pref2[k][n] - board[k][j]);
                }
            }
        }

        for(int i = 1 ; i <= n - 2 ; i++){
            for(int j = i + 1 ; j <= n - 1 ; j++){
                for(int k = j + 1 ; k <= n ; k++){
                    ans = max(ans , pref1[n][i] + pref1[n][j] + pref1[n][k]);
                    ans = max(ans , pref2[i][n] + pref2[j][n] + pref2[k][n]);
                }
            }
        }

        cout << ans << '\n';

        for(int g = 1 ; g <= q ; g++){
            int x = a[query[g].id].x;
            int y = a[query[g].id].y;
            ll w = query[g].up;
            pref1[n][y] += w;
            pref2[x][n] += w;
            board[x][y] += w;

            ll sum = pref2[x][n] + pref1[n][y] - board[x][y];

            ll new_ans = 0;

            for(int k = 1 ; k <= n ; k++){
                if(k != y) new_ans = max(new_ans , sum + pref1[n][k] - board[x][k]);
                if(k != x) new_ans = max(new_ans , sum + pref2[k][n] - board[k][y]);
            }

            for(int i = 1 ; i < n ; i++){
                for(int j = i + 1 ; j <= n ; j++){
                    if(i != x && j != x) new_ans = max(new_ans , pref2[x][n] + pref2[i][n] + pref2[j][n]);
                    if(i != y && j != y) new_ans = max(new_ans , pref1[n][y] + pref1[n][i] + pref1[n][j]);
                }
            }

            cout << max(ans , new_ans) << '\n';

            pref1[n][y] -= w;
            pref2[x][n] -= w;
            board[x][y] -= w;
        }
    }
}

void inp(){
    cin >> n >> m >> q;

    for(int i = 1 ; i <= m ; i++){
        cin >> a[i].x >> a[i].y >> a[i].w;
    }

    for(int i = 1 ; i <= q ; i++){
        cin >> query[i].id >> query[i].up;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();

    cin >> test_case;
    for(int g = 1 ; g <= test_case ; g++){
        inp();
        if(sub3::check()) return sub3::solve() , 0;
    }
}
/*


1
3 3 1
1 1 1
1 2 2
1 3 3
3 1


*/


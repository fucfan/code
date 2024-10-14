#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "rmq2"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 60;
int n , m , q , a[N][N] , rmq[N][N][13][13] , lg2[N];
void prepare(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            rmq[i][j][0][0] = a[i][j];
        }
    }
    for(int k2 = 1 ; k2 < 10 ; k2++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                // cout << (1 << (k2 - 1)) << '\n';
                rmq[i][j][0][k2] = min(rmq[i][j][0][k2 - 1] , rmq[i][j + (1 << (k2 - 1))][0][k2 - 1]);
                rmq[i][j][k2][0] = min(rmq[i][j][k2 - 1][0] , rmq[i + (1 << (k2 - 1))][j][k2 - 1][0]);
            }
        }
    }
    for(int k1 = 1 ; k1 < 10 ; k1++){
        for(int k2 = 1 ; k2 < 10 ; k2++){
            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= m ; j++){
                    rmq[i][j][k1][k2] = min(
                                    min(rmq[i][j][k1 - 1][k2 - 1] , 
                                        rmq[i + (1 << (k1 - 1))][j][k1 - 1][k2 - 1]) ,

                                    min(rmq[i][j + (1 << (k2 - 1))][k1 - 1][k2 - 1] ,
                                        rmq[i + (1 << (k1 - 1))][j + (1 << (k2 - 1))][k1 - 1][k2 - 1])
                                        );
                }
            }
        }
    }
    for(int i = 1 ; i <= max(n , m) ; i++){
        while((1 << (lg2[i])) <= i) lg2[i]++;
        lg2[i]--;
    }
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
            // a[i][j] = 1;
        }
    }
    prepare();
    // for(int k1 = 1 ; k1 < 10 ; k1++){
    //     for(int k2 = 1 ; k2 < 10 ; k2++){
    //         for(int i = 1 ; i <= n ; i++){
    //             for(int j = 1 ; j <= m ; j++){
    //                 cout << rmq[i][j][k1][k2] << ' ';
    //             }
    //             nl;
    //         }
    //         nl;
    //     }
    // }
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int x , y , u , v;
        cin >> x >> y >> u >> v;
        int k1 = lg2[u - x + 1];
        int k2 = lg2[v - y + 1];
        // cout << u - (1 << (k1)) + 1 << ' ' << v - (1 << (k2)) + 1 << '\n';
        cout << min(
            min(rmq[x][y][k1][k2] ,
                rmq[u - (1 << (k1)) + 1][y][k1][k2]) , 

            min(rmq[x][v - (1 << (k2)) + 1][k1][k2] ,
                rmq[u - (1 << (k1)) + 1][v - (1 << (k2)) + 1][k1][k2])
                ) << '\n';
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
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UwU      */
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "tetris"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 20 + 5;
const int LOG = 20;
const int base = 31;
const vector <pii> shape[] = {{{0 , 0} , {1 , 0} , {0 , 1} , {1 , 1}} ,
                              {{0 , 0} , {1 , 0} , {2 , 0} , {3 , 0}} ,
                              {{0 , 0} , {1 , 0} , {1 , 1} , {2 , 1}} ,
                              {{0 , 0} , {1 , 0} , {1 , -1} , {2 , -1}} ,
                              {{0 , 0} , {1 , 0} , {0 , 1} , {-1 , 0}}};


void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , m , ans[N];
char board[N][N];

void inp(){
    cin >> n >> m;
    for(int i = 0 ; i < max(n , m) ; i++){
        for(int j = 0 ; j < max(n , m) ; j++){
            board[i][j] = '.';
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }
}

void solve(){
    for(int spin = 1 ; spin <= 4 ;spin++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == '.') continue;
                for(int f = 0 ; f < 5 ; f++){
                    for(int g = 0 ; g < 4 ; g++){
                        pii cent = {i , j};
                        cent.fi += shape[f][g].fi;
                        cent.se += shape[f][g].se;
                        int type = -1;
                        bool ok = 1;
                        for(int v = 0 ; v < 4 ; v++){
                            pii tmp = cent;
                            tmp.fi += shape[f][v].fi;
                            tmp.se += shape[f][v].se;
                            
                            if(tmp.fi < 0 || tmp.se < 0 || board[tmp.fi][tmp.se] != board[i][j]){
                                ok = 0;
                                break;
                            }
                        }
                        if(ok){
                            // cout << cent.fi << ' ' << cent.se << ' ' << f << '\n';
                            ans[f]++;
                            for(int v = 0 ; v < 4 ; v++){
                                pii tmp = cent;
                                tmp.fi += shape[f][v].fi;
                                tmp.se += shape[f][v].se;
                                board[tmp.fi][tmp.se] = '.';
                            }
                        }
                        if(board[i][j] == '.') break;
                    }
                    if(board[i][j] == '.') break;
                }
            }
        }
        int sz = max(m , n);

        // for(int i = 0 ; i < max(n , m) ; i++){
        //     for(int j = 0 ; j < max(n , m) ; j++){
        //         cout << board[i][j];
        //     }
        //     nl;
        // }
        // nl;

        for(int i = 0 ; i < sz / 2 ; i++){
            for(int j = i ; j < sz - i - 1 ; j++){
                char tmp = board[i][j];
                board[i][j] = board[sz - 1 - j][i];
                board[sz - 1 - j][i] = board[sz - 1 - i][sz - 1 - j];
                board[sz - 1 - i][sz - 1 - j] = board[j][sz - 1 - i];
                board[j][sz - 1 - i] = tmp;
            }
        }
        // for(int i = 0 ; i < sz ; i++){
        //     for(int j = 0 ; j < sz ; j++){
        //         cout << board[i][j];
        //     }
        //     nl;
        // }
        // nl;

        swap(m , n);
    }


    for(int i = 0 ; i < 5 ; i++) cout << ans[i] << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
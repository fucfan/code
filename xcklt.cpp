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
#define file "xcklt"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 500 + 5;
const int LOG = 20;
const int base = 31;
const pair <pii , int> MOVE[] = {{{-1 , -1} , -1} , 
                                 {{-1 , -1} , 0} , 
                                 {{-1 , 0} , -1} , 
                                 {{-1 , 0} , 0} , 
                                 {{0 , -1} , -1} , 
                                 {{0 , -1} , 0}};

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int dp[N][N][N];
int par[N][N][N];
string a , b , c;
int sz_a , sz_b , sz_c;

void inp(){
    cin >> a >> b >> c;
}

void solve(){
    sz_a = a.size();
    sz_b = b.size();
    sz_c = c.size();
    a = " " + a;
    b = " " + b;
    c = " " + c;
    // cout << sol(1 , 1 , 1) << '\n';
    mem(dp , 0x3f);
    dp[1][1][1] = 0;

    for(int i = 1 ; i <= sz_a + 1 ; i++){
        for(int j = 1 ; j <= sz_b + 1 ; j++){
            for(int k = 1 ; k <= sz_c ; k++){
                if(dp[i][j][k] > oo) continue;

                if(a[i] == b[j]){
                    if(a[i] == c[k]){
                        if(mini(dp[i + 1][j + 1][k + 1] , dp[i][j][k] + 1))
                            par[i + 1][j + 1][k + 1] = 1;
                    }
                    else if(mini(dp[i + 1][j + 1][k] , dp[i][j][k] + 1))
                            par[i + 1][j + 1][k] = 2;
                }
                else{
                    if(a[i] == c[k]){
                        if(mini(dp[i + 1][j][k + 1] , dp[i][j][k] + 1))
                            par[i + 1][j][k + 1] = 3;
                    }
                    else if(mini(dp[i + 1][j][k] , dp[i][j][k] + 1))
                            par[i + 1][j][k] = 4;

                    if(b[j] == c[k]){
                        if(mini(dp[i][j + 1][k + 1] , dp[i][j][k] + 1))
                            par[i][j + 1][k + 1] = 5;
                    }
                    else if(mini(dp[i][j + 1][k] , dp[i][j][k] + 1))
                            par[i][j + 1][k] = 6;
                }
            }
        }
    }

    int length = sz_a + sz_b + 1;
    pair <pii , int> st;

    for(int i = 1 ; i < sz_c + 1 ; i++){
        if(mini(length , dp[sz_a + 1][sz_b + 1][i])){
            st = {{sz_a + 1 , sz_b + 1} , i};
        }
    }

    string res;
    // cout << st.fi.fi << ' ' << st.fi.se << ' ' << st.se << '\n';

    if(length <= sz_a + sz_b){
        cout << dp[st.fi.fi][st.fi.se][st.se] << '\n';
        while(dp[st.fi.fi][st.fi.se][st.se] < oo && dp[st.fi.fi][st.fi.se][st.se]){
            int d = par[st.fi.fi][st.fi.se][st.se] - 1;
            // cout << dp[st.fi.fi][st.fi.se][st.se] << ' ' << st.fi.fi << ' ' << st.fi.se << ' ' << st.se << ' ' << res << ' ' << d << '\n';
            st.fi.fi += MOVE[d].fi.fi;
            st.fi.se += MOVE[d].fi.se;
            st.se += MOVE[d].se;
            if(MOVE[d].fi.fi == -1) res = a[st.fi.fi] + res;
            else if(MOVE[d].fi.se == -1) res = b[st.fi.se] + res;
            // cout << dp[st.fi.fi][st.fi.se][st.se] << ' ' << st.fi.fi << ' ' << st.fi.se << ' ' << st.se << ' ' << res << ' ' << d << '\n';
        }
        cout << res;
    }
    else cout << "TRETRAU";
    // cout << 1;
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
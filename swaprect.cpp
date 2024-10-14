#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "swaprect"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 2e2 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , m , k;
vector <int> red , green , blue;
ll dp[N][N][N];

ll sol(int x , int y , int z){
    if(x + y + z < 2) return 0;

    if(x < 0 || y < 0 || z < 0) return -oo;

    if(dp[x][y][z] != -1) return dp[x][y][z];

    ll res = 0;

    res = max(res , sol(x - 1 , y - 1 , z) + red[x] * green[y]);
    res = max(res , sol(x - 1 , y , z - 1) + red[x] * blue[z]);
    res = max(res , sol(x , y - 1 , z - 1) + green[y] * blue[z]);

    return dp[x][y][z] = res;
}

void inp(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        red.pb(x);
    }
    for(int i = 1 ; i <= m ; i++){
        int x;
        cin >> x;
        green.pb(x);
    }
    for(int i = 1 ; i <= k ; i++){
        int x;
        cin >> x;
        blue.pb(x);
    }
}

void solve(){
    red.pb(-1);
    blue.pb(-1);
    green.pb(-1);

    sort(all(red));
    sort(all(blue));
    sort(all(green));

    mem(dp , -1);
    
    cout << sol(n , m , k);
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
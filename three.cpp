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
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct Station{
    int x , y , w;

    void input(){
        cin >> x >> y >> w;
    }
} st[N];

int n , m , q;
vector <int> row , col;
vector <int> st_row[N] , st_col[N];

void preprare(){
    for(int i = 1 ; i <= m ; i++){
        col.pb(st[i].x);
        row.pb(st[i].y);
    }

    sort(all(col));
    col.erase(unique(all(col)) , col.end());
    sort(all(row));
    row.erase(unique(all(row)) , row.end());    

    for(int i = 1 ; i <= m ; i++){
        st[i].x = lower_bound(all(col) , st[i].x) - col.begin() + 1;
        st[i].y = lower_bound(all(row) , st[i].y) - row.begin() + 1;

        st_row[st[i].y].pb(i);
    }
}

void inp(){
    cin >> n >> m >> q;
    for(int i = 1 ; i <= m ; i++){
        st[i].input();
    }
}

void solve(){
    
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
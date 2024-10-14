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
#define file "sumseq"
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

int n, l, r, a[N];
int rmq[N][LOG + 5];

void prepare(){
    for(int i = 1; i <= n; i++){
        rmq[i][0] = rmq[i - 1][0] + a[i];
    }

    for(int j = 1; j <= LOG; j++){
        for(int i = 1; i + (1 << (j - 1)) <= n; i++){
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int get(int l, int r){
    int length = 31 - __builtin_clz(r - l + 1);
    return min(rmq[l][length], rmq[r - (1 << length) + 1][length]);
}

void inp(){
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    prepare();
    int ans = -oo;
    for(int i = l; i <= n; i++){
        ans = max(ans, rmq[i][0] - get(max(0, i - r), i - l));
    }
    cout << ans;
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
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
#define file "triples"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e3 + 5;
const int big_N = 3e6 + 5;
const int LOG = 20;
const int base = 2e6;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, a[N];
int cnt[N];
vector <int> compress;
int pos[big_N];
int val1[N][N];
int val2[N][N];
ll val[N];
ll ans[N];
int sum1[N], sum3[N], sum2[big_N];

void prepare(){
    mem(pos, -1);
    for(int i = 1; i <= n; i++){
        compress.pb(a[i]);
    }
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());
    for(int i = 0; i < compress.size(); i++){
        pos[compress[i] + base] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            val1[i][pos[a[j] + base]]++;
        }

        for(int j = i + 1; j <= n; j++){
            val2[i][pos[a[j] + base]]++;
        }
    }
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    prepare();
    for(int i = 1; i <= n; i++){
        ans[i] = sum3[pos[a[i] + base]];
        for(int j = 0; j < compress.size(); j++){
            sum3[j] += sum2[compress[j] - a[i] + base];
        }
        for(int j = 0; j < compress.size(); j++){
            sum2[a[i] + compress[j] + base] += sum1[j];
        }
        sum1[pos[a[i] + base]]++;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
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
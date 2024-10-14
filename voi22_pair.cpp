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
const int N = 2e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, d, a[N], ans = 0;
vector <int> compress;
vector <pii> seq[N * N];
bool used[N];

bool cmp(pii a, pii b){
    if(a.se == b.se) return a.fi > b.fi;
    return (a.se < b.se);
}

void prepare(){
    sort(a + 1, a + 1 + n);
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            compress.pb(a[i] + a[j]);
            // cout << a[i] + a[j] << '\n';
        }
    }
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());

    for(int len = n; len >= 2; len--){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            int pos = lower_bound(all(compress), a[i] + a[j]) - compress.begin();
            seq[pos].pb({i, j});
            if(d == 1){
                if(pos && compress[pos] == compress[pos - 1] + 1){
                    seq[pos - 1].pb({i, j});
                }
            }
        }
    }
    vector <int> tmp;
    for(int i = 0; i < (int)compress.size(); i++){
        for(auto j : seq[i]){
            if(!used[j.fi] && !used[j.se]){
                used[j.fi] = 1;
                used[j.se] = 1;
                tmp.pb(j.fi);
            }
        }

        for(auto j : seq[i]){
            used[j.fi] = 0;
            used[j.se] = 0;
        }
        tmp.erase(unique(all(tmp)), tmp.end());
        ans = max(ans, (int)tmp.size());
        tmp.clear();
    }
}

void inp(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    prepare();
}

void solve(){
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

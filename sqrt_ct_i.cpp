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
const int BLOCK_SZ = 320;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n, m, q, intersect[BLOCK_SZ][BLOCK_SZ];
int pos[N];
ll val[N], val_update[N], a[N];
vector <int> vt[N];
vector <int> large;
vector <int> large_id[N];

void prepare(){
    for(int i = 1; i <= n; i++){
        for(int bl1 = 0; bl1 < large_id[i].size(); bl1++){
            for(int bl2 = 0; bl2 < large_id[i].size(); bl2++){
                // cout << i << ' ' << bl1 << ' ' << bl2 << '\n';
                intersect[pos[large_id[i][bl1]]][pos[large_id[i][bl2]]]++;
            }
        }
    }
}

void update_small(int k, int value){
    for(auto j : vt[k]){
        a[j] += value;
        for(auto id : large_id[j]){
            // cout << k << ' ' << id << ' ' << value << '\n';
            val[id] += value;
        }
    }
}

void update_large(int k, int value){
    int tmp = pos[k];
    val_update[k] += value;
    for(int bl = 0; bl < (int)large.size(); bl++){
        val[large[bl]] += 1ll * intersect[tmp][bl] * value;
            // cout << k << ' ' << large[bl] << ' ' << 1ll * intersect[tmp][bl] << ' ' << value << '\n';
    }
}

void inp(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        int sz;
        cin >> sz;
        for(int j = 1; j <= sz; j++){
            int x;
            cin >> x;
            vt[i].pb(x);
        }
        sort(all(vt[i]));
        if(vt[i].size() > sqrt(n)){
            pos[i] = large.size();
            large.pb(i);
            for(auto j : vt[i]){
                large_id[j].pb(i);
                val[i] += a[j];
            }
        }
    }
}

void solve(){
    prepare();
    for(int i = 1; i <= q; i++){
        char type;
        int num;
        cin >> type >> num;
        if(type == '+'){
            int value;
            cin >> value;
            if(vt[num].size() > sqrt(n)) update_large(num, value);
            else update_small(num, value);
        }
        else{
            if(vt[num].size() > sqrt(n)) cout << val[num] << "\n";
            else{
                ll ans = 0;
                for(auto j : vt[num]){
                    for(auto p : large_id[j]){
                        ans += val_update[p];
                    }
                    ans += a[j];
                }
                cout << ans << '\n';
            }
        }
    }
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
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "space"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
         freopen(file".inp", "r" , stdin);
         freopen(file".out", "w" , stdout);
    }
}

int n, rad, num_barr;
ll d[N], pos[N], v[N];

namespace sub0{
    bool defended[N];

    bool check(){
        return (n <= 19);
    }

    void solve(){
        ll res = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            if(__builtin_popcount(mask) > num_barr) continue;
            for(int i = 1; i <= n; i++){
                defended[i] = 0;
            }
            for(int i = 1; i <= n; i++){
                if(BIT(mask, i - 1)){
                    defended[i] = 1;
                    for(int j = i - 1; (j >= 1) && (pos[i] - pos[j] <= rad); j--){
                        defended[j] = 1;
                    }
                    for(int j = i + 1; (j <= n) && (pos[j] - pos[i] <= rad); j++){
                        defended[j] = 1;
                    }
                }
            }
            ll val = 0;
            for(int i = 1; i <= n + 1; i++){
                if(defended[i]) val += v[i];
                else{
                    res = max(res, val);
                    val = 0;
                }
            }
        }
        cout << res;
    }
}

namespace sub7{
    int nxt[N];
    ll pref[N];

    map <int, map<int, int>> dp, vst;

    bool check(){
        return 1;
    }

    void prepare(){
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i - 1] + v[i];
        }
        for(int i = 1; i <= n; i++){
            int pos1 = upper_bound(pos + 1, pos + 2 + n, pos[i] + rad) - pos - 1;
            int pos2 = upper_bound(pos + 1, pos + 2 + n, pos[pos1] + rad) - pos - 1;

//            cout << n << ' ' << pos[i] << ' ' << pos1 << ' ' << pos2 << '\n';
            nxt[i] = pos2;
        }
    }

    ll get(int l, int r){
        return pref[r] - pref[l - 1];
    }

    ll sol(int i, int cnt){
        if(i > n || cnt >= num_barr) return 0;
        return sol(nxt[i] + 1, cnt + 1) + get(i, nxt[i]);
    }

    void solve(){
        prepare();
        ll res = 0;
        for(int i = 1; i <= n; i++){
//            cout << i << ' ' << nxt[i] << '\n';
            res = max(res, sol(i, 0));
        }
        cout << res;
    }
}

void inp(){
    cin >> n >> num_barr >> rad;
    pos[1] = 1;
    for(int i = 1; i < n; i++){
        cin >> d[i];
        pos[i + 1] = pos[i] + d[i];
//        cout << pos[i] << '\n';
    }
    pos[n + 1] = oo;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
}

void solve(){
//    if(sub0::check()) return sub0::solve(), void();
    if(sub7::check()) return sub7::solve(), void();
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UwU      */


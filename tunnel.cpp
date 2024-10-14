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
#define file "tunnel"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , h[N];
vector <int> pos[N];
vector <int> adj[N];
int d[N];
pii D[N];
bool vst[N];

void prepare(){
    for(int i = 1 ; i <= n ; i++){
        pos[h[i]].pb(i);
    }
}

void bfs(){
    deque <int> dq;
    mem(d , 0x3f);
    d[n] = 0;
    for(int i = 1 ; i < n ; i++){
        if(h[i] == h[n]){
            dq.push_back(i);
            d[i] = 1;
        }
    }
    D[h[n]] = {0 , n};
    dq.push_front(n);
    vst[h[n]] = 1;

    while(dq.size()){
        int u = dq.front();
        // cout << u << ' ' << d[u] << '\n';
        dq.pop_front();
        if(h[u - 1] < h[u] && u > 1){
            if(!vst[h[u - 1]]){
                d[u - 1] = d[u];
                dq.push_front(u - 1);
                vst[h[u - 1]] = 1;
                for(auto j : pos[h[u - 1]]){
                    // cout << j << "gg\n";
                    if(j != u - 1){
                        dq.push_back(j);
                        d[j] = d[u] + 1;
                    }
                }
            }
            else{
                d[u - 1] = min(d[u - 1] , d[u]);
                D[h[u - 1]] = min(D[h[u - 1]] , {d[u] , u - 1});
            }
        }
    }
    // for(int i = 1 ; i <= n ; i++) cout << d[i] << '\n';
    cout << (d[1] <= n ? min(d[1] , D[h[1]].fi + (D[h[1]].se != 1)) : -1);
}

void inp(){
    cin >> n;
    int sz = 1;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        if(x != h[sz - 1] || sz == 1){
            h[sz] = x;
            // cout << h[sz] << ' ';
            sz++;
        }
    }
    n = sz - 1;
}

void solve(){
    prepare();
    bfs();
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
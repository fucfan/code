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
#define file "seq"
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

int n, q, a[N];

struct segment_tree{
    ll node[N << 2 | 1];

    void build(int id, int l, int r){
        if(l == r){
            int tmp = l;
            while(!(tmp & 1)){
                tmp /= 2;
            }
            node[id] = a[l] + a[tmp];
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);

        node[id] = node[id << 1] + node[id << 1 | 1];
    }

    void update(int id, int l, int r, int pos, int val){
        if(pos > r || l > pos) return;

        if(l == r){
            node[id] += val;
            return;
        }

        int mid = (l + r) >> 1;

        update(id << 1, l, mid, pos, val);
        update(id << 1 | 1, mid + 1, r, pos, val);

        node[id] = node[id << 1] + node[id << 1 | 1];
    }

    ll get(int id, int l, int r, int u, int v){
        if(u > r || l > v) return 0;

        if(u <= l && r <= v) return node[id];

        int mid = (l + r) >> 1;

        return get(id << 1, l, mid, u, v) +
               get(id << 1 | 1, mid + 1, r, u, v);
    }
} IT;

void update(int pos, int val){
    val -= a[pos];
    a[pos] += val;
    IT.update(1, 1, n, pos, val);

    if(pos & 1){    
        while(pos <= n){
            IT.update(1, 1, n, pos, val);
            pos *= 2;
        }
    }
}

void inp(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    IT.build(1, 1, n);
    for(int i = 1; i <= q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int pos, val;
            cin >> pos >> val;
            update(pos, val);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << IT.get(1, 1, n, l, r) << '\n';
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
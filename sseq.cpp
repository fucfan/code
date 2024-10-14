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
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "sseq"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

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

struct segment_tree{
    ll node[N << 2 | 1];
    ll lazy[N << 2 | 1];

    void down(int id){
        node[id << 1] += lazy[id];
        lazy[id << 1] += lazy[id]; 
        node[id << 1 | 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];

        lazy[id] = 0; 
    }

    void update(int id , int l , int r , int u , int v , int val){
        // cout << l << ' ' << r << ' ' << u << ' ' << v << '\n';
        if(u > r || l > v) return;
        if(u <= l && r <= v){
            node[id] += val;
            lazy[id] += val;
            return;
        }

        int mid = (l + r) >> 1;

        down(id);

        update(id << 1 , l , mid , u , v , val);
        update(id << 1 | 1 , mid + 1 , r , u , v , val);

        node[id] = max(node[id << 1] , node[id << 1 | 1]);
    }
} st;

int n , mx;

struct SEQ{
    int l , r;
    int w;

    void input(){
        cin >> l >> r >> w;
        mx = max(mx , r);
    }

    bool operator<(SEQ b){
        return l < b.l;
    }
} seq[N];

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) seq[i].input();
}

void solve(){
    sort(seq + 1 , seq + 1 + n);
    ll ans = 0;

    for(int i = n ; i >= 0 ; i--){
        if(seq[i].l != seq[i + 1].l) ans = max(ans , st.node[1]);
        st.update(1 , 1 , mx , seq[i].r , mx , seq[i].w);
        // cout << seq[i].l << ' ' << seq[i].r << ' ' << seq[i].w << ' ' << st.node[1] << '\n'; 
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
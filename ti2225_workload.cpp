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
#define file "workload"
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

int n , m;
pii a[N];
ll ans = 0;
vector <int> work[N];

bool cmp(pii a , pii b){
    return a.se < b.se;
}

struct segment_tree{
    pair <ll , int> node[N << 2 | 1];

    void build(int id , int l , int r){
        if(l == r){
            node[id] = {0 , l};
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1 , l , mid);
        build(id << 1 | 1 , mid + 1 , r);

        node[id] = min(node[id << 1] , node[id << 1 | 1]);
    }

    void update(int id , int l , int r , int pos , int val){
        if(pos < l || r < pos) return;

        if(l == r){
            node[id].fi += val;
            return;
        }

        int mid = (l + r) >> 1;

        update(id << 1 , l , mid , pos , val);
        update(id << 1 | 1 , mid + 1 , r , pos , val);

        node[id] = min(node[id << 1] , node[id << 1 | 1]);
    }
} ST;

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
}

void solve(){
    sort(a + 1 , a + 1 + m , greater<>());

    ST.build(1 , 1 , n);

    for(int i = 1 ; i <= m ; i++){
        pair <ll , int> tmp = ST.node[1];

        work[tmp.se].pb(a[i].se);

        ST.update(1 , 1 , n , tmp.se , a[i].fi);
    }

    sort(a + 1 , a + 1 + m , cmp);

    for(int i = 1 ; i <= n ; i++){
        ll sum = 0;
        for(auto j : work[i]){
            sum += a[j].fi;
        }
        ans = max(ans , sum);
    }

    cout << ans << '\n';

    for(int i = 1 ; i <= n ; i++){
        cout << work[i].size() << ' ';
        for(auto j : work[i]) cout << j << ' ';
        nl;
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

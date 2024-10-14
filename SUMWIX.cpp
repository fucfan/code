#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "sumwix"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

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

int n , a[N];
pii rmq[N][LOG + 5];
int lg2[N];
ll suf[N] , ans;

struct segment_tree{
    ll node[4 * N];
    int lazy[4 * N];

    segment_tree() {mem(lazy , -1);}

    void down(int id , int l , int r){
        if(lazy[id] == -1) return;

        int mid = (l + r) >> 1;

        node[id << 1] = (1ll * lazy[id] * (mid - l + 1)) % mod;
        lazy[id << 1] = lazy[id];
        node[id << 1 | 1] = (1ll * lazy[id] * (r - mid)) % mod;
        lazy[id << 1 | 1] = lazy[id];

        lazy[id] = -1;
    }

    void update(int id , int l , int r , int u , int v , int val){
        if(u > r || l > v) return;

        if(u <= l && r <= v){
            node[id] = (1ll * val * (r - l + 1)) % mod;
            lazy[id] = val;
            return;
        }

        int mid = (l + r) >> 1;

        down(id , l , r);

        update(id << 1 , l , mid , u , v , val);
        update(id << 1 | 1 , mid + 1 , r , u , v , val);

        node[id] = add(node[id << 1] , node[id << 1 | 1]);
    }

    ll get(int id , int l , int r , int u , int v){
        if(u > r || l > v) return 0;

        if(u <= l && r <= v){
            // cout << l << ' ' << r << ' ' << node[id] << '\n';
            return node[id];
        }

        int mid = (l + r) >> 1;

        down(id , l , r);

        ll val1 = get(id << 1 , l , mid , u , v);
        ll val2 = get(id << 1 | 1 , mid + 1 , r , u , v);

        return add(val1 , val2);
    }
} ST;

int get_max(int l , int r){
    int length = lg2[r - l + 1];
    return max(rmq[l][length].fi , rmq[r - (1 << length) + 1][length].fi);
}

int get_min(int l , int r){
    int length = lg2[r - l + 1];
    return min(rmq[l][length].se , rmq[r - (1 << length) + 1][length].se);
}

void prepare(){
    for(int i = 1 ; i <= n ; i++) rmq[i][0] = {a[i] , a[i]};

    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i + (1 << (j - 1)) <= n ; i++){
            rmq[i][j].fi = max(rmq[i][j - 1].fi , rmq[i + (1 << (j - 1))][j - 1].fi);
            rmq[i][j].se = min(rmq[i][j - 1].se , rmq[i + (1 << (j - 1))][j - 1].se);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        while((1 << lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){
    prepare();
    for(int i = n ; i >= 1 ; i--){
        int l = i , r = n;
        int pos = i;

        while(l <= r){
            int mid = (l + r) >> 1;

            if(get_min(i , mid) == a[i]){
                pos = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        ST.update(1 , 1 , n , i , pos , a[i]);
        ll val = ST.get(1 , 1 , n , i , n);
        suf[i] = add(suf[i + 1] , val);
    }
    
    for(int i = 1 ; i <= n ; i++){
        int l = 1 , r = i;
        int pos = i;

        while(l <= r){
            int mid = (l + r) >> 1;

            if(get_max(mid , i) == a[i]){
                pos = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        ST.update(1 , 1 , n , pos , i , a[i]);

        ll val = ST.get(1 , 1 , n , 1 , i);

        ans = add(ans , (val * suf[i + 1]) % mod);
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
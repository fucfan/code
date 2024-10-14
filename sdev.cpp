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
#define file "sdev"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
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

int n;
ll k;
int cur;

struct RECT{
    int l , r , b , t;

    void input(){
        cin >> l >> b >> r >> t;
    }
} rect[N];

namespace sub1{
    bool check(){
        for(int i = 1 ; i <= n ; i++){
            if(rect[i].r > 1000 || rect[i].t > 1000) return 0;
        }
        return (n <= 100);
    }

    bool grid[1001][1001];

    void solve(){
        vector <int> pos;
        for(int i = 1 ; i <= n ; i++){
            int l = rect[i].l;
            int r = rect[i].r;
            int b = rect[i].b;
            int t = rect[i].t;
            for(int x = l ; x <= r ; x++){
                for(int y = b ; y <= t ; y++){
                    if(!grid[x][y]) pos.pb(x + y);
                    grid[x][y] = 1;
                }
            }
        }

        sort(all(pos));

        cout << pos[k - 1];
    }
}

namespace sub2{
    bool check(){
        return (n <= 15);
    }

    ll countArea(ll cur_l , ll cur_b , ll cur_r , ll cur_t , ll s){
        ll cnt = 0;

        if(cur_l == -1 || cur_r == -1 || cur_t == -1 || cur_b == -1) return 0;

        ll sz = min(cur_r - cur_l + 1 , cur_t - cur_b + 1);

        if(s >= cur_l + cur_b){
            if(s <= sz + cur_l + cur_b - 1){
                ll tmp = s - cur_l - cur_b + 1;
                cnt += 1ll * (tmp + 1) * tmp / 2;
            }
            else if(sz + cur_l + cur_b <= s && s <= cur_r + cur_t - sz + 1){
                // cout << s << "gg\n";
                ll tmp = sz;
                cnt += (1ll * (tmp + 1) * tmp / 2 + sz * (s - (sz + cur_l + cur_b - 1)));
            }
            else if(cur_r + cur_t - sz + 1 < s && s <= cur_t + cur_r){
                ll tmp = cur_r + cur_t - s;
                cnt += (1ll * (cur_r - cur_l + 1) * (cur_t - cur_b + 1) - 1ll * (tmp + 1) * tmp / 2);
            }
            else if(s > cur_t + cur_r) 
                cnt += 1ll * (cur_r - cur_l + 1) * (cur_t - cur_b + 1);
        }

        return cnt;
    }

    void solve(){
        int lef = 1;
        int rig = oo;
        int ans = rig;
        while(lef <= rig){
            int mid = (lef + rig) >> 1;

            ll cnt = 0;

            for(int mask = 1 ; mask < (1 << n) ; mask++){
                int cur_l = 0;
                int cur_r = oo;
                int cur_b = 0;
                int cur_t = oo;

                for(int i = 0 ; i < n ; i++){
                    if(BIT(mask , i)){
                        int l = rect[i + 1].l;
                        int r = rect[i + 1].r;
                        int b = rect[i + 1].b;
                        int t = rect[i + 1].t;
                        cur_l = max(cur_l , l);
                        cur_r = min(cur_r , r);
                        cur_b = max(cur_b , b);
                        cur_t = min(cur_t , t);
                        
                        if(cur_l > cur_r || cur_b > cur_t){
                            cur_l = cur_b = -1;
                            cur_r = cur_t = -1;
                            break;
                        }
                        // cout << cur
                        // if(mid == 10){
                        //     cout << l << ' ' << b << ' ' << r << ' ' << t << '\n';
                        // }
                    }
                }
                // assert(cur_l != 0 && cur_b != 0);

                cnt += countArea(cur_l , cur_b , cur_r , cur_t , mid) * ((__builtin_popcount(mask) & 1) ? 1 : -1);

                // if(mid == 10){
                //     for(int j = 0 ; j < n ; j++) cout << BIT(mask , j);
                //     cout << ' ' << cur_l << ' ' << cur_b << ' ' << cur_r << ' ' << cur_t << '\n';
                //     cout << sz << ' ' << cnt << '\n';
                // }
            }

            // cout << mid << ' ' << cnt << '\n';

            if(cnt >= k){
                rig = mid - 1;
                ans = mid;
            }
            else{
                lef = mid + 1;
            }
        }

        cout << ans;
    }
}

namespace sub3{
    bool check(){
        return (n <= 1000);
    }

    ll countArea(ll cur_l , ll cur_b , ll cur_r , ll cur_t , ll s){
        ll cnt = 0;

        if(cur_l == -1 || cur_r == -1 || cur_t == -1 || cur_b == -1) return 0;

        ll sz = min(cur_r - cur_l + 1 , cur_t - cur_b + 1);

        if(s >= cur_l + cur_b){
            if(s <= sz + cur_l + cur_b - 1){
                ll tmp = s - cur_l - cur_b + 1;
                cnt += 1ll * (tmp + 1) * tmp / 2;
            }
            else if(sz + cur_l + cur_b <= s && s <= cur_r + cur_t - sz + 1){
                // cout << s << "gg\n";
                ll tmp = sz;
                cnt += (1ll * (tmp + 1) * tmp / 2 + sz * (s - (sz + cur_l + cur_b - 1)));
            }
            else if(cur_r + cur_t - sz + 1 < s && s <= cur_t + cur_r){
                ll tmp = cur_r + cur_t - s;
                cnt += (1ll * (cur_r - cur_l + 1) * (cur_t - cur_b + 1) - 1ll * (tmp + 1) * tmp / 2);
            }
            else if(s > cur_t + cur_r) 
                cnt += 1ll * (cur_r - cur_l + 1) * (cur_t - cur_b + 1);
        }

        return cnt;
    }

    vector <int> compress_x , compress_y;
    int grid[4001][4001];

    void prepare(){
        for(int i = 1 ; i <= n ; i++){
            compress_x.pb(rect[i].l);
            compress_x.pb(rect[i].r + 1);
            compress_y.pb(rect[i].b);
            compress_y.pb(rect[i].t + 1);
        }
        compress_x.pb(oo);
        compress_y.pb(oo);
        sort(all(compress_x));
        compress_x.erase(unique(all(compress_x)) , compress_x.end());
        sort(all(compress_y));
        compress_y.erase(unique(all(compress_y)) , compress_y.end());
    }

    void solve(){
        prepare();
        int sz_x = compress_x.size() - 1;
        int sz_y = compress_y.size() - 1;
        for(int i = 1 ; i <= n ; i++){
            int l = lower_bound(all(compress_x) , rect[i].l) - compress_x.begin() + 1;
            int r = upper_bound(all(compress_x) , rect[i].r) - compress_x.begin();
            int b = lower_bound(all(compress_y) , rect[i].b) - compress_y.begin() + 1;
            int t = upper_bound(all(compress_y) , rect[i].t) - compress_y.begin();

            // cout << l << ' ' << b << ' ' << r << ' ' << t << '\n';

            grid[l][b]++;
            grid[l][t + 1]--;
            grid[r + 1][b]--;
            grid[r + 1][t + 1]++;
        }

        for(int i = 1 ; i <= sz_x ; i++){
            for(int j = 1 ; j <= sz_y ; j++){
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            }
        }

        int lef = 1;
        int rig = oo;
        int ans = oo;

        while(lef <= rig){
            int mid = (lef + rig) >> 1;
            ll cnt = 0;

            for(int i = 1 ; i <= sz_x ; i++){
                for(int j = 1 ; j <= sz_y ; j++){
                    if(grid[i][j])
                        cnt += countArea(compress_x[i - 1] , compress_y[j - 1] , compress_x[i] - 1 , compress_y[j] - 1 , mid);
                }
            }

            // cout << mid << ' ' << cnt << '\n';

            if(cnt >= k){
                rig = mid - 1;
                ans = mid;
            }
            else lef = mid + 1;
        }

        cout << ans;
    }
}

namespace sub4{
    bool check(){
        for(int i = 1 ; i <= n ; i++){
            if(rect[i].l > N) return 0;
            if(rect[i].r > N) return 0;
            if(rect[i].b > N) return 0;
            if(rect[i].t > N) return 0;
        }
        return 1;
    }

    struct segment_tree{
        pair <int , ll> node[N << 2 | 1];
        int lazy[N << 2 | 1];

        void down(int id , int l , int r){
            int mid = (l + r) >> 1;
            
            node[id << 1].fi += lazy[id];
            lazy[id << 1] += lazy[id];
            node[id << 1 | 1].fi += lazy[id]; 
            lazy[id << 1 | 1] += lazy[id];

            lazy[id] = 0;
        }

        void merge(int id){
            // int mid = (l + r) >> 1;
            if(node[id << 1].fi > node[id << 1 | 1].fi){
                node[id] = node[id << 1 | 1];
            }
            
            if(node[id << 1].fi < node[id << 1 | 1].fi){
                node[id] = node[id << 1];
            }
            
            if(node[id << 1].fi == node[id << 1 | 1].fi){
                node[id] = {node[id << 1].fi , node[id << 1].se + node[id << 1 | 1].se}; 
            }
        }

        void build(int id , int l , int r){
            lazy[id] = 0;
            if(l == r){
                node[id].fi = 0;
                node[id].se = 1;
                // cout << compress[r] << ' ' << compress[l - 1] << ' ' << node[id].se << "pp\n";
                return;
            }

            int mid = (l + r) >> 1;

            build(id << 1 , l , mid);
            build(id << 1 | 1 , mid + 1 , r);

            merge(id);
        }

        void update(int id , int l , int r , int u , int v , int val){
            if(u > r || l > v) return;

            if(u <= l && r <= v){
                node[id].fi += val;
                lazy[id] += val;
                // if(cur == 7) cout << l << ' ' << r << ' ' << node[id].fi << ' ' << node[id].se << '\n';
                return;
            }

            int mid = (l + r) >> 1;

            down(id , l , r);

            update(id << 1 , l , mid , u , v , val);
            update(id << 1 | 1 , mid + 1 , r , u , v , val);

            merge(id);

            // if(cur == 7) cout << l << ' ' << r << ' ' << node[id].fi << ' ' << node[id].se << '\n';
        }

        ll get(int id , int l , int r , int u , int v){
            if(u > r || l > v) return 0;

            // cout << l << ' ' << r << ' ' << node[id].fi << ' ' << node[id].se << "kk\n";

            if(node[id].fi) return 0;

            if(u <= l && r <= v){
                // cout << l << ' ' << r << ' ' << node[id].se << "ff\n";
                return node[id].se;
            }

            int mid = (l + r) >> 1;

            down(id , l , r);

            return get(id << 1 , l , mid , u , v) +
                   get(id << 1 | 1 , mid + 1 , r , u , v);
        }
    } st;

    struct SEG{
        int pos;
        int type;
        int b , t;

        bool operator<(SEG b){
            return pos < b.pos;
        }
    };

    vector <SEG> event;

    void prepare(){
        for(int i = 1 ; i <= n ; i++){
            int l = rect[i].l;
            int r = rect[i].r;
            int b = rect[i].b;
            int t = rect[i].t;
            event.pb({l , 1 , b , t});
            event.pb({r + 1 , -1 , b , t});
        }

        sort(all(event));
    }

    void solve(){
        prepare();
        int sz = N;

        int lef = 1;
        int rig = oo;
        int ans = oo; 

        // cout << st.node[1].fi << ' ' << st.node[1].se << '\n';

        while(lef <= rig){
            st.build(1 , 1 , sz);
            int mid = (lef + rig) >> 1;
            cur = mid;
            ll cnt = 0;

            int j = 1;

            for(int i = 0 ; i < event.size() ; i++){
                // if(mid == 6) cout << i << ' ' << event[i].pos << ' ' << j << '\n';
                if(event[i].pos <= j){
                    st.update(1 , 1 , sz , event[i].b , event[i].t , event[i].type);
                }
                else{
                    while(j < event[i].pos){
                        int pos = mid - j;
                        if(pos > 0) cnt += pos - st.get(1 , 1 , sz , 1 , pos);
                        // if(mid == 6) cout << pos << ' ' << j << ' ' << pos - st.get(1 , 1 , sz , 1 , pos)<< "ggg\n";
                        j++;
                    }
                    st.update(1 , 1 , sz , event[i].b , event[i].t , event[i].type);
                }
            }

            if(cnt >= k){
                rig = mid - 1;
                ans = mid;
            }
            else lef = mid + 1;

            // if(mid == 5) cout << cnt << '\n';
        }

        cout << ans << '\n';

        // for(auto j : event){
        //     cout << j.b << ' ' << j.t << ' ' << j.pos << ' ' << j.type << '\n';
        // }
    }
}

void inp(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++) rect[i].input();
}

void solve(){
    if(sub1::check()) return sub1::solve();
    if(sub2::check()) return sub2::solve();
    if(sub3::check()) return sub3::solve();
    if(sub4::check()) return sub4::solve();
    assert(0 > 1);
}

main(){
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
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
const int N = 1e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}
struct Query{
    int l, r, id;

    void input(int num){
        cin >> l >> r;
        id = num;
    }

    bool operator<(Query b){
        return (l < b.l);
    }

    bool operator>(Query b){
        return (r < b.r);
    }
} query[N];

int n, a[N], q, cnt[N];
vector <Query> block[500];
int num_block;
ll res[N];

void prepare(){
    sort(query + 1, query + 1 + q);

    int tmp = sqrt(n);

    for(int i = 1; i <= q; i++){
        int l = query[i].l;
        int r = query[i].r;
        if(tmp < l){
            while(tmp < l){
                tmp += sqrt(n);
            }
            num_block++;
        }
        block[num_block].pb(query[i]);
    }
}

ll get(int a, int b){
    return abs(1ll * a * a - 1ll * b * b);
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for(int i = 1; i <= q; i++){
        query[i].input(i);
    }
}

void solve(){
    prepare();
    int lef = 0;
    int rig = 0;
    ll ans = 0;
    for(int i = 0; i <= num_block; i++){
        sort(all(block[i]), greater<>());
        if(i & 1) reverse(all(block[i]));
        for(auto j : block[i]){
            while(lef > j.l){
                lef--;  
                cnt[a[lef]]++;
                if(cnt[a[lef]] == 1) ans++;
            }
            while(lef < j.l){
                if(cnt[a[lef]] == 1) ans--;
                cnt[a[lef]]--;
                lef++;
            }
            while(rig < j.r){
                rig++;
                cnt[a[rig]]++;
                if(cnt[a[rig]] == 1) ans++;
            }   
            while(rig > j.r){
                if(cnt[a[rig]] == 1) ans--;
                cnt[a[rig]]--;
                rig--;
            }

            // cout << j.l << ' ' << j.r << ' ' << ans << '\n';
            // for(int p = 1; p <= n; p++) cout << cnt[p] << ' ';
            // nl;

            res[j.id] = ans;
        }
    }
    for(int i = 1; i <= q; i++){
        cout << res[i] << '\n';
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
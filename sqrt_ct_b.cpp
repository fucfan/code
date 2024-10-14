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

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct seg{
    int l, r, id, type;

    bool operator<(seg b){
        return (l < b.l);
    }

    bool operator>(seg b){
        return (r < b.r);
    }
} s[N];

struct Query{
    int l1, r1, l2, r2;

    void input(){
        cin >> l1 >> r1 >> l2 >> r2;
    }
} query[N];

int n, a[N], q, cnt[N][2];
vector <seg> block[250];
int num_block;
ll res[N][4];

void prepare(){
    for(int i = 1; i <= q; i++){
        int l1 = query[i].l1;
        int r1 = query[i].r1;
        int l2 = query[i].l2;
        int r2 = query[i].r2;
        s[i] = {l1 - 1, l2 - 1, i, 0};
        s[i + q] = {r1, r2, i, 1};
        s[i + q + q] = {l1 - 1, r2, i, 2};
        s[i + q + q + q] = {l2 - 1, r1, i, 3};
    }

    int tmp = sqrt(n);

    sort(s + 1, s + 1 + 4 * q);
    for(int i = 1; i <= 4 * q; i++){
        if(tmp < s[i].l){
            while(tmp < s[i].l){
                tmp += sqrt(n);
            }
            num_block++;
        }
        block[num_block].pb(s[i]);
    }
}

void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for(int i = 1; i <= q; i++){
        query[i].input();
    }
}

void solve(){
    prepare();
    int lef = 0;
    int rig = 0;
    ll ans = 1;
    cnt[0][0] = cnt[0][1] = 1;
    for(int i = 0; i <= num_block; i++){
        sort(all(block[i]), greater<>());
        if(i & 1) reverse(all(block[i]));
        for(auto j : block[i]){
            while(lef < j.l){
                lef++;
                cnt[a[lef]][0]++;
                ans += cnt[a[lef]][1];
            }
            while(lef > j.l){
                cnt[a[lef]][0]--;
                ans -= cnt[a[lef]][1];
                lef--;
            }
            while(rig > j.r){
                cnt[a[rig]][1]--;
                ans -= cnt[a[rig]][0];
                rig--;
            }
            while(rig < j.r){
                rig++;
                cnt[a[rig]][1]++;
                ans += cnt[a[rig]][0];
            }   

            // cout << j.l << ' ' << j.r << ' ' << ans << '\n';
            // for(int p = 0; p <= n; p++) cout << cnt[p][0] << " \n"[p == n];
            // for(int p = 0; p <= n; p++) cout << cnt[p][1] << " \n"[p == n];

            res[j.id][j.type] = ans;
        }
    }
    for(int i = 1; i <= q; i++){
        cout << res[i][1] - res[i][2] - res[i][3] + res[i][0] << '\n';
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
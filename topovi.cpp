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

int n, k, p, row[N], col[N];
vector <int> compress_x, compress_y;
multiset <int> num_x, num_y;
map<pii, int> mp;
ll res;

struct DA_ROOK{
    int x, y, p;

    void input(){
        cin >> x >> y >> p;
    }
} r[N];

struct Query{
    int x1, y1, x2, y2;

    void input(){
        cin >> x1 >> y1 >> x2 >> y2;
    }
} query[N];

void prepare(){
    res = 1ll * n * n;
    for(int i = 1; i <= n; i++){
        compress_x.pb(r[i].x);
        compress_y.pb(r[i].y);
    }
    for(int i = 1; i <= p; i++){
        compress_x.pb(query[i].x1);
        compress_y.pb(query[i].y1);
        compress_x.pb(query[i].x2);
        compress_y.pb(query[i].y2);
    }

    sort(all(compress_x));
    compress_x.erase(unique(all(compress_x)), compress_x.end());
    sort(all(compress_y));
    compress_y.erase(unique(all(compress_y)), compress_y.end());

    for(int i = 1; i <= n; i++){
        r[i].x = lower_bound(all(compress_x), r[i].x) - compress_x.begin() + 1;
        r[i].y = lower_bound(all(compress_y), r[i].y) - compress_y.begin() + 1;
        mp[{r[i].x, r[i].y}] = r[i].p;
        row[r[i].x] ^= r[i].p;
        col[r[i].y] ^= r[i].p;
    }

    int cnt1, cnt2;
    cnt1 = cnt2 = 0;

    for(int j = 0; j < compress_x.size(); j++){
        num_x.insert(row[j + 1]);
        if(row[j + 1]) res -= n;
        else cnt1++;
    }
    for(int j = 0; j < compress_y.size(); j++){
        num_y.insert(col[j + 1]);
        if(col[j + 1]) res -= n;
        else cnt2++;
    }

    res += 1ll * num_x.size() * num_y.size();
    res -= 1ll * cnt1 * n + 1ll * cnt2 * n;
    res += 1ll * cnt1 * cnt2;

    for(int j = 0; j < compress_x.size(); j++){
        res += num_y.count(row[j + 1]);
    }

    for(int i = 1; i <= p; i++){
        query[i].x1 = lower_bound(all(compress_x), query[i].x1) - compress_x.begin() + 1;
        query[i].y1 = lower_bound(all(compress_y), query[i].y1) - compress_y.begin() + 1;
        query[i].x2 = lower_bound(all(compress_x), query[i].x2) - compress_x.begin() + 1;
        query[i].y2 = lower_bound(all(compress_y), query[i].y2) - compress_y.begin() + 1;
    }
}

void update(int x, int y, int val){
    cout << x << ' ' << y << '\n';
    cout << "////////////////\n";
        for(auto j : num_x) cout << j << ' ';
        nl;
        for(auto j : num_y) cout << j << ' ';
        nl;

    cout << "////////////////\n";
    cout << res << ' ' << row[x] << ' ' << col[y] << "kk\n";
    if(row[x]) res -= num_y.count(row[x]) - (n - ((int)num_y.size() - num_y.count(0)));
    else res -= n - ((int)num_y.size() - num_y.count(row[x]));

    if(col[y]) res -= num_x.count(col[y]) - (n - ((int)num_x.size() - num_x.count(0)));
    else res -= n - ((int)num_x.size() - num_x.count(col[y]));
    
    // res += 2 * (row[x] == col[y]);

    cout << res << ' ' << row[x] << ' ' << col[y] << "gg\n";

    auto j = num_y.find(row[x]);
    if(j != num_y.end()) num_y.erase(j);
    j = num_x.find(col[y]);
    if(j != num_x.end()) num_x.erase(j);
    int tmp = mp[{x, y}];
    mp[{x, y}] = val;
    cout << x << ' ' << y << ' ' << row[x] << ' '<< col[y] << '\n';
    col[y] ^= tmp;
    row[x] ^= tmp;
    col[y] ^= val;
    row[x] ^= val;

    cout << x << ' ' << y << ' ' << row[x] << ' '<< col[y] << '\n';
    num_x.insert(row[x]);
    num_y.insert(col[y]);
    cout << "--------------\n";
        for(auto j : num_x) cout << j << ' ';
        nl;
        for(auto j : num_y) cout << j << ' ';
        nl;

    cout << "--------------\n";
    
    if(row[x]) res += num_y.count(row[x]) - (n - ((int)num_y.size() - num_y.count(0)));
    else res += n - ((int)num_y.size() - num_y.count(0));
    if(col[y]) res += num_x.count(col[y]) - (n - ((int)num_x.size() - num_x.count(0)));
    else res += n - ((int)num_x.size() - num_x.count(0));

    // res -= 2 * (col[y] == row[x]); 
    cout << res << "hh\n";
}

void inp(){
    cin >> n >> k >> p;
    for(int i = 1; i <= k; i++){
        r[i].input();
    }
    for(int i = 1; i <= p; i++) query[i].input();
}

void solve(){
    prepare();
    // cout << res << ' ';
    for(int i = 1; i <= p; i++){
        int x1 = query[i].x1;
        int y1 = query[i].y1;
        int x2 = query[i].x2;
        int y2 = query[i].y2;

        update(x2, y2, mp[{x1, y1}]);
        update(x1, y1, 0);
        // for(auto j : num_x) cout << j << ' ';
        // nl;
        // for(auto j : num_y) cout << j << ' ';
        // nl;

        cout << 1ll * n * n - res << ' ';
    }
    // cout << "gg\n";
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
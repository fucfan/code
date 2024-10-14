#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "test"
// #define int ll
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const ll mod = 998244353;
const int N = 2e6 + 5;
const int LOG = 20;

int n , subtask , q , st[N] , en[N] , sz;
ll lazy1[N], lazy[N] , tree[N] , tree1[N] , pref[N] , h[N];
vector<int> tour , adj[N];

void dfs(int i , int p){
    // cout << i << '\n';
    tour.pb(i); 
    st[i] = tour.size() - 1;
    for(auto j : adj[i]){
        if(j == p) continue;
        h[j] = h[i] + 1;
        dfs(j , i);
    }
    en[i] = tour.size() - 1;
}

void down(int id , ll l , ll r){
    ll mid = (l + r) >> 1;

    ll val = lazy1[id];

    if(!lazy[id] && !lazy1[id]) return;

    // cout << pref[mid] - pref[l - 1] << '\n';
    // cout << l << ' ' << mid << ' ' << r << ' ' << val << ' ' << val1 << ' ' << tree[id << 1] << ' ' << tree1[id << 1] << '\n';
    // cout << lazy[id] << ' ' << lazy1[id].fi << ' ' << lazy1[id].se << '\n';
    // nl;
    // cout << "gg\n";

    (tree1[id << 1] += (((pref[mid] - pref[l - 1] + mod * mod) % mod) * val) % mod) %= mod;
    (tree1[id << 1 | 1] += (((pref[r] - pref[mid] + mod * mod) % mod) * val) % mod) %= mod;

    (tree[id << 1] += ((mid - l + 1) * lazy[id]) % mod) %= mod;
    (lazy[id << 1] += lazy[id]) %= mod; 
    (tree[id << 1 | 1] += ((r - mid) * lazy[id]) % mod) %= mod;
    (lazy[id << 1 | 1] += lazy[id]) %= mod; 

    (lazy1[id << 1] += val) %= mod;
    (lazy1[id << 1 | 1] += val) %= mod;

    // cout << pref[mid] - pref[l - 1] << '\n';
    // cout << l << ' ' << mid << ' ' << r << ' ' << val << ' ' << val1 << ' ' << tree[id << 1] << ' ' << tree1[id << 1] << '\n';
    // cout << lazy[id] << ' ' << lazy1[id].fi << ' ' << lazy1[id].se << '\n';
    
    lazy1[id] = 0;
    lazy[id] = 0;
}

void update1(int id , int l , int r , int u , int v , ll val){  
    if(u > r || l > v) return;
    if(u <= l && r <= v){
        (tree1[id] += (((pref[r] - pref[l - 1] + mod * mod) % mod) * val) % mod) %= mod;
        (lazy1[id] += val) %= mod;
        // cout << l << ' ' << r << ' ' << val << ' ' << val1 << ' ' << (pref[r] - pref[l - 1]) << ' ' << tree1[id] << "ee\n";
        return;
    }
    int mid = (l + r) >> 1;
    down(id , l , r);
    update1(id << 1 , l , mid , u , v , val);
    update1(id << 1 | 1 , mid + 1 , r , u , v , val);
    tree1[id] = (tree1[id << 1] + tree1[id << 1 | 1]) % mod;
}

void update(int id , ll l , ll r , int u , int v , ll val){
    if(u > r || l > v) return;
    if(u <= l && r <= v){
        (tree[id] += ((r - l + 1) * val) % mod) %= mod;
        (lazy[id] += val) %= mod;
        return;
    }
    int mid = (l + r) >> 1;
    down(id , l , r);
    update(id << 1 , l , mid , u , v , val);
    update(id << 1 | 1 , mid + 1 , r , u , v , val);
    tree[id] = (tree[id << 1] + tree[id << 1 | 1]) % mod;
}

ll get(int id , int l , int r , int u , int v){
    if(u > r || l > v) return 0;
    if(u <= l && r <= v){
        // cout << l << ' ' << r << ' ' << tree[id] << ' ' << tree1[id] << "gg\n";
        return (tree[id] + tree1[id]) % mod;
    }
    int mid = (l + r) >> 1;
    down(id , l , r);
    return (get(id << 1 , l , mid , u , v) + get(id << 1 | 1 , mid + 1 , r , u , v)) % mod;
}

void inp()
{
    cin >> subtask;
    cin >> n;
    for(int i = 2 ; i <= n ; i++){
        int p;
        cin >> p;
        // cout << i << ' ' << p << '\n';
        adj[i].pb(p);
        adj[p].pb(i);
    }
    tour.pb(0);
    dfs(1 , 0);
    sz = tour.size() - 1;
    // for(auto j : tour) cout << j << ' ';
    //     nl;
    for(int i = 1 ; i <= n ; i++){
        pref[i] = (pref[i - 1] - h[tour[i]] + mod * mod) % mod;
        // cout << i << ' ' << h[tour[i]] << "gg\n";
    }
    // nl;
    // for(int i = 1 ; i <= n ; i++){
    //  cout << i << ' ' << pref[i] << '\n';
    // }
    // cin >> q;
    // for(int i = 1 ; i <= n ; i++){
    //  cout << i << ' ' << h[i] << '\n';
    // }
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        string type;
        cin >> type;
        // cout << type << '\n';
        if(type == "add"){
            ll pos , k , l;
            cin >> pos >> k >> l;
            (k += mod * mod) %= mod;
            (l += mod * mod) %= mod;
            // cout << st[pos] << ' ' << en[pos] << "gg\n";
            update(1 , 1 , n , st[pos] , en[pos] , k);
            update(1 , 1 , n , st[pos] , en[pos] , (h[pos] * l) % mod);
            update1(1 , 1 , n , st[pos] , en[pos] , l);
        }
        if(type == "get"){
            int pos;
            cin >> pos;
            cout << get(1 , 1 , n , st[pos] , st[pos]) << ' ';
        }
        if(type == "sum"){
            int pos;
            cin >> pos;
            cout << get(1 , 1 , n , st[pos] , en[pos]) << ' ';
        }
    }
}

void solve()
{

}

void run_with_file()
{
    if (fopen(file".inp", "r"))
    {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
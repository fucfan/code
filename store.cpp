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
#define file "store"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

struct Query{
    int type , x;
    ll y;
} query[N];

int n , q;
ll a[N] , tree[N] , tree1[N] , lazy[N];

void update_sub1(int pos , ll val){
    for(int i = 1 ; i <= pos ; i++) a[i] = max(a[i] , val);
}

int get_sub1(int st , ll money){
    int res = 0;
    for(int i = st ; i <= n ; i++){
        if(money >= a[i]){
            money -= a[i];
            res++;
        }
    }
    return res;
}

void sub1(){
    for(int i = 1 ; i <= q ; i++){
        int type = query[i].type;
        int x = query[i].x;
        ll y = query[i].y;
        if(type == 1) update_sub1(x , y);
        if(type == 2) cout << get_sub1(x , y) << '\n';
    }
}

void down(int id , int l , int r){
    int mid = (l + r) >> 1;
    if(!lazy[id]) return;
    tree[id << 1] = max(tree[id << 1] , lazy[id] * (mid - l + 1));
    tree[id << 1 | 1] = max(tree[id << 1 | 1] , lazy[id] * (r - mid));
    tree1[id << 1] = max(tree1[id << 1] , lazy[id]);
    tree1[id << 1 | 1] = max(tree1[id << 1 | 1] , lazy[id]);
    lazy[id << 1] = max(lazy[id] , lazy[id << 1]);
    lazy[id << 1 | 1] = max(lazy[id] , lazy[id << 1 | 1 ]);
    lazy[id] = 0;
}

void build(int id , int l , int r){
    if(l == r){
        tree[id] = a[l];
        tree1[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
    tree1[id] = min(tree1[id << 1] , tree1[id << 1 | 1]);
    // cout << l << ' ' << r << ' ' << tree[id] << ' ' << tree1[id] << '\n';
}

void update(int id , int l , int r , int u , int v , ll val){
    if(u > v) return;
    if(l > v || u > r) return;
    if(u <= l && r <= v){
        tree[id] = max(tree[id] , val * (1ll * r - l + 1));
        tree1[id] = max(tree1[id] , val);
        lazy[id] = max(lazy[id] , val);
        return;
    }
    int mid = (l + r) >> 1;
    down(id , l , r);
    update(id << 1 , l , mid , u , v , val);
    update(id << 1 | 1 , mid + 1 , r , u , v , val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
    tree1[id] = min(tree1[id << 1] , tree1[id << 1 | 1]);
}

int find(int id , int l , int r , int u , int v , ll k){
    if(l > v || u > r) return -1;
    if(tree1[id] > k) return -1;
    if(l == r) return r;
    int mid = (l + r) >> 1; 
    int res = -1;
    down(id , l , r);
    res = find(id << 1 , l , mid , u , v , k);
    if(res == -1) res = find(id << 1 | 1 , mid + 1 , r , u , v , k);
    return res;
}

ll get1(int id , int l , int r , int u , int v){
    if(u > v) return 0;
    if(u > r || v < l) return 0;
    if(u <= l && r <= v) return tree[id];
    int mid = (l + r) >> 1;
    down(id , l , r);
    return get1(id << 1 , l , mid , u , v) + get1(id << 1 | 1 , mid + 1 , r , u , v);
}

int get(int id , int l , int r , int u , int v , ll k){
    // cout << u << ' ' << v << ' ' << tree[id] << '\n';
    // cout << l << ' ' << r << ' ' << k << ' ' << tree[id << 1] << ' ' << tree[id << 1 | 1] << '\n';
    if(l > v || u > r) return 0;
    int mid = (l + r) >> 1;
    if(l == r){
        if(k >= tree[id]) return 1;
        return 0;
    }
    down(id , l , r);
    ll val = get1(1 , 1 , n , u , mid);
    // cout << val << '\n';
    if(val <= k) 
        return max(0 , mid - u + 1) + get(id << 1 | 1 , mid + 1 , r , max(mid + 1 , u) , v , k - val);
    else return get(id << 1 , l , mid , u , v , k);
}



void sub2(){
    build(1 , 1 , n);
    for(int i = 1 ; i <= q ; i++){
        int type = query[i].type;
        int x = query[i].x;
        ll y = query[i].y;
        // for(int i = 1 ; i <= n ; i++){
        //     cout << get1(1 , 1 , n , i) << ' ';
        // }
        // nl;
        if(type == 1){
            int pos = find(1 , 1 , n , 1 , x , y);
            if(pos != -1) update(1 , 1 , n , pos , x , y);
        }
        if(type == 2){
            int pos = find(1 , 1 , n , x , n , y);
            // cout << pos << '\n';
            if(pos == -1) cout << 0 << '\n';
            else cout << get(1 , 1 , n , pos , n , y) << '\n';
        }
    }
}   

void inp()
{
    cin >> n;
    bool check = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i] != (1ll << (63 - __builtin_clzll(a[i])))) check = 1;
    }
    // sort(a + 1 , a + 1 + n);
    // reverse(a + 1 , a + 1 + n);
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int type , x;
        ll y;
        cin >> type >> x >> y;
        if(a[i] != (1ll << (63 - __builtin_clzll(y)))) check = 1;
        query[i] = {type , x , y};
    }
    if(check) sub1();
    else sub2();
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

int main()
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
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "snow_wh"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int q , n;
ll a[N];
pair <ll , pii> tree[N * 4];
void build(int id , int l , int r){
    if(l == r){
        tree[id] = {a[l] , {a[l] , a[l]}};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2 , l , mid);
    build(id * 2 + 1 , mid + 1 , r);
    tree[id].fi = tree[id * 2].fi + tree[id * 2 + 1].fi;
    tree[id].se.fi = min(tree[id * 2].se.fi , tree[id * 2 + 1].se.fi);
    tree[id].se.se = max(tree[id * 2].se.se , tree[id * 2 + 1].se.se);
}
void update(int id , int l , int r , int pos , ll val){
    if(l > pos || r < pos) return;
    if(l == r){
        tree[id] = {val , {val , val}};
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 , l , mid , pos , val);
    update(id * 2 + 1 , mid + 1 , r , pos , val);
    tree[id].fi = tree[id * 2].fi + tree[id * 2 + 1].fi;
    tree[id].se.fi = min(tree[id * 2].se.fi , tree[id * 2 + 1].se.fi);
    tree[id].se.se = max(tree[id * 2].se.se , tree[id * 2 + 1].se.se);
}
pair <ll , pii> get(int id , int l , int r , int u , int v){
    if(l > v || r < u) return {0 , {1e18 + 7 , -1e18 + 7}};
    if(u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    pair <ll , pii> x = get(id * 2 , l , mid , u , v);
    pair <ll , pii> y = get(id * 2 + 1 , mid + 1 , r , u , v);
    return {x.fi + y.fi , {min(x.se.fi , y.se.fi) , max(x.se.se , y.se.se)}};
}
void inp()
{
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        // a[i] = i;
    }
}

void solve()
{
    build(1 , 1 , n);
    for(int i = 1 ; i <= q ; i++){
        int x , y , z;
        cin >> z >> x >> y;
        if(z == 1){
            int pos1 = x;
            int pos2 = y;
            x = a[x];
            y = a[y];
            swap(a[pos1] , a[pos2]);
            update(1 , 1 , n , pos1 , y);
            update(1 , 1 , n , pos2 , x);
        }
        if(z == 2){
            pair <ll , pii> res = get(1 , 1 , n , x , y);
            ll val = ((res.se.fi + res.se.se) * (res.se.se - res.se.fi + 1)) / 2;
            if(val == res.fi) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

void run_with_file()
{
//    if(fopen(file".inp","r")){
//        freopen(file".inp","r", stdin);
//        freopen(file".out", "w", stdout);
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
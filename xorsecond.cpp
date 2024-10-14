#include <bits/stdc++.h>
#define name "xorsecond"
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long

const int N = 2e5 + 5;
const ll oo = 1e18 + 7;

using namespace std;

int n;
ll tree[4 * N];
pii a[N];
void build(int id , int l , int r){
    if(l == r){
        tree[id] = -oo;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
}
void update(int id, int l , int r , int pos , int val){
    if(pos < l || pos > r) return;
    if(l == r){
        tree[id] = val;
//        cout << l << ' ' << r << ' ' << val << '\n';
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , pos , val);
    update(id << 1 | 1 , mid + 1 , r , pos , val);
    tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
}
ll get(int id , int l , int r , int u , int v , int val){
//    cout << l << ' ' << r << ' ' << u << ' ' << v << ' ' << val << ' ' << tree[id] << '\n';
    if(u > r || v < l) return -1;
    if(tree[id] < val) return -1;
    if(l == r) return tree[id];
    int mid = (l + r) >> 1;
    int res = get(id << 1 , l , mid , u , v , val);
    if(res == -1) res = get(id << 1 | 1 , mid + 1 , r , u , v , val);
    return res;
}
ll get1(int id , int l , int r , int u , int v , int val){
//    cout << l << ' ' << r << ' ' << u << ' ' << v << ' ' << val << ' ' << tree[id] << '\n';
    if(u > r || v < l) return -1;
    if(tree[id] < val) return -1;
    if(l == r) return tree[id];
    int mid = (l + r) >> 1;
    int res = get1(id << 1 | 1 , mid + 1 , r , u , v , val);
    if(res == -1) res = get1(id << 1 , l , mid , u , v , val);
    return res;
}
int main(){
    freopen(name".inp" , "r" , stdin);
    freopen(name".out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1 , a + 1 + n);
    reverse(a + 1 , a + 1 + n);
    build(1 , 1 , n);
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int val1 = get(1 , 1 , n , a[i].se + 1 , n , a[i].fi);
        int val2 = get1(1 , 1 , n , 1 , a[i].se - 1 , a[i].fi);
        if(a[i].se != n && val1 > 0)
            ans = max(ans , (a[i].fi ^ val1));
        if(a[i].se != 1 && val2 > 0)
            ans = max(ans , (a[i].fi ^ val2));
        update(1 , 1 , n , a[i].se , a[i].fi);
//        cout << tree[1] << '\n';
    }
    cout << ans;
}


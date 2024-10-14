    #include <bits/stdc++.h>
#define BIT(x , i) (((x) >> (i)) & 1)
#define ll long long
#define fi first
#define se second
#define pii pair <int , int>

const ll oo = 1e9 + 7;
const int N = 2e5 + 5;

using namespace std;

int n , m , a[N] , tree[4 * N][40] , lazy[4 * N];

void change(int id){
    for(int i = 0 ; i < 31 ; i++){
        tree[id][i] = tree[id << 1][i] + tree[id << 1 | 1][i];
    }
}

void down(int id , int l , int r){
    int mid = (l + r) >> 1;
    for(int i = 0 ; i < 31 ; i++){
        if(BIT(lazy[id] , i)){
            tree[id << 1][i] = (mid - l + 1) - tree[id << 1][i];
            tree[id << 1 | 1][i] = (r - mid) - tree[id << 1 | 1][i];
        }
    }
    lazy[id << 1] ^= lazy[id];
    lazy[id << 1 | 1] ^= lazy[id];
    lazy[id] = 0;
}

void build(int id , int l , int r){
    if(l == r){
        for(int i = 0 ; i < 31 ; i++){
            tree[id][i] = BIT(a[l] , i);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    change(id);
}

void update(int id , int l , int r , int u , int v , int val){
    if(u > r || l > v) return;
    if(u <= l && r <= v){
        for(int i = 0 ; i < 31 ; i++){
            if(BIT(val , i)){
                tree[id][i] = (r - l + 1) - tree[id][i];
            }
        }
        lazy[id] ^= val;
        return;
    }
    int mid = (l + r) >> 1;
    down(id , l , r);
    update(id << 1 , l , mid , u , v , val);
    update(id << 1 | 1 , mid + 1 , r , u , v , val);
    change(id);
}

ll get(int id , int l , int r , int u , int v){
    if(u > r || l > v) return 0;
    if(u <= l && r <= v){
        ll val = 0;
        for(int i = 0 ; i < 31 ; i++){
            val += (1ll << i) * tree[id][i];
        }
        return val;
    }
    int mid = (l + r) >> 1;
    down(id , l , r);
    return get(id << 1 , l , mid , u , v) +
           get(id << 1 | 1 , mid + 1 , r , u , v);
}

int main(){
    freopen("sumxor.inp" , "r" , stdin);
    freopen("sumxor.out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    build(1 , 1 , n);
    cin >> m;
    for(int i = 1 ; i <= m ; i++){
        int type;
        cin >> type;
        if(type == 1){
            int l , r;
            cin >> l >> r;
            cout << get(1 , 1 , n , l , r) << '\n';
        }
        else{
            int l , r , x;
            cin >> l >> r >> x;
            update(1 , 1 , n , l , r , x);
        }
    }
}

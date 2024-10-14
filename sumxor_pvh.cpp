#include <bits/stdc++.h>
#define pb push_back
#define all(c) (c).begin() , (c).end()

const int N = 2e6 + 5;

using namespace std;

struct Query{
    int l , r , id;
}qu[N];

bool cmp(Query a , Query b){
    return a.r < b.r;
}

int n , a[N] , q , cnt[N] , idx[N] , pref_xor[N] , pos[N] , tree[2 * N] , res[N];
bool used[N];
vector<int> compress;

void update(int id , int l , int r , int pos , int val){
    if(pos > r || l > pos) return;
    if(l == r){
        tree[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , pos , val);
    update(id << 1 | 1 , mid + 1 , r , pos , val);
    tree[id] = tree[id << 1] ^ tree[id << 1 | 1];
}

int get(int id , int l , int r , int u , int v){
    if(l > v || u > r) return 0;
    if(u <= l && r <= v) return tree[id];
    int mid = (l + r) >> 1;
    return (get(id << 1 , l , mid , u , v) ^ get(id << 1 | 1 , mid + 1 , r , u , v));
}

void sub2(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        compress.pb(a[i]);
    }
    sort(all(compress));
    compress.erase(unique(all(compress)) , compress.end());
    for(int i = 1 ; i <= n ; i++){
        idx[i] = lower_bound(all(compress) , a[i]) - compress.begin();
    }
    cin >> q;
    queue <int> qu;
    for(int i = 1 ; i <= q ; i++){
        int l , r;
        cin >> l >> r;
//            cout << l << ' ' << r << '\n';
        int ans = 0;
        for(int i = l ; i <= r ; i++){
            qu.push(idx[i]);
            cnt[idx[i]]++;
//                cout << a[i] << ' ' << cnt[idx[i]] << ' ' << idx[i] << ' ' << ans << '\n';
        }
        while(qu.size()){
            int u = qu.front();
            if(cnt[u] % 2 == 0 && cnt[u]){
                ans ^= compress[u];
            }
            cnt[u] = 0;
            qu.pop();
        }
        cout << ans << ' ';
    }
}

void sub3(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        compress.pb(a[i]);
    }
    sort(all(compress));
    compress.erase(unique(all(compress)) , compress.end());

    for(int i = 1 ; i <= n ; i++){
        idx[i] = lower_bound(all(compress) , a[i]) - compress.begin();
    }

    for(int i = 1 ; i <= n ; i++){
        pref_xor[i] = pref_xor[i - 1] ^ a[i];
    }

    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int l , r;
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
    }
    sort(qu + 1 , qu + 1 + q , cmp);
    int r = 0;
    for(int i = 1 ; i <= q ; i++){
//        cout << qu[i].l << ' ' << qu[i].r << '\n';
        while(r < qu[i].r){
            r++;
            update(1 , 1 , n , r , a[r]);
            update(1 , 1 , n , pos[idx[r]] , 0);
            pos[idx[r]] = r;
        }
        res[qu[i].id] = ((pref_xor[qu[i].r] ^ pref_xor[qu[i].l - 1]) ^ get(1 , 1 , n , qu[i].l , qu[i].r));
    }
    for(int i = 1 ; i <= q ; i++) cout << res[i] << ' ';
}

int main(){
//    freopen("test.inp" , "r" , stdin);
//    freopen("test.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    if(test_case <= 2) sub2();
    else sub3();
 }

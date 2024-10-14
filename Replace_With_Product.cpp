#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair <int , int>
#define ll long long

const int N = 2e5 + 5;
using namespace std;

int n , a[N];

void re_build(int id , int l , int r){
    lazy[id] = 0;
    if(l == r){
        tree[id] = {0 , 0};
        return;
    }
    int mid = (l + r) >> 1;
    re_build(id << 1 , l , mid);
    re_build(id << 1 | 1 , mid + 1 , r);
    change(id);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    while(test_case--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }
        cin >> s;
        s = " " + s;
        build(1 , 1 , n);
        cin >> q;
        for(int i = 1 ; i <= q ; i++){
            int type;
            cin >> type;
            if(type == 1){
                int l , r;
                cin >> l >> r;
                update(1 , 1 , n , l , r);
            }
            else{
                int x;
                cin >> x;
                cout << (x ? tree[1].fi : tree[1].se) << ' ';
            }
        }
        cout << '\n';
        re_build(1 , 1 , n);
    }
}

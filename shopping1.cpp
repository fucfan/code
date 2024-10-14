#include <bits/stdc++.h>
#define ll long long

const int N = 2e5 + 5;
const int LOG = 20;
using namespace std;

int n , m , lg2[N];
ll a[N] , rmq[N][LOG + 5];

void prepare(){
    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i + (1 << (j - 1)) <= n ; i++){
            rmq[i][j] = min(rmq[i][j - 1] , rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        while((1 << lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("shopping.inp" , "r" , stdin);
    freopen("shopping.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        rmq[i][0] = a[i];
    }
    prepare();
    for(int i = 1 ; i <= m ; i++){
        int l , r;
        ll t;
        cin >> t >> l >> r;
//        cout << t << ' ' << l << ' ' << r << '\n';
        while(1){
            int u = l , v = r;
            bool check = 0;
//            cout << u << ' ' << v << '\n';
            while(u <= v){
                int mid = (u + v) >> 1;
                int length = lg2[mid - u + 1];
                ll val = min(rmq[u][length] , rmq[mid - (1 << length) + 1][length]);
//                cout << u << ' ' << mid << ' ' << val << ' ' << t << '\n';
                if(t >= val){
                    v = mid - 1;
                    check = 1;
                }
                else u = mid + 1;
            }
            if(check){
                l = u + 1;
                t %= a[u];
            }
            else break;
        }
        cout << t << '\n';
    }
}

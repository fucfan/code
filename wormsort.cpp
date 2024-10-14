#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
const int N = 2e5 + 5;
using namespace std;
int n , m , a[N] , sz[N] , par[N] , cnt;
pair <int , pii> edge[N];
void make_set(){
    for(int i = 1 ; i <= n ; i++){
        par[i] = i;
        if(a[i] != i){
            sz[i] = 1;
            cnt++;
        }
    }
}
int get(int a){
    if(a == par[a]) return a;
    else return get(par[a]);
}
void uni(int a , int b){
    a = get(a);
    b = get(b);
    if(sz[a] > sz[b]) swap(a , b);
    sz[b] += sz[a];
    par[a] = b;
}
int main(){
    freopen("wormsort.in" , "r" , stdin);
    freopen("wormsort.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= m ; i++){
        cin >> edge[i].se.fi >> edge[i].se.se >> edge[i].fi;
    }
    make_set();
    if(!cnt){
        cout << -1;
        exit(0);
    }
    sort(edge + 1 , edge + 1 + m);
    reverse(edge + 1 , edge + 1 + m);
    for(int i = 1 ; i <= m ; i++){
        if(get(edge[i].se.fi) !=  get(edge[i].se.se)){
            uni(edge[i].se.fi , edge[i].se.se);
            if(sz[get(edge[i].se.se)] == cnt){
                cout << edge[i].fi;
                exit(0);
            }
        }
    }
}

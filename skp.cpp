#include <bits/stdc++.h>
#define ll long long
#define mem(a , b) memset((a) , (b) , sizeof((a)))
#define name "skp"

const int N = 2e5 + 5;
const ll oo = 1e18 + 7;
const int LOG = 20;

using namespace std;

int n , rmq[N][LOG + 5];
ll dp[N];
ll h[N] , b[N];

void update(int id , int l , int r , int pos , int val){
    if(pos > r || pos < l) return;
    if(l == r){
        tree[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , pos , val);
    update(id << 1 | 1 , mid + 1 , r , pos , val);
    tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
}

void prepare(){
    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i + (1 << (j - 1)) <= n ; i++){
            rmq[i][j] = min(rmq[i][j - 1] , rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main(){
    freopen(name".inp" , "r" , stdin);
    freopen(name".out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> h[i];
        rmq[i][0] = h[i];
    }
    prepare();
    for(int j = 1 ; j <= n ; j++){
        cin >> b[j];
    }

}

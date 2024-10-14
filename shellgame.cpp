#include <bits/stdc++.h>
using namespace std;
int n , x[4] , cnt[4] , res;
struct quest{
    int a , b , g;
};
quest q[101];
int main(){
    freopen("shell.in" , "r" , stdin);
    freopen("shell.out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> q[i].a >> q[i].b >> q[i].g;
    }
    for(int i = 1 ; i <= 3 ; i++){
        memset(x , 0 , sizeof(x));
        x[i] = 1;
        for(int j = 1 ; j <= n ; j++){
            swap(x[q[j].a] , x[q[j].b]);
            if(x[q[j].g] == 1) cnt[q[i].g]++;
        }
            res = max(res , cnt[q[i].g]);
        memset(cnt , 0 , sizeof(cnt));
    }
    cout << res;
}

#include <bits/stdc++.h>
using namespace std;
long n,m,a[1000001],b[1000001],g;
int main(){
    cin >> n >> m;
    for(long i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(long i = 1;i <= m;i++){
        cin >> b[i];
    }
    sort(a + 1,a + n + 1);
    sort(b + 1,b + n + 1);
    long i,j;
    i = 1;j = 1;
    while(i < n){
        if(a[i] <= b[i] && a[i] >= 0){
            if(a[i + 1] > b[i]){
                a[i] = -1;
                i = 1;
            }
        }
        if(j == m){
            i++;
            j = 1;
        }
        j++;
    }
    for(long k = 1;k <= n;k++){
        g = max(g,a[k]);
    }
    cout << g;
}
#include <bits/stdc++.h>
using namespace std;
long t,a[10000],k,p;
int main(){
    // freopen("TROXE.int","r",stdin);
    // freopen("TROXE.out","w",stdout);
    cin >> k;
    for(long i = 1;i <= k;i++){
        cin >> t;
        a[t - 10100000]++;
    }
    for(long i = 2010;i <= 9999;i++){
        if(a[i] <= 5 && a[i] > 0) p = p + 100;
        if(a[i] > 5 && a[i] > 0) p = p + (a[i] - 5) + 100;
    }
    cout << p;
}
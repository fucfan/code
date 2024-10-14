#include <bits/stdc++.h>
using namespace std;
long n,a,b;
int main(){
    freopen("STONES.inp","r",stdin);
    freopen("STONES.out","w",stdout);
    cin >> n;
    // n = rand() % 50 + 1238108;
    // cout << n << " ";
    a = sqrt(n);
    b = a;
    if(a * b == n) cout << a << " " << b;
    while(a * b < n ){
        a++;
        if(a * b >= n){
            cout << b << " " << a;
            exit(0);
        }
        b++;
        if(a * b >= n){
            cout << b << " " << a;
            exit(0);
        }
    }
    while(a * b > n){
        a--;
        if(a * b <= n){
            cout << b << " " << a + 1;
            exit(0);
        }
        b--;
        if(a * b <= n){
            cout << b + 1 << " " << a;
            exit(0);
        }
    }
}
#include<bits/stdc++.h>
#define file "twotasks"
using namespace std;

double a , b , c , v0 , v1 , v2;

int main(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
    cin >> a >> b >> c >> v0 >> v1 >> v2;
    cout << setprecision(15) << fixed << min({min(a , b + c) / v0 + min(b , c + a) / v0 + min(a , b + c) / v1 + min(b , c + a) / v1 , (min(a , b) + c) / v0 + c / v1 + min(a , b) / v2 , min(a , b) / v0 + c / v1 + max(a , b) / v2 , max(a , b) / v0 + c / v1 + min(a , b) / v2});
}
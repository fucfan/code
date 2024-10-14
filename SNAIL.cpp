#include <bits/stdc++.h>
using namespace std;
long a,b,v,d;long long s;
int main(){
    cin >> a >> b >> v;
    if(a >= v){
        cout << 1;
        exit(0);
    }
    // a = rand() % 20 + 10;
    // b = a - 3;
    // v = rand() % 50;
    // cout << a << " " << b << " " << v << endl;
    s = (v - a) / (a - b);
    d = (v - a) % (a - b);
    if(d == 0) s++;
    else s = s + 2;
    cout << s;
}
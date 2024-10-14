#include <bits/stdc++.h>
using namespace std;
long n;
int main(){
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n % 2 == 0) n = n / 2;
        else n = n * 3 + 1;
    }
    cout << "1";
}
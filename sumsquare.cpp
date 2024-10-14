#include <bits/stdc++.h>
using namespace std;
long long k , cnt;
int main(){
    cin >> k;
    for(long long i = 1 ; i <= sqrt(k) ; i++){
        long long p = sqrt(k - i * i);
        if(p * p + i * i == k){
            cnt++;
        }
    }
    cout << cnt;
}

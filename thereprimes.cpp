#include <bits/stdc++.h>
using namespace std;
const int N = 3e7 + 5;
int k , a[N] , cnt , cnt1;
bool prime[N];
vector <int> pr;
void sieve(){
    for(long long i = 2 ; i <= 1e7 ; i++){
        if(!prime[i]){
            pr.push_back(i);
            for(long long j = i * i ; j <= 1e7 ; j += i){
                if(j <= N){
                        //cout << j << '\n';
                    prime[j] = true;
                }
            }
        }
    }
}
void out(){
    //cout << a[1] << ' ' << a[2] << ' ' << a[3] << '\n';
    int z = (a[1] + a[2]) % a[3];
    int x = (a[2] + a[3]) % a[1];
    int y = (a[3] + a[1]) % a[2];
    //cout << x << ' ' << y << ' ' << z << "gg\n";
    if((z == a[3] - 1 || z == 1) && (x == a[1] - 1 || x == 1) && (y == a[2] - 1 || y == 1)){
        cout << a[1] << ' ' << a[2] << ' ' << a[3] << '\n';
        cout << cnt1 << '\n';
        cnt1++;
        if(cnt1 == k) exit(0);
    }
}
void TRY(int i){
    for(int j = 0 ; j < 10000 ; j++){
        if(pr[j] >= a[i - 1]){
            a[i] = pr[j];
            if(i == 3){
                out();
            }
            else TRY(i + 1);
        }
    }
}
int main(){
    cin >> k;
    sieve();
    for(auto j : pr){
        if(!prime[j * 2 - 1])cnt++;
        if(cnt == k){
            cout << j << ' ' << j << ' ' << j * 2 - 1 << '\n';
            exit(0);
        }
        if(!prime[j * 2 + 1])cnt++;
        if(cnt == k){
            cout << j << ' ' << j << ' ' << j * 2 + 1 << '\n';
            exit(0);
        }
    }
}

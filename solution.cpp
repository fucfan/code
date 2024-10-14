#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) bool((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "solution"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , a[N] , b , bit[50] , cnt;
void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    cin >> b;
}

void solve(){
    mem(bit , -1);
    for(int i = n ; i >= 1 ; i--){
        for(int j = 0 ; j < 31 ; j++){
            if(i % 2 == 0 && getBit(a[i] , j) && bit[j] == -1){
                bit[j] = 1;
            }
            if(i % 2 == 1 && !getBit(a[i] , j) && bit[j] == -1){
                bit[j] = 0;
            }
        }
    }
    for(int i = 0 ; i < 31 ; i++){
        if(bit[i] != -1) cnt++;
        // cout << bit[i] << ' ';
        if(bit[i] != getBit(b , i) && bit[i] != -1){
            cout << 0;
            exit(0);
        }
    }
    nl;
    // cout << cnt << '\n';
    cout << (1ll << cnt);
}

void run_with_file(){
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UMU      */
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "sci"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

ll n;
int cnt;

void inp(){
    cin >> n;
}

void solve(){
    ll i = 1 , j = 2;
    for(int i = 2 ; 1ll * i * i <= n ; i++){
        if(i & 1){
            if(n % i == 0){
                int tmp = (n / i);
                if((tmp & 1) && (i - tmp / 2 >= 0)){
                    // cout << tmp << '\n';
                    cnt++;
                }
                // cout << i << '\n';
                cnt++;
            }
        }
        else{
            if((n % i) == (i / 2)){
            // cout << i << '\n';
                cnt++;
            }
            int tmp = (n / i);
            if(tmp & 1){
                if(n % i == 0){
                    if(i - tmp / 2 >= 0){
                        // cout << tmp << '\n';
                        cnt++;
                    }
                }
            }
            else{
                if(n % i == tmp / 2){
                    // cout << tmp << '\n';
                    cnt++;
                }
            }
        }
        // cout << i / 2 << ' ' << n % i << ' ' << cnt << '\n';
    }   

    cout << cnt;
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
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
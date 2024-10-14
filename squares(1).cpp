#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "squares"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int cnt[10];
ll k;

void inp(){
    cin >> k;

    for(int i = 1 ; i <= 1e6 ; i++){
        ll tmp = 1ll * i * i;
        mem(cnt , 0);

        bool check = 1;

        while(tmp){
            // cout << tmp % 10 << ' ' << cnt[tmp % 10] << '\n';
            if(cnt[tmp % 10] > 0) check = 0;
            cnt[tmp % 10]++;
            tmp /= 10;
        }

        tmp = 1ll * i * i;

        if(check){
            k--;
            if(!k){
                cout << tmp;
                exit(0);
            }
        }
    }

    cout << -1;
}

void solve(){
    
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
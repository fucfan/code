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
#define file "vector"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , m , a[N][30] , lis[N] , dp[N];
int bs(int l , int r , int x[]){
    int mid = (l + r) >> 1;
    bool check = 1;
    // cout << l << ' ' << r << "gg\n";
    for(int i = 1 ; i <= m ; i++){
        // cout << a[lis[mid]][i] << ' ' << x[i] << '\n';
        if(a[lis[mid]][i] >= x[i]){
            // nl;
            check = 0;
            break;
        }
    }
    // nl;
    if(r - l <= 1){
        if(check) return r;
        return l;
    }
    if(check) return bs(mid , r , x);
    else return bs(l , mid , x);
}
void sub125(){
    mem(lis , 0x3f);
    lis[0] = 0;
    int length = 0;
    for(int i = 1 ; i <= n ; i++){
        int pos = lower_bound(lis , lis + length + 2 , a[i][1]) - lis;
        lis[pos] = a[i][1];
        length = max(length , pos);
    }
    cout << length;
}
void sub346(){
    for(int i = 1 ; i <= m ; i++){
        a[0][i] = oo;
    }
    int length = 1;
    dp[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        dp[i] = 1;
        for(int j = 1 ; j < i ; j++){
            bool check = 1;
            for(int k = 1 ; k <= m ; k++){
                if(a[j][k] >= a[i][k]){
                    check = 0;
                    break;
                }
            }
            if(check){
                dp[i] = max(dp[i] , dp[j] + 1);
                length = max(length , dp[i]);
            }
        }
        // cout << i << ' ' << dp[i] << '\n';
    }
    cout << length;
}
void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
        sort(a[i] + 1 , a[i] + 1 + m);
        // for(int j = 1 ; j <= m ; j++){
        //     cout << a[i][j] << ' ' ;
        // }
        // nl;
    }
}

void solve(){
    if(m == 1) sub125();
    else sub346();
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
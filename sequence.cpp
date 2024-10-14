#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 3e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        // freopen(file".inp", "r" , stdin);
        // freopen(file".out", "w" , stdout);
    }
}

int n , a[N];
ll dp1[N][N];
ll dp2[N][N];
ll ans = oo;
ll res[N];

ll sol_l(int i , int pre){
    if(i < 1) return 0;

    if(dp1[i][pre] != -1) return dp1[i][pre];
    
    ll res = oo;

    res = min(res , sol_l(i - 1 , pre) + abs(a[i] - (a[pre] - (pre - i))));
    if(a[i] < a[pre] - (pre - i + 1)) res = min(res , sol_l(i - 1 , i));

    return dp1[i][pre] = res;
}

ll sol_r(int i , int pre){

    if(i > n) return 0;

    if(dp2[i][pre] != -1) return dp2[i][pre];
    
    ll res = oo;

    res = min(res , sol_r(i + 1 , pre) + abs(a[i] - (a[pre] + (i - pre))));
    if(a[i] > a[pre] + (i - pre - 1)) res = min(res , sol_r(i + 1 , i));

    return dp2[i][pre] = res;
}

void trace(){
    int pos = 1;
    for(int i = 1 ; i <= n ; i++){
        if(sol_l(i - 1 , i) + sol_r(i + 1 , i) == ans){
            pos = i;
            break;
        }
    }

    res[pos] = a[pos];

    int pre = pos;
    ll val = sol_r(pos + 1 , pos);

    for(int i = pos + 1 ; i <= n ; i++){
        if(sol_r(i , pre) == sol_r(i + 1 , i) && a[i] > a[pre] + (i - pre - 1)){
            res[i] = a[i];
            pre = i;
            val = sol_r(i + 1 , i);
        }
        else{
            res[i] = a[pre] + (i - pre);
            val = sol_r(i , pre) + abs(a[i] - (a[pre] + (i - 1 - pre)));
        }
    }

    pre = pos;
    val = sol_l(pos - 1 , pos);

    for(int i = pos - 1 ; i >= 1 ; i--){
        if(sol_l(i , pre) == sol_l(i - 1 , i) && a[i] < a[pre] - (i - pre + 1)){
            res[i] = a[i];
            pre = i;
            val = sol_l(i - 1 , i);
            // cout << i << ' ' << "kkk\n";
        }
        else{
            res[i] = a[pre] - (pre - i);
        }
    }
}

void inp(){
    cin >> n;   
    assert(n <= 3000);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){
    mem(dp1 , -1);
    mem(dp2 , -1);

    for(int i = 1 ; i <= n ; i++){
        ans = min(ans , sol_l(i - 1 , i) + sol_r(i + 1 , i));
    }

    cout << ans << '\n';

    trace();

    for(int i = 1 ; i <= n ; i++){
        cout << res[i] << ' ';
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

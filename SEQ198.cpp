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
#define add(x , y) ((x) = (x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e3 + 5;
const int LOG = 20;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        //freopen(file".inp", "r" , stdin);
        //freopen(file".out", "w" , stdout);
    }
}

int n , b[N];
vector <int> pre_pos[N];
map <int , int> cnt;
vector <int> a , cnt_a;
int dp[N][N];

int sol(int i , int mask){

    if(i >= a.size()){
        // cout << i << ' ';
        // for(int i = 1 ; i <= 10 ; i++) cout << BIT(mask , i - 1);
        // nl;
        return 0;
    }

    // cout << mask << '\n';

    bool check = 1;

    if(dp[i][mask] != -1) return dp[i][mask];

    int res = 0;

    for(auto j : pre_pos[i]){
        if(BIT(mask , j - 1)) check = 0;
    }

    int nxt_mask = mask;

    if(check) ((nxt_mask <<= 1) &= ((1 << 10) - 1)) |= 1;
    
    if(check) res = max(res , sol(i + 1 , nxt_mask) + cnt_a[i]);
    res = max(res , sol(i + 1 , ((mask << 1) & ((1 << 10) - 1))));

    return dp[i][mask] = res;

}

void inp(){
    cin >> n;
    a.pb(-1);
    for(int i = 1 ; i <= n ; i++){
        cin >> b[i];
        a.pb(b[i]);
        cnt[b[i]]++;
    }

    sort(all(a));
    a.erase(unique(all(a)) , a.end());
}

void solve(){
    for(auto j : a){
        cnt_a.pb(cnt[j]);
    }

    for(int i = 0 ; i < a.size() ; i++){
        for(int j = max(0 , i - 10) ; j < i ; j++){
            if(a[i] - a[j] == 1 || a[i] - a[j] == 8 || a[i] - a[j] == 9){
                pre_pos[i].pb(i - j);
                // cout << i << ' ' << j << '\n';
            }
        }
    }

    mem(dp , -1);
    cout << n - sol(1 , 0);
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
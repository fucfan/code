#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "taxi"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , a[N] , s , t;
vector <int> ans;
bool used[N];

bool dfs(int node , int cnt){
    // cout << node << '\n';
    if(node == t) return 1;
    if(cnt > 100 || node > t) return 0;
    for(int i = 1 ; i <= n ; i++){
        if(used[i]) continue;
        used[i] = 1;
        if(dfs((node | a[i]) , cnt + 1)){
            ans.pb(i);
            return 1;
        }
        used[i] = 0;
    }
    return 0;
}

void inp(){
    cin >> n >> s >> t;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
}

void solve(){
    if(!dfs(s , 0)) return cout << -1 , void();
    cout << ans.size() << '\n';
    sort(all(ans));
    // reverse(all(ans));
    for(auto j : ans) cout << j << ' ';
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
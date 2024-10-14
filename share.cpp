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
#define file "share"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
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

int n;
pii a[N];
ll ans[N];
ll m;

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
}

void solve(){
    sort(a + 1 , a + 1 + n);

    ll cur = 0;

    for(int i = 1 ; i <= n ; i++){
        if(a[i].fi - cur > 0){
            if(m / (n - i + 1) > a[i].fi - cur){
                m = m - (1ll * (a[i].fi - cur) * (n - i + 1));
                cur = a[i].fi;
            }
            else{
                cur += m / (n - i + 1);
                m %= (n - i + 1);
            }
        }

        ans[a[i].se] = cur;
        // cout << m << ' ' << cur << '\n';

        // for(int j = 1 ; j <= n ; j++) cout << ans[j] << ' ';
        // nl;
    }

    if(m) cout << -1;
    else{
        for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
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
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
#define file "woods"
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

int n , k;
ll a[N];
ll Max;

void inp(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        Max = max(Max , a[i]);
    }
}

void solve(){
    int l = 1 , r = oo;
    int ans = Max;
    while(l <= r){
        int mid = (l + r) / 2;

        // cout << mid << '\n';

        ll cost = 0;
        
        for(int i = 1 ; i <= n ; i++){
            cost += (a[i] / mid + (a[i] % mid != 0)) - 1;
        }

        if(cost > k){
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ans = mid;
        }
    }

    cout << ans;
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
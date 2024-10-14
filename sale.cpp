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
#define add(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "sale"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , discount;
ll ship , a[N];
ll pref[N];

ll get(int l , int r){
    if(r < l) return 0;
    return pref[r] - pref[l - 1];
}

void inp(){
    cin >> n >> ship >> discount;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve(){
    sort(a + 1 , a + 1 + n);
    for(int i = 1 ; i <= n ; i++) pref[i] = pref[i - 1] + a[i];

    // for(int i = 1 ; i <= n ; i++) cout << a[i] << ' ';
    // nl;
    // nl;

    ll ans = loo;

    for(int i = discount + 1 ; i <= n ; i++){
        ll cost = 0;
        for(int j = (n % i) + 1 ; j <= n ; j += i){
            int l = j;
            int r = min(n , j + i - 1);
            // cout << l << ' ' << r << ' ' << discount << ' ' << get(l , r) << ' ' << get(l + discount , r) << '\n';
            if(r - l + 1 >= i){
                if(!cost) cost += ship + get(l + discount , r);
                else cost += min(get(l , r) , ship + get(l + discount , r));
            }
            else{
                if(!cost) cost = ship;
                cost += get(l , r);
            }
        }
        // cout << cost + get(1 , (n % i)) + ship << ' ';
        cost = min(cost + get(1 , (n % i) + discount) - get(1 , discount) , cost + get(1 , (n % i)) + ship);
        cout << cost << ' ';
    }
    
    for(int i = 1 ; i <= discount ; i++) cout << pref[n] + ship << ' ';
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
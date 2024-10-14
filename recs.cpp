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

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
//        freopen(file".inp", "r" , stdin);
//        freopen(file".out", "w" , stdout);
    }
}

pii rect[4];

bool check(ll x1 , ll y1 , ll x2 , ll y2){
    if(x1 > y1) swap(x1 , y1);
    if(x2 > y2) swap(x2 , y2);

    return (x1 >= x2 && y1 >= y2);
}

bool ok(int num1 , int num2 , int num3 , ll s){

    ll x = rect[num1].fi + rect[num2].fi;
    ll y = s / x;

    ll y1 = y - rect[num1].se;
    ll y2 = y - rect[num2].se;

    if(y1 >= 0 && y2 >= 0){
        if(check(rect[num1].fi , y1 , rect[num3].fi , rect[num3].se)) return 1;
        if(check(rect[num2].fi , y2 , rect[num3].fi , rect[num3].se)) return 1;
    }
    x = rect[num1].se + rect[num2].fi;
    y = s / x;

    y1 = y - rect[num1].fi;
    y2 = y - rect[num2].se;

    if(y1 >= 0 && y2 >= 0){
    if(check(rect[num1].se , y1 , rect[num3].fi , rect[num3].se)) return 1;
    if(check(rect[num2].fi , y2 , rect[num3].fi , rect[num3].se)) return 1;
    }

    x = rect[num1].fi + rect[num2].se;
    y = s / x;

    y1 = y - rect[num1].se;
    y2 = y - rect[num2].fi;

    if(y1 >= 0 && y2 >= 0){
        if(check(rect[num1].fi , y1 , rect[num3].fi , rect[num3].se)) return 1;
        if(check(rect[num2].se , y2 , rect[num3].fi , rect[num3].se)) return 1;
    }
    x = rect[num1].se + rect[num2].se;
    y = s / x;

    y1 = y - rect[num1].fi;
    y2 = y - rect[num2].fi;

    if(y1 >= 0 && y2 >= 0){
        if(check(rect[num1].se , y1 , rect[num3].fi , rect[num3].se)) return 1;
        if(check(rect[num2].se , y2 , rect[num3].fi , rect[num3].se)) return 1;
    }

    return 0;
}

bool ok1(ll s){
    ll x = rect[1].fi + rect[2].fi + rect[3].fi;
    ll y = s / x;
    if(y >= max({rect[1].se , rect[2].se , rect[3].se})) return 1;

    x = rect[1].fi + rect[2].fi + rect[3].se;
    y = s / x;
    if(y >= max({rect[1].se , rect[2].se , rect[3].fi})) return 1;

    x = rect[1].fi + rect[2].se + rect[3].fi;
    y = s / x;
    if(y >= max({rect[1].se , rect[2].fi , rect[3].se})) return 1;

    x = rect[1].fi + rect[2].se + rect[3].se;
    y = s / x;
    if(y >= max({rect[1].se , rect[2].fi , rect[3].fi})) return 1;

    x = rect[1].se + rect[2].fi + rect[3].fi;
    y = s / x;
    if(y >= max({rect[1].fi , rect[2].se , rect[3].se})) return 1;

    x = rect[1].se + rect[2].fi + rect[3].se;
    y = s / x;
    if(y >= max({rect[1].fi , rect[2].se , rect[3].fi})) return 1;

    x = rect[1].se + rect[2].se + rect[3].fi;
    y = s / x;
    if(y >= max({rect[1].fi , rect[2].fi , rect[3].se})) return 1;

    x = rect[1].se + rect[2].se + rect[3].se;
    y = s / x;
    if(y >= max({rect[1].fi , rect[2].fi , rect[3].fi})) return 1;

    return 0;
}

void inp(){
    cin >> rect[1].fi >> rect[1].se >> rect[2].fi >> rect[2].se >> rect[3].fi >> rect[3].se;
}

void solve(){
    ll l = 1 , r = 3e18;
    ll ans = r;

    while(l <= r){
        ll mid = (l + r) >> 1;

        if(ok(1 , 2 , 3, mid) || ok(1 , 3 , 2 , mid) || ok(2 , 3 , 1 , mid) || ok1(mid)){
            r = mid - 1;
            ans = min(ans , mid);
        }
        else l = mid + 1;
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */

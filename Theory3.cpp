#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
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

int w;
ll h;
vector <int> vt;

void inp(){
    cin >> w >> h;
    for(int i = 1; i <= w; i++) vt.pb(i);
}

void solve(){
    ll my = 0;
    ll mx = 1;
    string s;
    random_shuffle(all(vt));
    int cnt = 0;
    for(auto i : vt){
        cout << "? " << i << ' ' << my + 1 << endl;
        cnt++;
        cin >> s;
        if(s == "sky") continue;
        my++;
        mx = i;
        ll l = my + 1;
        ll r = h;
        while(l <= r){
            ll mid = (l + r) >> 1;
            cout << "? " << i << ' ' << mid << endl;
            cnt++;
            cin >> s;
            if(s == "sky"){
                r = mid - 1;
            }
            else{
                l = mid + 1;
                if(maxi(my, mid)){
                    mx = i;
                }
            }
        }
        if(my == h) break;
        assert(cnt <= 12000);
    }
    cout << "! " << mx << ' ' << my << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
//    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */

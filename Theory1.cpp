#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<ll, ll>
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

int n, per;
pii p[N];

bool check(pii p1, pii p2, pii p3){
    return ((p1.se + p2.se) * (p2.fi - p1.fi) + (p2.se + p3.se) * (p3.fi - p2.fi) - (p3.se + p1.se) * (p3.fi - p1.fi)    == 0);
}

void inp(){
    cin >> n >> per;
    for(int i = 1; i <= n; i++) cin >> p[i].fi >> p[i].se;
    shuffle(p + 1, p + 1 + n);
}

void solve(){
    if(n == 1){
        cout << "possible";
        exit(0);
    }
    if(n == 2){
        cout << "possible";
        exit(0);
    }
    int k = (n * per + 99) / 100;
    for(int Try = 1; Try <= 200; Try++){
        int i = rand() % n;
        int j = rand() % n;
        if(i == j) continue;
        i++;
        j++;
        int cnt = 0;
        for(int f = 1; f <= n; f++){
            cnt += check(p[i], p[j], p[f]);
        }
        if(cnt >= k){
            cout << "possible";
            exit(0);
        }
    }
    cout << "impossible";
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
//    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    srand(time(NULL));
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */

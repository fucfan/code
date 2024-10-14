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
template <typename T1, typename T2> bool maxi(T1 &a, T2 b)   {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".ans", "w" , stdout);
    }
}

string a, b;
int z[N];
int p[N];
int pre[N];

void inp(){
    cin >> b >> a;
}

void solve(){
    int m = a.size();
    a = a + ' ' + b;
    int n = a.size();
    // cout << a << '\n';

    for(int i = 0; i <= 255; i++) pre[i] = -oo;

    for(int i = 0; i < (int)a.size(); i++){
        p[i] = i - pre[a[i]];
        pre[a[i]] = i;
    }

    p[m] = 0;

    int l = 0;
    int r = 0;
    z[0] = n;

    for(int i = 0; i < (int)a.size(); i++){
        cout << i << ' ' << p[i] << '\n';
    }

    for(int i = 1; i < n; i++){
        if(i > r){
            l = r = i;
            while(r < n && (p[r] == p[r - l] || (r - p[r] < l && r - l - p[r - l] < 0))){
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else{
            int k = i - l;
            if(z[k] < r - i + 1){
                z[i] = z[k];
            }
            else{
                l = i;
                while(r < n && (p[r] == p[r - l] || (r - p[r] < l && r - l - p[r - l] < 0))){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
        cout << i << ' ' << l << ' ' << r << '\n';
    }

    vector <int> res;

    for(int i = m + 1; i < n; i++){
        if(z[i] == m) res.pb(i - m);
    }
    cout << res.size() << '\n';
    for(auto j : res) cout << j << ' ';
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
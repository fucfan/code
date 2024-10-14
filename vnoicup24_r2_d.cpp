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

int n, k;
string s;
pii val[30][30];
pii cnt[30];

int get_val(int l, int r){
    int res = 0;
    for(int i = l; i <= r; i++){
        res += (1 << (i - l)) * (s[i] == 'K');
    }
    return res;
}

void prepare(){
    for(int mask1 = 0; mask1 < 8; mask1++){
        for(int mask2 = 0; mask2 < 8; mask2++){
            if(BIT(mask1, 1) == BIT(mask2, 1)) continue;
            // cout << mask1 << ' ' << mask2 << '\n';
            val[mask1][mask2].fi += (!BIT(mask2, 1) && BIT(mask1, 2));
            val[mask1][mask2].se += (!BIT(mask2, 1) && BIT(mask1, 0));
            val[mask1][mask2].fi += (BIT(mask2, 1) && !BIT(mask1, 0));
            val[mask1][mask2].se += (BIT(mask2, 1) && !BIT(mask1, 2));
            val[mask1][mask2].fi += (!BIT(mask1, 1) && BIT(mask2, 2));
            val[mask1][mask2].se += (!BIT(mask1, 1) && BIT(mask2, 0));
            val[mask1][mask2].fi += (BIT(mask1, 1) && !BIT(mask2, 0));
            val[mask1][mask2].se += (BIT(mask1, 1) && !BIT(mask2, 2));
            val[mask1][mask2].fi -= (!BIT(mask2, 1) && BIT(mask2, 2));
            val[mask1][mask2].se -= (!BIT(mask2, 1) && BIT(mask2, 0));
            val[mask1][mask2].fi -= (BIT(mask2, 1) && !BIT(mask2, 0));
            val[mask1][mask2].se -= (BIT(mask2, 1) && !BIT(mask2, 2));
            val[mask1][mask2].fi -= (!BIT(mask1, 1) && BIT(mask1, 2));
            val[mask1][mask2].se -= (!BIT(mask1, 1) && BIT(mask1, 0));
            val[mask1][mask2].fi -= (BIT(mask1, 1) && !BIT(mask1, 0));
            val[mask1][mask2].se -= (BIT(mask1, 1) && !BIT(mask1, 2));
        }
    }
}

bool ok(int i, int j){
    if(abs(cnt[i].fi - cnt[j].fi) <= 1) return (cnt[i].se != cnt[j].fi || cnt[j].se != cnt[j].fi);
    return (cnt[i].fi && cnt[j].fi);
}

void inp(){
    cin >> n >> k >> s;
}

void solve(){
    for(int i = 0; i <= 8; i++) cnt[i] = {0, 0};
    // assert(k == 1);
    int a = 0;
    int b = 0;
    int num_k = 0;
    int num_o = 0;
    for(auto j : s){
        if(j == 'K') num_k++;
        if(j == 'O') num_o++;
    }
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'O' && s[i - 1] == 'K') b++;
        if(s[i] == 'K' && s[i - 1] == 'O') a++;
    }
    ll ans = 1ll * a * a - 1ll * b * b;
    // cout << a << ' ' << b << ' ' << ans << '\n';
    s = " " + s;
    s = s + " ";

    for(int i = 2; i < n; i++){
        int tmp = get_val(i - 1, i + 1);
        if(!cnt[tmp].fi) cnt[tmp].fi = i;
        cnt[tmp].se = i;
        // cout << i << ' ' << tmp << '\n';
        // cout << val[2][5].fi << ' ' << val[2][5].se << '\n';
    }

    for(int i = 1; i < n; i++){
        int pre_a = a;
        int pre_b = b;
        a -= (s[i - 1] == 'O' && s[i] == 'K');
        a -= (s[i] == 'O' && s[i + 1] == 'K');
        a -= (s[i + 1] == 'O' && s[i + 2] == 'K');
        b -= (s[i - 1] == 'K' && s[i] == 'O');
        b -= (s[i] == 'K' && s[i + 1] == 'O');
        b -= (s[i + 1] == 'K' && s[i + 2] == 'O');
        swap(s[i], s[i + 1]);
        a += (s[i - 1] == 'O' && s[i] == 'K');
        a += (s[i] == 'O' && s[i + 1] == 'K');
        a += (s[i + 1] == 'O' && s[i + 2] == 'K');
        b += (s[i - 1] == 'K' && s[i] == 'O');
        b += (s[i] == 'K' && s[i + 1] == 'O');
        b += (s[i + 1] == 'K' && s[i + 2] == 'O');
        ans = max(ans, 1ll * a * a - 1ll * b * b);
        swap(s[i], s[i + 1]);
        a = pre_a;
        b = pre_b;
    }
    for(int i = 3; i <= n; i++){
        int pre_a = a;
        int pre_b = b;
        a -= (s[i - 1] == 'O' && s[i] == 'K');
        a -= (s[i] == 'O' && s[i + 1] == 'K');
        a -= (s[1] == 'O' && s[2] == 'K');
        b -= (s[i - 1] == 'K' && s[i] == 'O');
        b -= (s[i] == 'K' && s[i + 1] == 'O');
        b -= (s[1] == 'K' && s[2] == 'O');
        swap(s[i], s[1]);
        a += (s[i - 1] == 'O' && s[i] == 'K');
        a += (s[i] == 'O' && s[i + 1] == 'K');
        a += (s[1] == 'O' && s[2] == 'K');
        b += (s[i - 1] == 'K' && s[i] == 'O');
        b += (s[i] == 'K' && s[i + 1] == 'O');
        b += (s[1] == 'K' && s[2] == 'O');
        ans = max(ans, 1ll * a * a - 1ll * b * b);
        swap(s[i], s[1]);
        a = pre_a;
        b = pre_b;
    }
    
    for(int i = n - 2; i >= 1; i--){
        int pre_a = a;
        int pre_b = b;
        a -= (s[i - 1] == 'O' && s[i] == 'K');
        a -= (s[i] == 'O' && s[i + 1] == 'K');
        a -= (s[n - 1] == 'O' && s[n] == 'K');
        b -= (s[i - 1] == 'K' && s[i] == 'O');
        b -= (s[i] == 'K' && s[i + 1] == 'O');
        b -= (s[n - 1] == 'K' && s[n] == 'O');
        swap(s[i], s[n]);
        a += (s[i - 1] == 'O' && s[i] == 'K');
        a += (s[i] == 'O' && s[i + 1] == 'K');
        a += (s[n - 1] == 'O' && s[n] == 'K');
        b += (s[i - 1] == 'K' && s[i] == 'O');
        b += (s[i] == 'K' && s[i + 1] == 'O');
        b += (s[n - 1] == 'K' && s[n] == 'O');
        ans = max(ans, 1ll * a * a - 1ll * b * b);
        swap(s[i], s[n]);
        a = pre_a;
        b = pre_b;
    }
    
    for(int i = 0; i < 8; i++){
        for(int j = i; j < 8; j++){
            if(ok(i, j)){
                a += val[i][j].fi;
                b += val[i][j].se;
                // cout << cnt[i].fi << ' ' << cnt[j].fi << ' ' << i << ' ' << j << ' ' << a << ' ' << b << '\n';
                ans = max(ans, 1ll * a * a - 1ll * b * b);
                a -= val[i][j].fi;
                b -= val[i][j].se;
            }
        }
    }
    
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;  
    prepare(); 
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
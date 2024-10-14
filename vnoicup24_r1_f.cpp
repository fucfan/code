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
const int mod = 998244353;
const int N = 3e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

string s;
int n , k;
int pre_pos[N];
int pre[30];
int cur_pos[30];
int dp_1[30];
int dp_2[N];
int dp_3[N];
int id[N];

void sub2(string st){
    vector <int> pos[30];
    reverse(all(st));
    st = " " + st;
    // cout << st <<'\n';
    for(int i = 1 ; i <= n ; i++){
        pre_pos[i] = pre[st[i] - 'a'];
        pre[st[i] - 'a'] = i;
    }
    int Max = 0;
    for(int i = 1 ; i <= n ; i++){
        if(st[i] != st[i - 1]){
            for(int j = 0 ; j < 26 ; j++){
                if(cur_pos[j] < cur_pos[st[i] - 'a']) continue;
                if(j == st[i] - 'a') continue;
                dp_1[st[i] - 'a'] = add(dp_1[st[i] - 'a'] , dp_1[j]);
            }
        }
        cur_pos[st[i] - 'a'] = i;
        if(!pre_pos[i]) dp_1[st[i] - 'a'] = add(dp_1[st[i] - 'a'] , 1);
        dp_3[n - i + 1] = dp_1[st[i] - 'a'];
        // cout << n - i + 1 << ' ' << dp_3[n - i + 1] << '\n';
    }
    
    int ans = 0;

    reverse(all(st));

    for(int i = 0 ; i < 26 ; i++){
        pos[i].pb(0);
    }
    
    for(int i = 1 ; i <= n ; i++){
        id[i] = pos[st[i] - 'a'].size();
        pos[st[i] - 'a'].pb(i);
    }

    for(int i = 0 ; i < 26 ; i++){
        pos[i].pb(n + 1);
        pos[i].pb(n + 2);
        // cout << i << ":";
        // for(auto j : pos[i]) cout << j << ' ';
        // nl;
    }

    for(int i = 1 ; i <= n ; i++){
        int val1 = sub(dp_2[i] , dp_2[pos[st[i] - 'a'][id[i] - 1]]);
        int val2 = sub(dp_3[pos[st[i] - 'a'][id[i] + 1]] , dp_3[pos[st[i] - 'a'][id[i] + 2]]);
        
        if(!val1 || !val2) continue;

        // cout << ans << ' ' << val1 << ' ' << val2 << "gg\n";
        if(pos[st[i] - 'a'][id[i] + 1] > n) continue;

        for(int j = i + 1 ; j < pos[st[i] - 'a'][id[i] + 1] ; j++){
            if(pos[st[j] - 'a'][id[j] - 1] < pos[s[i] - 'a'][id[i] - 1] || 
               pos[st[j] - 'a'][id[j] - 1] > i) continue;
            // cout << j << ' ' << dp_2[pos[st[j] - 'a'][id[j] - 1]] << "\n";
            val1 = sub(val1 , dp_2[pos[st[j] - 'a'][id[j] - 1]]);
        }
        // nl;

        for(int j = pos[st[i] - 'a'][id[i] + 1] - 1 ; j >= i + 1 ; j--){
            if(pos[st[j] - 'a'][id[j] + 1] > pos[st[i] - 'a'][id[i] + 2] ||
               pos[st[j] - 'a'][id[j] + 1] < pos[st[i] - 'a'][id[i] + 1]) continue;
            // cout << j << ' ' << dp_3[pos[st[j] - 'a'][id[j] + 1]] << "\n";
            
            val2 = sub(val2 , dp_3[pos[st[j] - 'a'][id[j] + 1]]);
        }
        // cout << ans << ' ' << val1 << ' ' << val2 << "hh\n";
        ans = add(ans , 1ll * val1 * val2 % mod);
        // cout << ans << '\n';
    }

    for(int i = 1 ; i <= n ; i++) dp_2[i] = dp_3[i] = 0;

    cout << ans << '\n';

    for(int i = 0 ; i < 26 ; i++){
        pre_pos[i] = cur_pos[i] = 0;
    }
    mem(pre , 0);
    mem(dp_1 , 0);
}

void inp(){
    cin >> n >> s;
}

void solve(){
    s = " " + s;
    for(int i = 1 ; i <= n ; i++){
        pre_pos[i] = pre[s[i] - 'a'];
        pre[s[i] - 'a'] = i;
    }
    int Max = 0;
    for(int i = 1 ; i <= n ; i++){
        if(s[i] != s[i - 1]){
            for(int j = 0 ; j < 26 ; j++){
                if(cur_pos[j] < cur_pos[s[i] - 'a']) continue;
                if(j == s[i] - 'a') continue;
                dp_1[s[i] - 'a'] = add(dp_1[s[i] - 'a'] , dp_1[j]);
            }
        }
        cur_pos[s[i] - 'a'] = i;
        if(!pre_pos[i]) dp_1[s[i] - 'a'] = add(dp_1[s[i] - 'a'] , 1);
        dp_2[i] = dp_1[s[i] - 'a'];
        // cout << i << ' ' << dp_1[s[i] - 'a'] << '\n';
    }
    
    int ans = 0;

    for(int i = 0 ; i < 26 ; i++){
        ans = add(ans , dp_1[i]);
        pre_pos[i] = cur_pos[i] = 0;
    }
    mem(pre , 0);
    mem(dp_1 , 0);
    if(k == 1) cout << ans << '\n';
    else sub2(s);
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case >> k;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
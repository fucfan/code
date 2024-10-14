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

int res_n[200], res_m[200], res_k[200];
int n;

void inp(){
    for(int i = 0; i < 5; i++){
        cout << "edit" << " (" << "n/" << (1 << i * 2) << ")%4" << endl;
        string s;
        cin >> s;
        n = s.size();
        s = " " + s;
        for(int j = 1; j <= n; j++){
            if(s[j] == 'W') res_n[j] += (0 << i * 2);
            if(s[j] == 'M') res_n[j] += (1 << i * 2);
            if(s[j] == 'R') res_n[j] += (2 << i * 2);
            if(s[j] == 'T') res_n[j] += (3 << i * 2);
        }
    }   
    for(int i = 0; i < 5; i++){
        cout << "edit" << " (" << "m/" << (1 << i * 2) << ")%4" << endl;
        string s;
        cin >> s;
        n = s.size();
        s = " " + s;
        for(int j = 1; j <= n; j++){
            if(s[j] == 'W') res_m[j] += (0 << i * 2);
            if(s[j] == 'M') res_m[j] += (1 << i * 2);
            if(s[j] == 'R') res_m[j] += (2 << i * 2);
            if(s[j] == 'T') res_m[j] += (3 << i * 2);
        }
    }   
    for(int i = 0; i < 5; i++){
        cout << "edit" << " (" << "k/" << (1 << i * 2) << ")%4" << endl;
        string s;
        cin >> s;
        n = s.size();
        s = " " + s;
        for(int j = 1; j <= n; j++){
            if(s[j] == 'W') res_k[j] += (0 << i * 2);
            if(s[j] == 'M') res_k[j] += (1 << i * 2);
            if(s[j] == 'R') res_k[j] += (2 << i * 2);
            if(s[j] == 'T') res_k[j] += (3 << i * 2);
        }
    } 
    cout << "answer\n";
    for(int i = 1; i <= n; i++){
        cout << res_n[i] << ' ' << res_m[i] << ' ' << res_k[i] << endl;
    }  
}

void solve(){
    
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    // run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
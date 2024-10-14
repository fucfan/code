#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y    )))
#define file "string"
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

string s;
int n;
int pw[N];
vector <int> len;

void prepare(){
    for(int i = 1 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            len.pb(i);
            if(n / i != i) len.pb(n / i);
        }
    }

    sort(all(len));
}

bool cal(string str , string t){
    // cout << str << ' ' << t << '\n';
    int sz = t.size() - 1;
    int sz1 = str.size() - 1;

    if(str == " ") return 1;

    for(int i = 1 ; i <= sz1 - sz + 1 ; i++){
        bool same = 1;

        for(int j = i ; j <= i + sz - 1 ; j++){
            // cout << i << ' ' << j << ' ' << str[j] << ' ' << t[j - i + 1] << '\n';
            if(str[j] != t[j - i + 1]) same = 0;
        }

        // cout << i << ' ' << same << '\n';

        if(same){
            string nxt_str;
            for(int j = 0 ; j <= i - 1 ; j++){
                nxt_str += str[j];
            }

            for(int j = i + sz ; j <= sz1 ; j++){
                nxt_str += str[j];
            }

            // cout << nxt_str << '\n';

            return cal(nxt_str , t);
        }
    }

    return 0;
}

void inp(){
    cin >> s;
    n = s.size();
    s = " " + s;
}

void solve(){
    string ans = "";

    bool check = 0;

    prepare();

    for(auto j : len){
        for(int i = 1 ; i <= n - j + 1 ; i++){
            string st = "";

            for(int f = i ; f <= i + j - 1 ; f++){
                st += s[f];
            }

            st = " " + st;

            if(cal(s , st)){
                ans = max(ans , st);
                check = 1;
            }
        }

        if(check) break;
    }
    
    for(auto j : ans) if(j != ' ') cout << j;
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
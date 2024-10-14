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

string s;
int n, lv[N];

struct fenwick_tree{
    int node[N];

    void update(int pos, int val){
        for(; pos <= n; pos += (pos & -pos)){
            node[pos] += val;
        }
    }

    int get(int pos){
        int res = 0;
        for(; pos > 0; pos -= (pos & -pos)){
            res += node[pos];
        }
        return res;
    }
} BIT;

void inp(){
    cin >> n >> s;
    s = " " + s;
}

void solve(){
    int d = 0;
    int cnt = 0;
    stack<int> st, st1;
    for(int i = 1; i <= n; i++){
        char j = s[i];
        if(j == '6'){
            st.push(i);
            st1.push(0);
        }
        else{
            if(st.size()){
                int val = st1.top();
                st1.pop();
                lv[st.top()] = val + 1;
                if(st1.size()) st1.top() = val + 1;
                st.pop();
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(lv[i]){
            cnt += i - BIT.get(lv[i] - 1);
            BIT.update(lv[i], 2);
        }
    }
    cout << cnt;
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

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
#define file "seed"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , a[N] , num_star , sz;
string s;
ll ans;

struct Trie{
    struct Node{
        int child[3];
        int exist , cnt;
    } node[N];

    int cur;

    Trie() : cur(0){
        mem(node[cur].child , -1);
        node[cur].exist = node[cur].cnt = 0;
    }

    int new_node(){
        cur++;
        mem(node[cur].child , -1);
        node[cur].exist = node[cur].cnt = 0;
        return cur;
    }

    void add_string(string s){
        int pos = 0;
        for(auto j : s){
            int c = j - '0';
            if(node[pos].child[c] == -1) node[pos].child[c] = new_node();
            pos = node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist = 1;
    }

    bool find_string(string s){
        int pos = 0;
        for(auto j : s){
            int c = j - '0';
            if(node[pos].child[c] == -1) return 0;
            pos = node[pos].child[c];
        }

        return (node[pos].exist != 0);
    }
} trie;

void btr(int i){
    if(i >= sz){
        string t;
        for(int j = i - 1 ; j >= i - sz ; j--){
            t = char(a[j] + '0') + t;
        }
        // cout << i << ' ' << t << ' ' << trie.find_string(t) << ' ' << n - i << '\n';
        if(trie.find_string(t)){
            ans += (1ll << (n - i));
            return;
        }
    }

    for(int j = 0 ; j <= 1 ; j++){
        a[i] = j;
        if(i == n){
            return;
        }
        else btr(i + 1);
    }
}

void inp(){
    cin >> n >> s;
    num_star = 0;
    sz = s.size();
    // s = " " + s;
    for(auto j : s){
        if(j == '*') num_star++;
    }
}

void solve(){
    for(int mask = 0 ; mask < (1 << num_star) ; mask++){
        int cnt = 0;
        string t = s;
        for(int i = 0 ; i < sz ; i++){
            if(t[i] == '*'){
                t[i] = char('0' + BIT(mask , cnt));
                cnt++;
            }
        }
        // cout << t << '\n';
        trie.add_string(t);
    }
    btr(0);
    cout << ans;
}

void run_with_file(){
    if(fopen(file".inp","r")){
        freopen(file".inp","r", stdin);
        freopen(file".out", "w", stdout);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    // cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
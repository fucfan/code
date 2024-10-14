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
const int N = 2e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int q, xor_val;

struct TRIE{
    struct NODE{
        int cnt;
        int val[21];
        int child[2];
    } node[N];

    int cur = 0;

    TRIE() {
        node[cur].cnt = 0;
        mem(node[cur].val, 0);
        mem(node[cur].child, -1);
    }

    int new_node(){
        cur++;
        node[cur].cnt = 0;
        mem(node[cur].val, 0);
        mem(node[cur].child, -1);
        return cur;
    }

    void add_num(int num){
        int pos = 0;
        for(int i = LOG; i >= 0; i--){
            if(node[pos].child[BIT(num, i)] == -1)
                node[pos].child[BIT(num, i)] = new_node();
            pos = node[pos].child[BIT(num, i)];
            node[pos].cnt++;
            for(int j = LOG; j >= 0; j--){
                if(BIT(num, j)) node[pos].val[j]++;
            }
        }
    }

    bool find_num(int num){
        int pos = 0;
        for(int i = LOG; i >= 0; i--){
            if(node[pos].child[BIT(num, i)] == -1) return 0;
            pos = node[pos].child[BIT(num, i)];
        }
        return  (node[pos].cnt != 0);
    }

    bool del_num(int num){
        if(!find_num(num)) return 0;
        int pos = 0;
        for(int i = LOG; i >= 0; i--){
            pos = node[pos].child[BIT(num, i)];
            node[pos].cnt--;
            for(int j = LOG; j >= 0; j--){
                if(BIT(num, j)) node[pos].val[j]--;
            }
        }
        return 1;
    }

    ll get(int num, int k){
        if(!k) return 0;
        ll res = 0;
        int pos = 0;
        int numb = 0;
        for(int i = LOG; i >= 0; i--){
            // cout << res << '\n';
            if(BIT(num, i)){
                int nxt_pos = node[pos].child[1];
                if(nxt_pos == -1 || node[nxt_pos].cnt <= k){
                    if(nxt_pos != -1){
                        for(int j = 0; j <= LOG; j++){
                            if(BIT(num, j))
                                res += (1ll << j) * (node[nxt_pos].cnt - node[nxt_pos].val[j]);
                            else
                                res += (1ll << j) * node[nxt_pos].val[j];
                        }
                        k -= node[nxt_pos].cnt;
                    }
                    // if(i == 2) cout << i << ' ' << node[pos].cnt << '\n';
                    if(!k) return res;
                    pos = node[pos].child[0];
                    
                }
                else{
                    numb += (1 << i);
                    pos = node[pos].child[1];
                }
            }
            else{
                int nxt_pos = node[pos].child[0];
                if((nxt_pos == -1) || (node[nxt_pos].cnt <= k)){
                    if(nxt_pos != -1){
                        for(int j = 0; j <= LOG; j++){
                            if(BIT(num, j))
                                res += (1ll << j) * (node[nxt_pos].cnt - node[nxt_pos].val[j]);
                            else
                                res += (1ll << j) * node[nxt_pos].val[j];
                        }
                        k -= node[nxt_pos].cnt;
                    }
                    // cout << i << ' ' << '\n';
                    if(!k) return res;
                    pos = node[pos].child[1];
                    numb += (1 << i);
                }
                else{
                    pos = node[pos].child[0];
                }
            }
            // cout << k << ' ' << i << ' ' << res << '\n';
        }

        if(k){
            for(int j = 0; j <= LOG; j++){
                if(BIT(num, j))
                    res += (1ll << j) * min(k, (node[pos].cnt - node[pos].val[j]));
                else
                    res += (1ll << j) * min(k, node[pos].val[j]);
            }
        }

        return res;
    }
} trie;

void inp(){
    cin >> q;
}

void solve(){
        // cout << trie.cur << '\n';
        int cnt = 0;
    for(int i = 1; i <= q; i++){
        int type, val;
        cin >> type >> val;
        type++;
        if(type == 1){
            // cout << val << ' ' << xor_val << '\n';
            trie.add_num(val ^ xor_val);
            cnt++;
        }
        if(type == 2){
            cnt -= trie.del_num(val ^ xor_val);
        }
        if(type == 3){
            xor_val ^= val;
        }
        if(type == 4){
            cout << trie.get(xor_val, min(cnt, val)) << '\n';
        }
        // cout << trie.cur << '\n';
    }
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
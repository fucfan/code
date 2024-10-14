#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , dp[N];
string t;
struct Trie{
    struct nodes{
        int child[27];
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
            int c = j - 'a';
            if(node[pos].child[c] == -1) node[pos].child[c] = new_node();
            pos = node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }
    pii find_string(char x , int num){
        // cout << 1 << '\n';
        int c = x - 'a';
        int pos = num;
        // if(node[pos].child[c] == -1) return {0 , 0};
        if(node[pos].child[c] == -1) return {0 , 0};
        pos = node[pos].child[c];
        if(!node[pos].exist) return {pos , 0};
        return {pos , 1};
    }
} trie;
int sol(int i){
    // cout << i << '\n';
    if(i >= t.size()) return 1;
    if(dp[i] != -1) return dp[i];
    pii pos = {0 , 0};
    int res = 0;
    for(int j = i ; j < t.size() ; j++){
        pos = trie.find_string(t[j] , pos.fi);
        // cout << t[j] << ' ' << pos.fi << ' ' << pos.se << '\n';
        // break;
        if(pos.fi && pos.se){
            // cout << s << '\n';
            res += sol(j + 1);
            res %= mod;
        }
        else if(!pos.fi && !pos.se) break;
    }
    return dp[i] = res;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        string s;
        cin >> s;
        trie.add_string(s);
    }
    cin >> t;
}

void solve()
{
    mem(dp , -1);
    cout << sol(0);
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // run_with_file();
    inp();
    solve();
}
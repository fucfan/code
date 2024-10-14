#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
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
        for(auto f : s){
            int c = f - 'a' + 1;
            if(node[pos].child[c] == -1) node[pos].child[c] = new_node();
            pos = node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }
} trie[2];
int n , m;
queue <pair<int , pii>> q;
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        string s;
        cin >> s;
        // cout << s << '\n';
        trie[0].add_string(s);
    }
    cin >> m;
    for(int i = 1 ; i <= m ; i++){
        string s;
        cin >> s;
        // cout << s << '\n';
        trie[1].add_string(s);
    }
}

void solve()
{
    q.push({0 , {0 , 0}});
    while(q.size()){
        int type = q.front().fi;
        int pos[2];
        pos[0] = q.front().se.fi;
        pos[1] = q.front().se.se;
        q.pop();
        bool check = 1;
        for(int i = 1 ; i < 27 ; i++){
            int nxt_node1 = trie[0].node[pos[0]].child[i];
            int nxt_node2 = trie[1].node[pos[1]].child[i];
            // cout << nxt_node1 << ' ' << nxt_node2 << ' ' << i << '\n';
            if(nxt_node1 > 0 && nxt_node2 < 0 && !type){
                cout << "Nina";
                exit(0);
            }
            if(nxt_node1 > 0 && nxt_node2 > 0){
                q.push({1 - type , {nxt_node1 , nxt_node2}});
            }
            if(nxt_node2 > 0) check = 0;
        }
        if(check && type){
            cout << "Nina";
            exit(0);
        }
    }
    cout << "Emilija";
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
    cin.tie(0)->sync_with_stdio(false);
    // run_with_file();
    inp();
    solve();
}

/*      UwU      */
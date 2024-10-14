#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e4 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        //freopen(file".inp", "r" , stdin);
        //freopen(file".out", "w" , stdout);
    }
}

int n , m , k , s , num_student;
int cnt[N];
vector <int> adj[N];
vector <string> student;
map <string , int> check;
// bool path[N][N];
set <int> st[N];

void bfs(){
    queue <int> q;

    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] >= k){
            q.push(i);
        }
    }

    while(q.size()){
        int u = q.front();

        q.pop();

        for(auto v : adj[u]){
            if(cnt[v] >= k) continue;

            if(cnt[u] >= k){
                cnt[v]++;
                if(cnt[v] >= k) q.push(v);
            }
        }
    }

    vector <string> res;

    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] >= k) res.pb(student[i - 1]);
    }

    sort(all(res));

    cout << res.size() << '\n';

    for(auto j : res){
        cout << j << ' ';
    }
}

void inp(){
    cin >> n >> k >> s >> m;
    for(int i = 1 ; i <= s ; i++){
        string s;
        cin >> s;
        student.pb(s);
        cnt[student.size()] = k;
        check[s] = student.size();
    }

    for(int i = 1 ; i <= m ; i++){
        string x , y;
        cin >> x >> y;

        if(!check[x]){
            student.pb(x);
            check[x] = student.size();
        }
        
        if(!check[y]){
            student.pb(y);
            check[y] = student.size();
        }

        int u = check[x];
        int v = check[y];

        if(st[u].count(v)) continue;

        adj[u].pb(v);
        adj[v].pb(u);
        
        st[u].insert(v);
        st[v].insert(u);
    }
}

void solve(){
    bfs();
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
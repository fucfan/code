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
#define add(x , y) ((x) = (x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "research"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , m , type[N] , in[N];
bool vst[N] , vst1[N];
vector <int> adj[N];
queue <int> q[2];

void bfs(){
    int cnt = -1;
    bool check = 0;
    while(q[0].size() || q[1].size()){
        check = 0;

        while(q[0].size()){
            int u = q[0].front();
            q[0].pop();
            if(vst1[u]) continue;
            check = 1;
            vst1[u] = 1;
            for(auto v : adj[u]){
                if(vst[v]) continue;
                in[v]--;
                if(!in[v]){
                    vst[v] = 1;  
                    if(type[v] == 2){
                        q[0].push(v);
                        q[1].push(v);
                    }
                    else q[type[v]].push(v);
                }
            }
        }

        cnt += check;

        check = 0;

        while(q[1].size()){
            int u = q[1].front();
            q[1].pop();
            if(vst1[u]) continue;
            vst1[u] = 1;
            check = 1;
            for(auto v : adj[u]){
                if(vst[v]) continue;
                in[v]--;
                if(!in[v]){
                    vst[v] = 1;  
                    if(type[v] == 2){
                        q[0].push(v);
                        q[1].push(v);
                    }
                    else q[type[v]].push(v);
                }
            }
        }
        
        cnt += check;
    }

    for(int i = 1 ; i <= n ; i++){
        if(!vst1[i]){
            cout << -1;
            exit(0);
        }
    }

    cout << cnt;
}

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        char x;
        cin >> x;
        type[i] = x - 'A';
    }
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        in[v]++;
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        if(!in[i]){
            if(type[i] == 2){
                q[0].push(i);
                q[1].push(i);
            }
            else q[type[i]].push(i);
        }
    }

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
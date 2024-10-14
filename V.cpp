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
#define file "V"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , w[N] , st[N] , en[N];
ll t , b[N] , g[N];
vector <int> adj[N] , tour;
ll ans;
int len = oo;
vector <ll> res , tmp1; 

bool cmp(int a , int b){
    if(w[a] == w[b]) return g[a] < g[b];
    return w[a] < w[b];
}

void dfs(int i , int p){
    tour.pb(i);
    st[i] = tour.size() - 1;

    for(auto j : adj[i]){
        if(j == p) continue;
        dfs(j , i);
    }

    en[i] = tour.size() - 1;
}

void prepare(){
    dfs(1 , 0);
}

void inp(){
    cin >> n >> t;
    for(int i = 2 ; i <= n ; i++){
        int x;
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    for(int i = 1 ; i <= n ; i++) cin >> w[i];
    for(int j = 1 ; j <= n ; j++) cin >> b[j];
    for(int i = 1 ; i <= n ; i++) cin >> g[i];
}

void solve(){
    prepare();
    priority_queue <pii , vector <pii> , greater<pii>> q;
    for(int i = 1 ; i <= n ; i++){
        q.push({en[i] - st[i] + 1 , i});
    }

    vector <int> tmp;

    tmp = tour;

    while(q.size()){
        int u = q.top().se;
        // cout << u << '\n';
        q.pop();

        // cout << u << ' ' << st[u] << ' ' << en[u] << ' ' << b[u] << '\n';

        // for(auto j : tmp) cout << j << ' ';
        // nl;
        // for(auto j : tmp) cout << w[j] << ' ';
        // nl;
        // for(auto j : tmp) cout << g[j] << ' ';
        // nl;

        sort(tmp.begin() + st[u] , tmp.begin() + en[u] + 1 , cmp);

        ll sum = 0;
        int length = 0;

        for(int i = st[u] ; i <= en[u] ; i++){
            if(sum + w[tmp[i]] > t) break;
            length++;
            sum += w[tmp[i]];
        }

        ll val = b[u] + 1ll * length * length;

        if(val > ans){
            ans = val;
            len = length;
            res.clear();
            for(int i = st[u] ; i <= st[u] + length - 1 ; i++){
                res.pb(g[tmp[i]]);
            }

            sort(all(res));
        }
        else if(val == ans){
            if(length < len){
                len = length;
                res.clear();
                for(int i = st[u] ; i <= st[u] + length - 1 ; i++){
                    res.pb(g[tmp[i]]);
                }

                sort(all(res));
            }
            else if(length == len){
                tmp1.clear();
                for(int i = st[u] ; i <= st[u] + length - 1 ; i++){
                    tmp1.pb(g[tmp[i]]);
                }

                sort(all(tmp1));
                if(res > tmp1) res = tmp1;
            }
        }
    }

    cout << ans << ' ' << len << '\n';
    for(auto j : res) cout << j << ' ';
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
    int O;
    cin >> O >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
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
int n , m , a , b , d , par[N] , last[N];
vector <int> x[N] , topo;
bool vst[N] ;
queue <int> q , ans;

void inp()
{
    cin >> n >> m ;
    for(int i = 1 ; i <= m ; i++){
        cin >> a >> b ;
        x[a].pb(b);
        par[b]++;
    }
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        if(par[i] == 0){
            q.push(i);
            vst[i] = true;
        }
    }
    while(!q.empty()){
        a = q.front();
        q.pop();
        ans.push(a);
        topo.pb(a);
        for(auto j : x[a]){
            if(par[j] > 0) par[j]--;
            if(par[j] == 0 && !vst[j]){
                q.push(j);
                vst[j] = true;
            }
        }
    }
    d = 1;
    while(!ans.empty()){
        a = ans.front();
        last[a] = d; 
        d++;
        ans.pop();
    }
    for(int i = 1 ; i <= n ; i++){
        // last[topo[i - 1]] = i;
        cout << topo[i - 1] << " ";
    }
    // for(int i = 1 ; i <= n ; i++){
    //     cout << last[i] << " ";
    // }
}

void run_with_file()
{
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
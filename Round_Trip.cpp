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
int n , m , a , b , par[N] , d;
vector <int> x[N];
bool vst[N];
void dfs(int i , int k){
    vst[i] = true;
    for(auto j : x[i]){
        if(!vst[j]){
            par[j] = i;
            dfs(j , i);
        }
        else if(j != k){
            for(int h = i ; h != par[j] ; h = par[h]){
                d++;
            }
            cout << d << '\n';
            cout << j  << " ";
            for(int h = i ; h != par[j] ; h = par[h]){
                cout << h << " " ;
            }
            exit(0);
        }
    }
}
void inp()
{
    cin >> n >> m;
    d = 1;
    for(int i = 1 ; i <= m ; i++){
        cin >> a >> b;
        x[a].pb(b);
        x[b].pb(a);
    }
    mem(par , -1);
}

void solve()
{
    for(int i = 1 ;i <= n ; i++){
        if(!vst[i]){
            dfs(i , -1);
        }
    }
    cout << "IMPOSSIBLE";
}

// void run_with_file()
// {
//     freopen(file".inp", "r", stdin);
//     freopen(file".out", "w", stdout);
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // run_with_file();
    inp();
    solve();
}
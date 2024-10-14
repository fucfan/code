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
int n , m , x , y;
stack <int> topo , ans;
int cor[N] , way[N] , cnt , g , f;
vector <int> X[N];
queue <int> SORT;
bool check[N];
void DFS(int k){
    cor[k] = 1;
    check[k] = true;
    sort(X[k].begin() , X[k].end());
    reverse(X[k].begin() , X[k].end());
    for(auto j : X[k]){
        if(cor[j] == 0){
            DFS(j);
        }
        else{
            if(cor[j] == 1){
                cout << "Sandro fails.\n" ;
                exit(0);
            }
        }
    }
    cor[k] = 2;
    topo.push(k);
}
void inp()
{
    cin >> n >> m ;
    for(int i = 1 ; i <= m ; i++){
        cin >> x >> y;
        X[x].pb(y);
        way[y]++;
    }
    memset(cor , 0 , sizeof(cor));
}

void solve()
{   
    cnt = 1;
    for(int i = n ; i >= 1 ; i--){
        if(!check[i]){
            DFS(i);
        }
    }
    while(!topo.empty()){
        cout << topo.top() << ' ';
        topo.pop();
        if(topo.empty()) cout << '\n';
    }
}

void run_with_file()
{
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
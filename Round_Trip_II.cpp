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
int n , m , a , b , cor[N] , trace[N] , cnt;
stack <int> ans;
vector <int> x[N];
void DFS(int s){
    cor[s] = 1;
    for(auto i : x[s]){
        if(cor[i] == 0 && i != s){
            trace[i] = s;
            DFS(i);
        }
        if(cor[i] == 1 && i != s){
            for(int k = s ; k != -1 ; k = trace[k]){
                cnt++;
                ans.push(k);
                if(k == i) break; 
            }
            cout << cnt + 1 << '\n';
            while(!ans.empty()){
                cout << ans.top() << " ";
                ans.pop();
            }
            cout << i << " ";
            exit(0);
        }
    }
    cor[s] = 2;
}
void inp()
{
    cin >> n >> m ;
    for(int i = 1; i <= m ; i++){
        cin >> a >> b;
        x[a].pb(b);
    }
}

void solve()
{
    mem(cor , 0);
    mem(trace , -1);
    for(int i = 1 ; i <= n ; i++){
        if(cor[i] == 0){
            DFS(i);
        }
    }
    cout << "IMPOSSIBLE";
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
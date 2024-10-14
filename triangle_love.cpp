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
int t , n , p[105] , cor[105] , h[105];
bool check;
void dfs(int i){
    if(cor[p[i]] == 2) return;
    cor[i] = 1;
    if(cor[p[i]] == 1){
        if(h[i] - h[p[i]] == 2) check = true;
        cor[i] = 2;
        return;
    }
    h[p[i]] = h[i] + 1;
    dfs(p[i]);
    cor[i] = 2;
}
void sol(){
    check = false;
    for(int i = 1 ; i <= n ; i++){
        if(!cor[i]) dfs(i);
    }
    if(check) cout << "<3\n";
    else cout << "</3\n";
}
void inp()
{
    cin >> t;
    for(int i = 1 ; i <= t ; i++){
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> p[i];
        }
        mem(cor , 0);
        mem(h , 0);
        sol();
    }
}

void solve()
{
    
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
    run_with_file();
    inp();
    solve();
}
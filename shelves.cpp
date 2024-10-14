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
#define file "shelves"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
int n , m , a[N] , b[N] , cnta , cntb;
ll prefa[N] , prefb[N];
vector <int> ans1 , ans2;
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        // a[i] = rand() % 10;
        prefa[i] = prefa[i - 1] + a[i];
    }
    for(int i = 1 ; i <= m; i++){
        cin >> b[i];
        // b[i] = rand() % 10;
        prefb[i] = prefb[i - 1] + b[i]; 
    }
    // for(int i = 1 ; i <= n ; i++){
    //     cout << a[i] <<  ' ';
    // }
    // nl;
    // for(int i = 1 ; i <= m ; i++){
    //     cout << b[i] <<  ' ';
    // }
    // nl;
}

void solve()
{
    int i = 1;
    int j = 1;
    int high = 0;
    while(i <= n || j <= m){
        if((a[i] < b[j] && i <= n) || j > m){
            high = prefa[i];
            cnta++;
            ans1.pb(i);
            i++;
            while(prefb[j] - high < b[j] && j <= m) j++;
            // i++;
            // cout << j << '\n';
        }
        else{
            if((a[i] >= b[j] && j <= m) || i > n){
                high = prefb[j];
                cntb++;
                ans2.pb(j);
                j++;
                while(prefa[i] - high < a[i] && i <= n) i++;
                // j++;
            }
        }
        // cout << high << ' ' << prefa[i] << ' ' << prefb[j] << '\n';
        // cout << i << ' ' << j << '\n';
        // if(prefb[i] - high) j++;
    }
    cout << cnta << ' ' << cntb << '\n';
    for(auto j : ans1){
        cout << j << ' ';
    }
    nl;
    for(auto j : ans2){
        cout << j << ' ';
    }
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
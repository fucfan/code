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
int a[10][10] , cnt , ans;
pii b[11];
void inp()
{
    cnt = 1;
    for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            cin >> a[i][j];
            b[cnt] = {i , j};
            cnt++;
        }
    }
}

void solve()
{
    for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            if(b[a[i][j]].fi != i){
                cout << b[a[i][j]].fi << '\n';
                cout << a[i][j] << ' ' << a[b[a[i][j]].fi][j] << '\n';
                swap(a[i][j] , a[b[a[i][j]].fi][j]);
                ans++;
            }
        }
    }
    for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            if(b[a[i][j]].se != j){
                cout << b[a[i][j]].se << '\n';
                cout << a[i][j] << ' ' << a[i][b[a[i][j]].se] << '\n';
                swap(a[i][j] , a[i][b[a[i][j]].se]);
                ans++;
            }
        }
    }
    cout << ans;
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
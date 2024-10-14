#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int n , m;
pair <vector <int> , int> a[N];
int lis[N];
vector <int> res[N];

bool cmp(pair <vector <int>, int> &a, pair <vector <int>, int> &b){
    for(int i = 1; i <= m; i++){
        if(a.fi[i] > b.fi[i]) return false;
        else if(a.fi[i] < b.fi[i]) return true;
    }
    return true;
}

bool merge(int x , int y){
    for(int i = 1 ; i <= m ; i++){
        // cout << x << ' ' << y << ' ' << a[x][i] << ' ' << a[y][i] << ' ' << check1 << ' ' << check2 << '\n';
        if(a[x].fi[i] > a[y].fi[i]) return 0;
    }

    // cout << x << ' ' << y << ' ' << check1 << ' ' << check2 << '\n';

    return 1;
}

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        a[i].fi.pb(0);
        for(int j = 1 ; j <= m ; j++){
            int x;
            cin >> x;
            a[i].fi.pb(x);
        }
        sort(all(a[i].fi));

        a[i].se = i;
    }
}

void solve(){
    sort(a + 1 , a + 1 + n , cmp);

    int ans = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j < i ; j++){
            if(merge(j , i)){
                // cout << i << ' ' << j << ' ' << merge( , j) << '\n';

                lis[a[i].se] = max(lis[a[j].se] + 1 , lis[a[i].se]);
                ans = max(ans , lis[a[j].se] + 1);
            }
        }           
    }

    for(int i = 1 ; i <= n ; i++) res[lis[i]].pb(i);
    cout << ans + 1 << '\n';
    for(int i = 0 ; i <= ans ; i++){
        cout << res[i].size() << ' ';
        for(auto j : res[i]) cout << j << ' ';
        nl;
    }
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
    inp();
    solve();
}

/*      UMU      */
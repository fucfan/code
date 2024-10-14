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
#define file "rline"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
int n , s , del , sub[N];
pii a[N];
bool cmp(pii a , pii b){
    if(a.fi == b.fi){
        return a.se < b.se;
    }
    return a.fi < b.fi;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1 , a + n + 1 , cmp);
}

void solve()
{
    for(int i = 1 ; i <= n ; i++){
        sub[i] = a[i].se - a[i].fi;
    }
    for(int i = 2 ; i <= n ; i++){
        if(a[i].fi < a[i - 1].se){
            sub[i - 1] = sub[i - 1] - (a[i - 1].se - a[i].fi);
            sub[i] = sub[i] - (a[i - 1].se - a[i].fi);
        }
    }
    int minx , maxx;
    minx = a[1].fi;
    maxx = a[1].se;
    s = maxx - minx;    
    for(int i = 2 ; i <= n ; i++){
        if(a[i].se > maxx){
            int x = a[i].se - maxx;
            int y = a[i].fi - maxx;
            if(x > 0) s += x;
            if(y > 0) s -= y;
            maxx = max(a[i].se , maxx);
        }
    }
    del = 1e9;
    for(int i = 1 ; i <= n ; i++){
        del = min(del , sub[i]);
        if(sub[i] <= 0){
            cout << s;
            exit(0);
        }
    }
    cout << s - del;
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
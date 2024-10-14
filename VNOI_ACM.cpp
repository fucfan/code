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
ll a , b ;
int n , an , bn;
vector <ll> ansa , ansb;
pair <ll , pair <ll , ll>> x[1000000];
void inp()
{
    cin >> n;
    n = n * 2;
    for(int i = 1 ; i <= n ; i++){
        cin >> a >> b;
        x[i].se.fi = a;
        x[i].se.se = b;
        x[i].fi = abs(a - b);
    }
    sort(x + 1 , x + 1 + n);
    reverse(x + 1 , x + 1 + n);
}

void solve()
{
    a = an = 0;
    b = bn = 0;
    for(int i = 1 ; i <= n ; i++){
        if(x[i].se.fi < x[i].se.se){
            if(an < n / 2){
                an++;
                a = a + x[i].se.fi; 
                ansa.pb(x[i].se.fi);
            }
            else{
                bn++;
                b = b + x[i].se.se;
                ansb.pb(x[i].se.se);
            }
        }
        else{
            if(bn < n / 2){
                bn++;
                ansb.pb(x[i].se.se);
                b = b + x[i].se.se;
            }
            else{
                an++;
                ansa.pb(x[i].se.fi);
                a = a + x[i].se.fi;
            }   
        }
    }
    cout << a + b;
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
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
#define file "schedule"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , sum1 , sum2 , l , r;
pair <ll , ll> t[N];
bool cmp(pair <ll , ll> a,pair <ll , ll> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> t[i].fi >> t[i].se;
    }
    sort(t + 1 , t + 1 + n , cmp);
}

void solve()
{
    // r = 1;
    // for(int i = 2 ; i <= n + 1 ; i++){
    //     if(t[r].fi != t[i].fi){
    //         l = r;
    //         r = i;
    //         sort(t + l , t + r , cmp);
    //     }
    // }
    // for(int i = 1 ; i <= n ; i++){
        // cout << t[i].fi << ' ' << t[i].se << '\n';
    // }
    // reverse(t + 1 , t + 1 + n);
    for(int i = 1 ; i <= n ; i++){
        sum1 = sum1 + t[i].fi;
        if(sum2 < sum1) sum2 = sum1 + t[i].se;
        else{
            if(sum2 - sum1 < t[i].se) sum2 = sum2 + (t[i].se - (sum2 - sum1));
        }
        // cout << sum1 << ' ' << sum2 << '\n';
    }
    cout << sum2;
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
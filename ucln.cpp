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
int t , n , a[N];
vector <int> ans;
void inp()
{
    cin >> t;
    for(int g = 1 ; g <= t ; g++){
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = i + 1 ; j <= n ; j++){
                ans.pb(__gcd(a[j] , a[i]));
            }
        }
        sort(all(ans));
        reverse(all(ans));
        cout << ans[1] << '\n';
        ans.clear();
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
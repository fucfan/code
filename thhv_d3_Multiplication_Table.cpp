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
const int N = 2e6 + 5;
ll n , ans , cnt , a[N];
void inp()
{
    cin >> n;
}

void solve()
{
    cnt = 1;
    for(ll i = 1 ; i <= n ; i++){
        if(i != (n - i + 1)){
            a[cnt] = a[cnt + 1] = i * (n - i + 1);
            cnt += 2;
            if(cnt >= n) break;
        }
        else{
            a[cnt] = i * i;
            cnt++;
        }
    }
    cout << a[(cnt - 1) / 2 + ((cnt - 1) % 2)];
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
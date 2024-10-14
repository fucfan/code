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
int n , m , ch ,cnt5 , cnt;
void inp()
{
    cin >> m;
    for(int i = 1 ; i <= m ; i++){
        cin >> n;
        while(n % 10 == 0 ){
            cnt++;
            n = n / 10;
        }
        while(n % 5 == 0){
            cnt5++;
            n = n / 5;
        }
        while(n % 2 == 0){
            ch++;
            n = n / 2;
        }
    }
}

void solve()
{
    cnt = cnt + min(cnt5 , ch);
    cout << cnt;
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
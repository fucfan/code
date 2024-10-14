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
long n , cnt;
ll res;
queue <int> ans;
void inp()
{
    cin >> n;
}

void solve()
{
    while(n != 0){
        ans.push(n % 2);
        n = n / 2;
    }
    while(!ans.empty()){
        if(ans.front() == 1){
            res = pow(2 , cnt);
            cout << res << ' ';
        }
        cnt++;
        ans.pop();
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
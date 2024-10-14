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
int n , a , b;
bool vst[N];
vector <int> ans;
void inp()
{
    cin >> n;
    ans.pb(0);
}

void solve()
{   
    for(int i = sqrt(n) ; i >= 1 ; i++){
        if(n % i == 0){
            a = i;
            b = n / i ;
            ans.pb(a);
            ans.pb(b);
            a--; b++;
            while(a != 0){
                if(!vst[a * b]){
                    ans.pb(a * b);
                    vst[a * b] = true;
                }
                a--; b++;
            }
            break;
        }
    }
    for(auto j : ans){
        cout << j << " ";
    }
}

void run_with_file()
{
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
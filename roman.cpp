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
map <char , int> ROM;
long ans;
string s;
void inp()
{
    cin >> s;
}

void solve()
{
    ROM['I'] = 1;
    ROM['V'] = 5;
    ROM['X'] = 10;
    ROM['L'] = 50;
    ROM['C'] = 100;
    ROM['D'] = 500;
    ROM['M'] = 1000;
    ans = ans + ROM[s[s.size() - 1]];
    for(int i = s.length() - 2 ; i >= 0 ; i--){
        if(ROM[s[i]] < ROM[s[i + 1]]){
            while(ROM[s[i]] < ROM[s[i + 1]]){
                ans = ans - ROM[s[i]];
                i--;
            }
            i++;
        }
        else ans = ans + ROM[s[i]];
    }
    cout << ans;
}

void run_with_file()
{
//    if(fopen(file".inp","r")){
//        freopen(file".inp","r", stdin);
//        freopen(file".out", "w", stdout);
//    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
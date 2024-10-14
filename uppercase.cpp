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
string s , s1[N] , ans;
void inp()
{
    getline(cin , s);
    for(int)
}

void solve()
{
    s = ' ' + s;
    // cout << s.size();
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == 32) {if(s[i + 1] >= 97 && s[i + 1] <= 122) s[i + 1] = s[i + 1] - 32;}
        else ans = ans + s[i];
    }
    cout << ans;
}

void run_with_file()
{
//    if(fopen(file".inp","r")){
//        freopen(file".inp","r", stdin);
//        freopen(file".out"a, "w", stdout);
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

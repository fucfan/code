#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define ppi pair<pii, pii>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e4 + 5;
const int base = 31;
string s;
int q;
pii st[2][4 * N] , en[2][4 * N];
void inp()
{
    cin >> s;
    cin >> q;
    int n = s.size();
    s = " " + s;
    for(int i = 1 ; i <= q ; i++){
        int type;
        cin >> type;
        if(type == 1){
            int pos;
            char x;
            cin >> pos >> x;
            s[pos] = x;
        }
        if(type == 2){
            int l , r;
            cin >> l >> r;
            int ans = 0;
            for(int i = l + 1 ; i <= r ; i++){
                if(s[i] != s[i - 1]){
                    ans++;
                    i++;
                }
            }
            cout << ans << '\n';
        }
    }
}

void solve()
{
    
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
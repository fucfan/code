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
#define file "thesis"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
string s;
void inp()
{
    cin >> n;
    cin >> s;
    s = " " + s;
}

void solve()
{
    stack <pair<char , int>> st;
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(s[i] == 'T' && i % 2 == 0){
            if(st.empty()) st.push({s[i] , i});
            else{
                if(st.top().fi == s[i]) st.push({s[i] , i});
                else{
                    ans += i - st.top().se;
                    st.pop();
                }
            }
        }
        else if(s[i] == 'F' && i % 2 == 1){
            if(st.empty()) st.push({s[i] , i});
            else{
                if(st.top().fi == s[i]) st.push({s[i] , i});
                else{
                    ans += i - st.top().se;
                    st.pop();
                }
            }
        }
    }
    cout << ans;
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
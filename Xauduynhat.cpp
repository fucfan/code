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
const int N = 5e5 + 5;
string s;
int cnt , ans , k , g;
bool kt[N];
bool check[N];
void sol(int i){
    cnt = 0;
    g = i;
    mem(check , false);
    for(int j = i ; j < s.length() ; j++){
        if(!check[s[j]]){
            check[s[j]] = true;
            cnt++;
            ans = max(ans , cnt);
        }
        else{
            k = g;
            while(s[k] != s[j]){
                check[s[k]] = false;
                k++;
                cnt--;
            }
            g = k + 1;
        }
    }
}
void inp()
{
    cin >> s;
}

void solve()
{
    sol(0);
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
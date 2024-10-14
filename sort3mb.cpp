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
#define file "sort3mb"
using namespace std;

int n;
string t;
vector <string> s1;
vector <string> s2;

void inp()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> t;
        if(t.size() == 4){
            s1.pb("");
            for(int j = 0 ; j < t.size() ; j++)
                if(t[j] != '.') s1.back() = s1.back() + t[j];
        }
        if(t.size() == 5){
            s2.pb("");
            for(int j = 0 ; j < t.size() ; j++)
                if(t[j] != '.' && t[j] != '-') s2.back() = s2.back() + t[j];
        }
    }
}

void solve()
{
    sort(all(s1));
    sort(all(s2));

    reverse(all(s2));

    if(s2.size())
        for(auto j : s2)
            cout << '-' << j[0] << '.' << j[1] << j[2] << ' ';

    if(s1.size()){
        for(auto j : s1)
            cout << j[0] << '.' << j[1] << j[2] << ' ';
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
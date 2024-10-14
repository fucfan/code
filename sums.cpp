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
string s;
int n;
long f[107][107][107][107];
int trau(int i , int pos , int l , int h){
    if(i > n ){ 
        return h - l;
    }
    long &ans = f[i][pos][l][h];
    if(ans != -1) return ans;
    ans = 0;
    ans =  ans + trau(i + 1 , pos , l , h);
    if(s[i] == 'L'){
        --pos ;
    }
    else ++pos;
    l = min(l , pos);
    h = max(h , pos);
    ans = ans + trau(i + 1 , pos , l , h);
    f[i][pos][l][h] = ans;
    return ans;
}
void inp()
{
    cin >> s;
    n = s.length();
    s = " " + s;
}

void solve()
{
    mem(f , -1);
    cout << trau(1 , 0 , 0 , 0);
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
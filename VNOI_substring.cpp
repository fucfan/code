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
string a , b;
long long hashA[1000007] , hashB;
void inp()
{
    cin >> a >> b;
    for(int i = 0 ; i < b.size() ; i++){
        hashB = hashB * base + (b[i] - 'a' + 1);
    }
    for(int i = 0 ; i <)
}

void solve()
{
    
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
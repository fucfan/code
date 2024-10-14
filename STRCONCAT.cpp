#include <bits/stdc++.h>
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
#define file "phuc"
using namespace std;

const int oo = 1e9 + 7;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int base = 27;
int n, m, k;
ll hashT[1000007], hashP[10000007], POW[1000007] , cnt , ans[1000007];
vector <string> P;
bool vst[1000007];
string T , S;
ll gh(long i , long j){
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}
void inp()
{
    P.push_back(" ");
    cin >> n >> m;
    k = n / m;
    cin >> T;
    T = " " + T;
    for (int i = 1; i <= m; i++)
    {
        cin >> S;
        P.push_back(S);
        P[i] = " " + P[i];
    }
}

void solve()
{
    POW[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        POW[i] = (POW[i - 1] * base) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        hashT[i] = (hashT[i - 1] * base + T[i] - 'a' + 1) % MOD;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            hashP[i] = (hashP[i] * base + P[i][j] - 'a' + 1) % MOD;
        }
    }
    for(int i = 1 ; i <= n - k + 1 ; i = i + k){    
        for(int j = m ; j >= 1 ; j--){
            if(gh(i , i + k - 1) == hashP[j] && !vst[j]){
                vst[j] = true;
                cnt++;
                ans[cnt] = j;
                cout << j << " ";
                break; 
            }
        }
    }
}

void run_with_file()
{
    freopen(file ".inp", "r", stdin);
    freopen(file ".out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
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
int n;
ll k;
struct matrix{
    int n , m;
    vector <vector <int>> x;

    matrix(int n = 0 , int m = 0) : n{n} , m{m} , x(n , vector<int>(m , 0)) {}
    matrix(const vector<vector<int>> &d) : x{d} {
        n = x.size();
        m = x[0].size();
    }
    vector<int>& operator[] (int i){
        return x[i];
    }
    matrix operator* (matrix b){
        matrix &a = *this;
        assert(a.m == b.n);
        matrix c(a.n , b.m);
        for(int i = 0 ; i < c.n ; i++){
            for(int j = 0 ; j < c.m ; j++){
                for(int k = 0 ; k < a.m ; k++){
                    (c[i][j] += 1ll * a[i][k] * b[k][j] % mod) %= mod;
                }
            }
        }
        return c;
    }
    void operator *= (matrix b){
        matrix &a = *this;
        a = a * b;
    }
    matrix pow(ll k){
        assert(k > 0);
        k--;
        matrix ans = (*this), tmp = ans;
        while(k){
            if(k & 1) ans *= tmp;
            k >>= 1;
            tmp *= tmp;
        }
        return ans;
    }
};
matrix adj(51 , 51);
void inp()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> adj[i][j];
        }
    }
}

void solve()
{
    ll ans = 0;
    adj = adj.pow(k);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ans += adj[i][j];
            ans %= mod;
        }
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
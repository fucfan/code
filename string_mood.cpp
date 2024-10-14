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
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
struct matrix{
    int n , m;
    vector <vector <int>> x;
    matrix(int n = 0 , int m = 0) : n{n} , m{m} , x(n , vector<int>(m , 0)) {}
    matrix(const vector<vector<int>> &d) : x{d}{
        n = x.size();
        m = x[0].size();
    }
    vector<int>& operator[](int i){
        return x[i];
    }
    matrix operator*(matrix b){
        matrix &a = *this;
        assert(a.m == b.n);
        matrix c(a.n , b.m);
        for(int i = 0 ; i < c.n ; i++){
            for(int j = 0 ; j < c.m ; j++){
                for(int k = 0 ; k < a.m ; k++){
                    c[i][j] += (1ll * a[i][k] * b[k][j] + mod * mod) % mod;
                    c[i][j] = (c[i][j] + (1ll * mod * mod)) % mod;
                }
            }
        }
        return c;
    }
    void operator*=(matrix b){
        matrix &a = *this;
        a = a * b;
    }
    matrix pow(ll k){
        assert(k > 0);
        k--;
        matrix ans = *this , tmp = ans;
        while(k){
            if(k & 1) ans *= tmp;
            k >>= 1;
            tmp *= tmp;
        }
        return ans;
    }
};
ll n;
matrix a(2 , 2);
matrix b(2 , 1);
void inp()
{
    cin >> n;
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = -338;
    a[1][1] = 39;
    b[0][0] = 19;
    b[1][0] = 403;
}

void solve()
{
    if(n - 2 < 1){
        cout << b[n - 1][0];
        exit(0);
    }
    // cout << a.m << ' ' << b.n;
    a = a.pow(n - 2);
    a *= b;
    cout << a[1][0];
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
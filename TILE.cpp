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
#define file "tile"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
struct matrix{
    int n , m;
    vector <vector<ll>> x;
    matrix(int n = 0 , int m = 0) : n{n} , m{m} , x(n , vector<ll> (m , 0)) {};
    matrix(const vector<ll>& d) : x{d}{
        n = x.size();
        m = x[0].size();
    }
    vector<ll>& operator[](int i){
        return x[i];
    }
    matrix operator*(matrix b){
        matrix a = *this;
        assert(a.m == b.n);
        matrix c(a.n , b.m);
        for(int i = 0 ; i < c.n ; i++){
            for(int j = 0 ; j < c.m ; j++){
                for(int k = 0 ; k < a.m ; k++){
                    (c[i][j] += (1ll * a[i][k] * b[k][j])) %= mod;
                }
            }
        }
        return c;
    }
    void operator*= (matrix b){
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
int t;
ll n;
void inp()
{
    cin >> t;
    matrix st(1 , 2);
    st[0][0] = 0; 
    st[0][1] = 1;
    matrix up(2 , 2);
    up[0][1] = 2;
    up[1][0] = up[1][1] = 1;
    for(int g = 1 ; g <= t ; g++){
        cin >> n;
        matrix ans = st * up.pow(n);
        cout << ans[0][1] << '\n';
    }
}

void solve()
{

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
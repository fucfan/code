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
string n;
struct matrix{
    int n , m;
    vector <vector<ll>> x;
    matrix(int n = 0 , int m = 0) : n{n} , m{m} , x(n , vector<ll>(m , 0)){}
    matrix(const vector<vector<ll>> &d) : x{d}{
        n = x.size();
        m = x[0].size();
    }
    vector<ll>& operator[](int i){
        return x[i];
    }
    matrix operator* (matrix b){
        matrix &a = *this;
        assert(a.m == b.n);
        matrix c(a.n , b.m);
        for(int i = 0 ; i < c.n ; i++){
            for(int j = 0 ; j < c.m ; j++){
                for(int k = 0 ; k < a.m ; k++){
                    (c[i][j] += ((1ll * a[i][k] * b[k][j]) + (mod * mod)) % mod) %= mod;
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
} up(2 , 2);
void inp()
{
    cin >> n;
    up[0][0] = 0;
    up[0][1] = up[1][0] = up[1][1] = 1;
}

void solve()
{
    matrix st = up;
    up = up.pow(n[0] - '0');
    // cout << n[0] - '0' << '\n';
    // for(int i = 0 ; i < 2 ; i++){
    //     for(int j = 0 ; j < 2 ; j++){
    //         cout << up[i][j] << ' ';
    //     }
    //     nl;
    // }
    for(int i = 1 ; i < n.size() ; i++){
        matrix g = up;
        for(int i = 2 ; i <= 10 ; i++){
            up *= g;
    // for(int i = 0 ; i < 2 ; i++){
    //     for(int j = 0 ; j < 2 ; j++){
    //         cout << up[i][j] << ' ';
    //     }
    //     nl;
    // }
    // nl;
        }
        if(n[i] != '0') up *= st.pow(n[i] - '0');
    }
    // for(int i = 0 ; i < 2 ; i++){
    //     for(int j = 0 ; j < 2 ; j++){
    //         cout << up[i][j] << ' ';
    //     }
    //     nl;
    // }
    matrix ans(2 , 1);
    ans[0][0] = 3;
    ans[1][0] = -1;
    up *= ans;
    cout << up[1][0];
}

void run_with_file()
{
   if(fopen(file".inp","r")){
    //    freopen(file".inp","r", stdin);
    //    freopen(file".out", "w", stdout);
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
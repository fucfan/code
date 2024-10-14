#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define add(x , y) (x) = ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
#define file "wpumps"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , a[N] , m;

struct matrix{
    int n , m;
    vector <vector <int>> x;

    matrix(int n = 0 , int m = 0) : n{n} , m{m} , x(n , vector <int> (m , 0)) {};

    matrix(const vector<vector<int>> &d) : x{d}{
        n = x.size();
        m = x[0].size();
    }

    vector<int> &operator[](int i){
        return x[i];
    }

    matrix operator*(matrix b){
        matrix a = *this;

        assert(a.m == b.n);

        matrix c(a.n , b.m);
        for(int i = 0 ; i < c.n ; i++){
            for(int j = 0 ; j < c.m ; j++){
                for(int k = 0 ; k < a.m ; k++){
                    add(c[i][j] , (1ll * a[i][k] * b[k][j]) % mod);
                    // (c[i][j] += (a[i][k] + b[k][j]) % mod) %= mod;
                    // cout << c[i][j] << '\n';
                }
            }
        }

        return c;
    }

    void operator*=(matrix b){
        matrix &a = *this;
        a = a * b;
    }

    matrix Pow(ll k){
        assert(k > 0);
        k--;

        matrix ans = *this , tmp = ans;

        while(k){
            if(k & 1) ans *= tmp;
            tmp *= tmp;
            k >>= 1;
        }

        return ans;
    }

    void print(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++) cout << x[i][j] << ' ';
                nl;
        }
    }
};

void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    cin >> m;
}

void solve()
{
    matrix st(1 , n);
    matrix up(n , n);

    for(int i = 1 ; i <= n ; i++) st[0][i - 1] = a[i];
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++) up[i][j] = 1;
    }

    // st.print();

    st *= up.Pow(m);

    st.print();

    // for(int i = 0 ; i < n ; i++) cout << st[0][i] << ' ';
}

void run_with_file()
{
    if (fopen(file".inp", "r"))
    {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
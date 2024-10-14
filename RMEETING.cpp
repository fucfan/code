#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "rmeeting"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int cnt = 0;

struct matrix{
    int n , m;
    vector <vector<int>> x;

    matrix(int n = 0 , int m = 0) : n{n} , m{m} , x(n , vector<int>(m , 0)) {};

    matrix(const vector<vector <int>> &d) : x{d} {
        n = x.size();
        m = x[0].size();
    }

    vector <int> &operator[](int i){
        return x[i];
    }

    matrix operator*(matrix b){
        matrix a = *this;
        matrix c(a.n , b.m);
        for(int i = 0 ; i < c.n ; i++){
            for(int j = 0 ; j < c.m ; j++){
                for(int k = 0 ; k < a.m ; k++){
                    cnt++;
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    bool ok(matrix b , int mx){
        matrix a = *this;
        matrix c(a.n , b.m);

        for(int i = 0 ; i < c.n ; i++){
            for(int j = 0 ; j < c.m ; j++){
                for(int k = 0 ; k < a.m ; k++){
                    c[i][j] += a[i][k] * b[k][j];
                    if(c[i][j] >= mx) return 1;
                }
            }
        }

        return 0;
    }

    void operator*=(matrix b){
        matrix &a = *this;
        a = a * b;
    }

    matrix Pow(int k){
        assert(k > 0);
        k--;

        matrix ans = *this , tmp = ans;

        while(k){
            // cout << k << "gg\n";    
            if(k & 1) ans *= tmp;
            tmp *= tmp;
            k >>= 1;
        }

        return ans;
    }

    void print(){
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                cout << x[i][j] << ' ';
            }
            nl;
        }
        nl;
    }
};

int n , m , q , sz;
vector <matrix> pw;
matrix adj;

void prepare(){
    // adj.print();
    for(int i = 1 ; i <= sz + 1 ; i++) pw.pb(adj);
    for(int i = 2 ; i <= sz ; i++){
        pw[i] *= pw[i - 1];
        // pw[i].print();
    }
}

void inp(){
    cin >> n >> m;

    matrix tmp(n + 1 , n + 1);
    adj = tmp;

    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    sz = ((n + 1) / 2) * ((n + 1) / 2);

    // sz = 00;
}

void solve(){
    prepare();

    // cout << sz << ' ' << cnt;

    cin >> q;

    for(int i = 1 ; i <= q ; i++){
        int k;
        cin >> k;
        matrix tmp(1 , n + 1);

        int ans = -1;

        for(int j = 1 ; j <= k ; j++){
            int x;
            cin >> x;
            tmp[0][x]++;
            if(tmp[0][x] == k) ans = 0;
        }

        if(ans != -1){
            cout << ans << '\n';
            continue;
        }

        int l = 1 , r = sz;

        for(int mid = l ; mid <= r ; mid++){
            // int mid = (l + r) >> 1;

            if(tmp.ok(pw[mid] , k)){
                ans = mid;
                break;
                // r = mid - 1;
            }
            // else l = mid + 1;
        }

        cout << ans << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
    Times;
}

/*      UwU      */
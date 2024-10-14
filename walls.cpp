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
#define add(x , y) ((x) + (y) >= p ? ((x) + (y) - p) : ((x) + (y)))
#define file "walls"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int MAX = 2e6 + 1;
const int N = 2e6 + 5;
int o , r , comb[5005][10005];
ll gt[N] , p , inv[N];
bool notPrime[MAX];
vector <int> Primes;
ll Pow(ll a , ll b){
    if(b == 0) return 1;
    b--;
    for(ll tmp = a; b > 0; b >>= 1, (tmp *= tmp) %= p){
        if(b & 1) (a *= tmp) %= p;
    }
    return a;
}
void prepare(){
    int l = N;
    if(o == 4) l = N / 2;
    gt[0] = 1;
    for(int i = 1 ; i < l ; i++){
        gt[i] = (gt[i - 1] * i) % p;
        // gt[i] %= p;
        // cout << gt[i] << '\n';
    }
    inv[l - 1] = Pow(gt[l - 1] , p - 2) % p;
    for(int i = l - 1 ; i >= 1 ; i--){
        inv[i - 1] = (1ll * inv[i] * i) % p;
    }
}
void sieve(){
    notPrime[0] = notPrime[1] = 1;
    for(int i = 2 ; 1ll * i * i < MAX ; i++){
        if(!notPrime[i])
        for(int j = i * i ; j < MAX ; j += i){
            // cout << j << '\n';
            notPrime[j] = 1;
        }
    }
    for(int i = 1 ; i < MAX ; i++){
            // cout << i << '\n';
        if(!notPrime[i]){
            Primes.pb(i);
        }
    }
}
int getExp(int n, int p) {
	int res = 0;
    if(p > n) return 0;
	long long pw = p;
	while (pw <= n) {
		res += n / pw;
		pw *= p;
	}
    // cout << res << ' ' << n << ' ' << pw << ' ' << p << '\n';
    return res;
}

void inp()  
{
    cin >> o >> r >> p;
    if(o <= 2){
        for(int i = 1 ; i <= 5000 * 2 ; i++){
            comb[0][i] = 1;
        }
        comb[0][0] = 1;
        for(int i = 1 ; i <= 5000 ; i++){
            for(int j = 1 ; j <= 5000 * 2 ; j++){
                if(i > j) comb[i][j] = 0;
                if(i == j) comb[i][j] = 1;
                if(i < j){
                    comb[i][j] = comb[i][j - 1] + comb[i - 1][j - 1];
                    if(comb[i][j] >= p) comb[i][j] -= p;
                }
            }
        }
        for(int i = 1 ; i <= r ; i++){
            int n , c;
            cin >> n >> c;
            cout << (comb[c][n + c] - 1 + p) % p << ' ';
            // cout << comb[1][2] << '\n';
        }
    }
    else if(o == 5){
        sieve();
        for(int i = 1 ; i <= r ; i++){
            int n , c;
            cin >> n >> c;
            ll ans = 1;
            for(auto j : Primes){
                int exp = getExp(n + c , j) - getExp(n , j) - getExp(c , j);
                // cout << j << exp << '\n';
                ans *= Pow(j , exp);
                ans %= p;
            }
            cout << (ans - 1 + p) % p << ' ';
        }
    }
    else{
        prepare();
        // cout << gt[N - 1] << '\n';
        if(o == 3){
            for(int i = 1 ; i <= r ; i++){  
                ll n , c;
                cin >> n >> c;
                cout << (((1ll * gt[n + c] * Pow((gt[c] * gt[n]) % p , p - 2)) % p) - 1ll + p) % p << ' ';
                // cout << comb[1][2] << '\n';
            }
        }
        else 
        if(o == 4){
            for(int i = 1 ; i <= r ; i++){  
                ll n , c;
                cin >> n >> c;
                ll num = inv[c];
                int tmp = (n + 1) % p;
                for(ll k = n + 1 ; k <= n + c ; k++, tmp = add(tmp, 1)){
                    (num *= tmp) %= p;
                }
                // cout << (((num * Pow(gt[c] % p , p - 2)) % p) - 1ll + p) % p << '/';
                cout << (num - 1ll + p) % p << ' ';
            }
        }
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
main()
{
    cin.tie(0)->ios_base::sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}
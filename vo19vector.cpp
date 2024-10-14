#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int N1 = 1e7 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n;
int cnt[2][N1];
bool not_prime[N1];
vector <int> prime;
vector <pii> res;

void sieve(){
    not_prime[0] = not_prime[1] = 1;
    for(int i = 2 ; i <= sqrt(1e7) ; i++){
        if(not_prime[i]) continue;
        for(int j = i * i ; j <= 1e7 ; j += i){
            not_prime[j] = 1;
        }
    }

    for(int i = 2 ; i <= 1e7 ; i++){
        if(!not_prime[i]) prime.pb(i);
    }
}

void calc(int k , int type){
    for(auto j : prime){
        if(!not_prime[k]){
            cnt[type][k]++;
            break;
        }
        if(k == 1) break;

        while(k % j == 0){
            // cout << k << '\n';
            k /= j;
            cnt[type][j]++;
        }
    }
}

void inp(){
    cin >> n;
    sieve();
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        calc(x , 0);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        calc(x , 1);
    }
}

void solve(){
    int ans = 0;

    for(int i = 2 ; i <= 1e7 ; i++){
        if(not_prime[i] || (!cnt[1][i] && !cnt[0][i])) continue;
        // cout << cnt[0][i] << ' ' << cnt[1][i] << '\n';

        if(cnt[1][i] & 1){
            res.pb({0 , i});
            cnt[1][i]++;
        }

        if((cnt[0][i] - (cnt[1][i] / 2)) & 1){
            cnt[1][i] += 2;
            res.pb({0 , i});
            res.pb({0 , i});
        }

        for(int j = 2 ; j <= cnt[1][i] ; j += 2){
            res.pb({1 , i});
            cnt[0][i]++;
        }
        
        for(int j = 2 ; j <= cnt[0][i] ; j += 2){
            res.pb({-1 , i});
        }
    }

    cout << res.size() << '\n';

    for(auto j : res){
        cout << j.se << ' ';
        if(j.fi == -1) cout << "L\n";
        if(j.fi == 1) cout << "W\n";
        if(j.fi == 0) cout << "D\n";
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
}

/*      UwU      */
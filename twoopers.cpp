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
#define add(x , y) ((x) = (x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        //freopen(file".inp", "r" , stdin);
        //freopen(file".out", "w" , stdout);
    }
}

string s , t;
int n;
int hashS[N] , hashT[N] , pw[N];

void prepare(){
    pw[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        pw[i] = 1ll * pw[i - 1] * base % mod;
    }

    for(int i = 1 ; i <= n ; i++){
        hashS[i] = ((1ll * hashS[i - 1] * base % mod) + (s[i] - 'A' + 1)) % mod;
        hashT[i] = ((1ll * hashT[i - 1] * base % mod) + (t[i] - 'A' + 1)) % mod;
    }
}

int get_hashT(int l , int r){
    if(l > r) return 0;
    return (hashT[r] - (1ll * pw[r - l + 1] * hashT[l - 1] % mod) + mod) % mod;
}

int get_hashS(int l , int r){
    if(l > r) return 0;
    return (hashS[r] - (1ll * pw[r - l + 1] * hashS[l - 1] % mod) + mod) % mod;
}

void inp(){
    cin >> s >> t;
    n = s.size();
    s = " " + s;
    t = " " + t;

    swap(s , t);
}

void solve(){
    prepare();
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        // cout << ( * get_hashT(i , n) * pw[i - 1]) % mod + get_hashT(1 , i - 1) << ' ' << get_hashS(1 , n) << '\n';
        if((1ll * get_hashT(i , n) * pw[i - 1] % mod + get_hashT(1 , i - 1)) % mod == get_hashS(1 , n)) ans += n;
        else
        if(s[1] != t[i]){
            if(get_hashS(2 , n) == (1ll * get_hashT(i + 1 , n) * pw[i - 1] % mod + get_hashT(1 , i - 1)) % mod){
                // cout << "pp\n";
                // cout << get_hashS(2 , n) << ' ' << (get_hashT(i + 1 , n) * pw[i - 1] % mod + get_hashT(1 , i - 1)) % mod << '\n';
                // cout << i + 1 << ' ' << n << '\n';
                ans++;
            }
        }
        else{
            int l = 1 , r = n;
            int length = 1;

            while(l <= r){
                int mid = (l + r) >> 1;
                int hash1 =(1ll * get_hashT(i , min(i + mid - 1 , n)) * pw[max(0 , mid - (n - i + 1))] % mod + get_hashT(1 , max(mid - (n - i + 1) , 0))) % mod;
                if(hash1 == hashS[mid]){
                    l = mid + 1;
                    length = mid;
                }
                else r = mid - 1;
            }

            // cout << i << ' ' << length << "ff" << '\n';
            // cout << (i + length) % n + 1 << ' ' << i - 1 << '\n';
            // cout << length + 2 << ' ' << n << '\n';
            // for(int j = (i + length) % n + 1 ; j <= i - 1 ; j++) cout << t[j];
            // nl;
            // for(int j = length + 1 ; j <= n ; j++) cout << s[j];
            // nl;
            // cout << get_hashT((i + length) % n + 1 , i - 1) << ' ' << get_hashS(length + 2 , n) << '\n';

            if(i + length >= n){
                if(get_hashT((i + length) % n + 1 , i - 1) == get_hashS(length + 2 , n)){
                    // cout << i << "gg" << '\n';
                    ans++;
                }
            }
            else{
                if((1ll * get_hashT(i + length + 1 , n) * pw[i - 1] % mod + get_hashT(1 , i - 1)) % mod == get_hashS(length + 2 , n)){
                    // cout << i << "gg" << '\n';
                    ans++;
                }
            }
        }
    }

    cout << ans;
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
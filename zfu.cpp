#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7;
const int N = 2e6 + 5;

string s;
int n , q;
ll hashS[N] , base[N] , val[N];

ll get_hash(int l , int r){
    return (hashS[r] - (hashS[l - 1] * base[r - l + 1] % mod) + mod * mod) % mod;
}

void prepare(){
    base[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        base[i] = (base[i - 1] * 31) % mod;
        hashS[i] = (hashS[i - 1] * 31 % mod + s[i] - 'a') % mod;
        // cout << hashS[i] << '\n';
    }
}

void inp(){
    cin >> s;
    n = s.size();
    s = " " + s;
}

void solve(){
    prepare();
    for(int i = 1 ; i <= n ; i++){
        int l = 1 , r = n - i + 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            ll hash_tmp1 = get_hash(i , i + mid - 1);
            ll hash_tmp2 = get_hash(1 , mid);

            if(hash_tmp1 == hash_tmp2){
                l = mid + 1;
                val[i] = mid;
            }
            else r = mid - 1;
        }
    }

    for(int i = n ; i >= 1 ; i--){
        val[i] = max(val[i] , val[i + 1]);
    }

    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int pos;
        cin >> pos;
        cout << val[pos] << '\n';
    }
}

void run_with_file(){
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UMU      */
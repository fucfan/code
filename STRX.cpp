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
const int N = 2e5 + 5;

string s , t;
ll hashT[N] , base[N];
map <ll , int> mp;
int n;

ll get_hash(int l , int r){
    if(r < l) return 0;
    return (hashT[r] - (hashT[l - 1] * base[r - l + 1] % mod) + mod * mod) % mod;
}

void prepare(){
    base[0] = 1;
    
    for(int i = 1 ; i <= n ; i++) base[i] = (base[i - 1] * 2) % mod;

    for(int i = 1 ; i <= n ; i++){
        hashT[i] = ((hashT[i - 1] * 2) % mod + t[i] - '0') % mod;
    }

    mp[hashT[n]] = 0;

    for(int i = n ; i >= 2 ; i--){
        ll preffix = get_hash(i , n);
        ll suffix = get_hash(1 , i - 1);

        mp[((preffix * base[i - 1]) % mod + suffix % mod) % mod] = i - 1;
    }
}

void inp(){
    cin >> t >> s;
    n = s.size();
    t = " " + t;
    s = " " + s;
}

void solve(){
    prepare();

    // cout << n << ' ' << s << ' ' << t << '\n';

    for(int i = 1 ; i <= n ; i++){
        // cout << i << '\n';
        string tmp = " ";
        for(int j = i ; j <= n ; j++) tmp += s[j];
        for(int j = 1 ; j <= i - 1 ; j++) tmp += s[j];
        // cout << tmp << ' ';

        for(int j = 1 ; j <= n ; j++){
            tmp[j] = char('0' + ((tmp[j] - '0') | (s[j] - '0')));
        }

        // cout << tmp << '\n';

        ll hash_tmp = 0;

        for(int j = 1 ; j <= n ; j++){
            hash_tmp = ((hash_tmp * 2) % mod + tmp[j] - '0') % mod;
        }

        if(mp[hash_tmp]){
            // cout << mp[hash_tmp] << '\n';
            int ans1 = (-mp[hash_tmp] + n) % n;
            int ans2 = (i - 1 - mp[hash_tmp] + n) % n;
            cout << min(ans1 , ans2) << ' ' << max(ans1 , ans2);
            exit(0);
        }
    }

    cout << -1;
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
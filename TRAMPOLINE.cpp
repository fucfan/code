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
#define file "trampoline"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , a[N];

struct fenwick_tree{
    int node[4 * N];

    void reset(int n){
        for(int i = 1 ; i <= n ; i++) node[i] = 0;
    }
    
    void update(int pos , int val){
        for(; pos <= n ; pos += (pos & (-pos))){
            node[pos] += val;
        }
    }

    int get(int pos){
        int res = 0;

        for(; pos >= 1 ; pos -= (pos & (-pos))){
            res += node[pos];
        }

        return res;
    }
} BIT;

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
}   

void solve(){
    ll ans = 0;
    
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 1 && !BIT.get(i)) continue;

        BIT.update(i + 2 , 1);
        BIT.update(min(n + 1 , i + a[i] + 1) , -1);
        
        ll val = BIT.get(i);

        if(a[i] <= val){
           BIT.update(i + 1 , val - (a[i] - 1));
           BIT.update(min(n + 1 , i + 2) , -(val - (a[i] - 1)));
        }

        a[i] -= BIT.get(i);

        ans += max(0 , a[i] - 1);
    }

    BIT.reset(n);

    cout << ans << '\n';
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
    int test_case = 1;
    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */ 
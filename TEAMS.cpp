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
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        //freopen(file".inp", "r" , stdin);
        //freopen(file".out", "w" , stdout);
    }
}

int n , en[N];
pii a[N];  

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
}

void solve(){
    int ans = 0;

    sort(a + 1 , a + 1 + n , greater<>());

    for(int i = 1 ; i <= n ; i += a[i].fi){
        ans++;
    }

    cout << ans << '\n';

    for(int i = 1 ; i <= n ; i += a[i].fi){
        cout << a[i].fi << ' ';
        for(int j = i ; j <= i + a[i].fi - 1 ; j++){
            cout << a[j].se << ' ';
        }
        nl;
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
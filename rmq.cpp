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
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "rmq"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 6e5 + 5;
int n , q , a[N] , rmq[N][22] , lg2[N];
void prepare(){
    for(int i = 1 ; i <= n ; i++) rmq[i][0] = a[i];
    for(int k = 1 ; k <= 20 ; k++){
        for(int i = 1 ; i <= n ; i++){
            rmq[i][k] = min(rmq[i][k - 1] , rmq[i + (1 << (k - 1))][k - 1]);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        while(1 << (lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    prepare();
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int l , r;
        cin >> l >> r;
        l++;r++;
        int length = lg2[r - l + 1];
        cout << min(rmq[l][length] , rmq[r - (1 << (length)) + 1][length]) << '\n';
    }
    // cout << 1;
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
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UwU      */
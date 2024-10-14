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
#define file "sprime"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e6 + 5;
int t , l , r;
bool pr[N];
vector <int> ans;
int bs(int l , int r , int x , int type){
    int mid = (l + r) / 2;
    if(r - l <= 1){
        if(type == 1){
            if(ans[l] >= x) return l;
            return r;
        }
        if(type == 2){
            if(ans[r] <= x) return r;
            return l;
        }
    }
    if(ans[mid] == x) return mid;
    if(ans[mid] < x) return bs(mid , r , x , type);
    if(ans[mid] > x) return bs(l , mid , x , type);
}
bool check(int k){
    int s = 0;
    while(k > 0){
        s += k % 10;
        k = k / 10;
    }
    if(s % 5 == 0) return true;
    return false;
}
void sieve(){
    for(ll i = 2 ; i < N ; i++){
        if(!pr[i]){
            if(check(i)){
                ans.pb(i);
            }
            for(ll j = i * i ; j < N ; j += i){
                if(j < N)pr[j] = true;
            }
        }
    }
}
void inp()
{
    cin >> t;
    sieve();
    for(int i = 1 ; i <= t ; i++){
        cin >> l >> r;
        int a = bs(0 , ans.size() - 1 , l , 1);
        int b = bs(0 , ans.size() - 1 , r , 2);
        if(a == b && (ans[a] < l || ans[b] > r)) cout << 0;
        else cout << (b - a) + 1 << '\n';
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
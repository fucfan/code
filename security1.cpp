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
#define file "SECURITY"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , m , x , y , low[N] , num[N] , d , cnt , cnt1[N] , cnt0[N];
ll a[N] , sum[N] , l , sum0 , k , MAX;
stack <ll> res;
priority_queue <ll , vector <ll> , greater <ll>> q[N];
bool check[N];
vector <ll> w[N] , ans;
void vst(int i){
    res.push(i);
    low[i] = cnt;
    num[i] = cnt;
    cnt++;
    for(auto j : w[i]){
        if(!check[j]){
            if(num[j] == 0){
                vst(j);
                low[i] = min(low[i] , low[j]);
            }
            else{
                low[i] = min(low[i] , low[j]);
            }
        }
    }
    if(low[i] == num[i]){
        d++;
        while(!res.empty()){
            q[d].push(a[res.top()]);
            if(a[res.top()] == 0) cnt0[d]++;
            check[res.top()] = true;
            if(res.top() == i){
                res.pop();
                break;
            }
            res.pop();
        }
        // nl;
    }
}
void inp()
{
    cin >> n;
    for(int i = 1 ;  i <= n ; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1 ; i <= m ; i++){
        cin >> x >> y;
        w[x].pb(y);
    }
}

void solve()
{
    d = 0;
    cnt = 1;
    for(int i = 1 ; i <= n ; i++){
        if(num[i] == 0){
            vst(i);
        }
    }
    // for(int i = 1 ; i <= d ; i++){
    //     while(!q[i].empty()){
    //         cout << q[i].top() << ' ';
    //         q[i].pop();
    //     }
    //     nl;
    // }
    for(int i = 1 ; i <= d ; i++){
        // cout << q[i].top() << "a \n";
        if(q[i].top() > 0){
            // cout << q[i].top();
            MAX = (((MAX % mod)) + (q[i].top() % mod)) % mod;
            sum[i] = q[i].top();
            while(q[i].top() == sum[i] && !q[i].empty()){
                cnt1[i]++;
                q[i].pop();
            }
        }
        else if(q[i].top() < 0){
                while(q[i].top() < 0 && !q[i].empty()){
                    MAX = ((MAX % mod) + (q[i].top() % mod)) % mod;
                    sum[i] = ((sum[i] % mod) + (q[i].top() % mod)) % mod;
                    q[i].pop();
                }
            }
            else if(q[i].top() == 0){
                // cout << i << '\n';
                cnt0[i]--;
                sum[i] = 0;
            }
        sum0 = sum0 + cnt0[i];
    }
    l = 1;
    cout << MAX << ' ';
    for(int i = 1 ; i <= d ; i++){
        if(cnt1[i] != 0){
            l = ((l % mod) * (cnt1[i] % mod)) % mod;
        }
    }
    for(int i = 1 ; i <= sum0 ; i++){
        l = ((l % mod) * 2) % mod;
    }
    cout << l;
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
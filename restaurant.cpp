#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "restaurant"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

int n , m;
ll ans , dp[205][605][605];
vector <int> adj[N];

struct dishes{
    int deli , full , cost;
} dish[N];

void sub1(){
    for(int mask = 0 ; mask < (1 << n) ; mask++){
        bool check = 1;
        ll sum1 , sum2 , sum3;
        sum1 = sum2 = sum3 = 0;

        for(int i = 1 ; i <= n ; i++){
            if(BIT(mask , i - 1)){
                sum1 += dish[i].deli;
                sum2 += dish[i].full;
                sum3 += dish[i].cost;

                if(adj[i].size()){
                    for(auto j : adj[i]){
                        if(!BIT(mask , j - 1)) check = 0;
                    }
                }
                if(!check) break;
            }
            
            if(!check) break;
        }

        if(check) ans = max(ans , sum1 * sum2 - sum3);
    }

    cout << ans;
}

void sub2(){
    mem(dp , -0x3f);
    dp[0][0][0] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int sum1 = 1 ; sum1 <= 601 ; sum1++){
            for(int sum2 = 1 ; sum2 <= 601 ; sum2++){
                if(sum1 >= dish[i].deli && sum2 >= dish[i].full)
                    dp[i][sum1][sum2] = max(dp[i - 1][sum1][sum2] ,
                                            dp[i - 1][sum1 - dish[i].deli][sum2 - dish[i].full] 
                    - dish[i].cost + (sum1 - dish[i].deli) * dish[i].full + (sum2 - dish[i].full) * dish[i].deli + dish[i].deli * dish[i].full);
                else dp[i][sum1][sum2] = dp[i - 1][sum1][sum2];
                ans = max(ans , dp[i][sum1][sum2]);
                // cout << i << ' ' << sum1 << ' ' << sum2 << ' ' << dp[i][sum1][sum2] << '\n';
                // cout << - dish[i].cost + sum1 * dish[i].full + sum2 * dish[i].deli + dish[i].deli * dish[i].full << '\n';
            }
        }
    }

    cout << ans;
}

void inp(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> dish[i].full >> dish[i].deli >> dish[i].cost;
    }
    for(int i = 1 ; i <= m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
    }
}

void solve(){
    if(!m) sub2();
    else sub1();
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
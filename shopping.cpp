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
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "shopping"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 300 + 5;
const int LOG = 20;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct Items{
    int weight , cost , cost_voucher;

    bool operator<(Items b){
        return cost_voucher < b.cost_voucher;
    }
} item[N];

int n , money , voucher;
int dp[N][N][N] , dp_sub1[3001][3001];

int sol(int i , int remain , int remain_voucher){
    if(remain < 0) return -oo;
    
    if(i > n) return 0;

    if(dp[i][remain][remain_voucher] != -1) return dp[i][remain][remain_voucher];

    int res = 0;

    int val = min(item[i].cost , remain_voucher / item[i].cost_voucher);

    res = max(res , sol(i + 1 , remain , remain_voucher));
    res = max(res , sol(i + 1 , remain - item[i].cost + val , remain_voucher - item[i].cost_voucher * val) + item[i].weight);
    
    return dp[i][remain][remain_voucher] = res;
}

void sub1(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= money ; j++){
            dp_sub1[i][j] = dp_sub1[i - 1][j];
            if(j >= item[i].cost) dp_sub1[i][j] = max(dp_sub1[i][j] , dp_sub1[i - 1][j - item[i].cost] + item[i].weight);
        }
    }

    cout << dp_sub1[n][money];
}

void sub234(){
    sort(item + 1 , item + 1 + n);
    mem(dp , -1);
    cout << sol(1 , money , voucher);
}

void inp(){
    cin >> n >> money >> voucher;
    for(int i = 1 ; i <= n ; i++){
        cin >> item[i].weight >> item[i].cost >> item[i].cost_voucher;
    }
}

void solve(){
    if(n > 200) sub1();
    else sub234();
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
    Times;
}

/*      UwU      */

// #include<bits/stdc++.h>
// #define fi first
// #define se second
// #define ull unsigned long long
// #define ll long long
// #define BIT(a , b) ((a >> b) & 1)
// #define turnOn(a , b) ((a) | (1 << (b)))
// #define turnOff(a , b) ((a) ^ (1 << (b)))
// #define pii pair<int, int>
// #define pb push_back
// #define nl cout << "\n";
// #define __ <<" "<<
// #define mem(a, b) memset((a), (b), sizeof((a)))
// #define all(c) (c).begin(), (c).end()
// #define add(x , y) ((x) = (x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
// #define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
// #define file "test"
// using namespace std;

// const int oo = 1e9 + 7;
// const int mod = 1e9 + 7;
// const int N = 200 + 5;
// const int LOG = 20;

// void run_with_file(){
//     if(fopen(file".inp" , "r")){
//         // freopen(file".inp", "r" , stdin);
//         // freopen(file".ans", "w" , stdout);
//     }
// }

// int n , money , voucher;
// int weight[N] , cost[N] , cost_voucher[N];
// int dp[N][N][N] , dp_sub1[2001][2001];

// void sub1(){
//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 0 ; j <= money ; j++){
//             dp_sub1[i][j] = dp_sub1[i - 1][j];
//             if(j >= cost[i]) dp_sub1[i][j] = max(dp_sub1[i][j] , dp_sub1[i - 1][j - cost[i]] + weight[i]);
//         }
//     }

//     cout << dp_sub1[n][money];
// }

// void sub234(){
//     for(int i = 1 ; i <= n ; i++){
//         for(int remain = 0 ; remain <= money ; remain++){
//             for(int remain_voucher = 0 ; remain_voucher <= voucher ; remain_voucher++){
//                 dp[i][remain][remain_voucher] = dp[i - 1][remain][remain_voucher];

//                 if(remain >= cost[i])
//                 dp[i][remain][remain_voucher] = max(dp[i][remain][remain_voucher] , dp[i - 1][remain - cost[i]][remain_voucher] + weight[i]);

//                 for(int j = 1 ; j <= remain_voucher / cost_voucher[i] ; j++){
//                     // cout << "gg\n";
//                     if(remain >= cost[i] - j && cost[i] >= j)
//                     dp[i][remain][remain_voucher] = max(dp[i][remain][remain_voucher] , dp[i - 1][remain - cost[i] + j][remain_voucher - (cost_voucher[i] * j)] + weight[i]);
//                 }

//                 // cout << i << ' ' << remain << ' ' << remain_voucher << ' ' << dp[i][remain][remain_voucher] << '\n';
//             }
//         }
//     }

//     cout << dp[n][money][voucher];
// }

// void inp(){
//     cin >> n >> money >> voucher;
//     for(int i = 1 ; i <= n ; i++){
//         cin >> weight[i] >> cost[i] >> cost_voucher[i];
//     }
// }

// void solve(){
//     if(n > 200) sub1();
//     else sub234();
// }

// int main(){
//     cin.tie(0)->sync_with_stdio(false);
//     run_with_file();
//     int test_case = 1;
//     //cin >> test_case;
//     while(test_case--){
//         inp();
//         solve();
//     }
//     Times;
// }

// /*      UwU      */
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "xephinh"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

vector <int> board(9 , 0);
map <string , int> d;
bool used[N];
string s;
// int a[N];
// vector <pair <int , vector<int>>> st;

// void out(){
//     int hash_num = 0;
//     for(int i = 0 ; i <= 8 ; i++){
//         // cout << a[i] << ' ';
//         hash_num = (1ll * hash_num * base + a[i]) % mod;
//     }
//     // nl;
//     st.push_back({hash_num , {a[0] , a[1] , a[2] , a[3] , a[4] , a[5] , a[6] , a[7] , a[8]}});
// }

// void btr(int i){
//     for(int j = 0 ; j <= 8 ; j++){
//         if(used[j]) continue;
//         used[j] = 1;
//         a[i] = j;
//         if(i < 8) btr(i + 1);
//         else out();
//         used[j] = 0;
//     }
// }

void bfs(){
    queue <pair <string , int>> q;
    q.push({"012345678" , 0});
    d["012345678"] = 1;

    while(q.size()){
        string u = q.front().fi;
        int pos_0 = q.front().se;
        int dis = d[u];
        q.pop();

        if(pos_0 / 3 > 0){
            swap(u[pos_0 - 3] , u[pos_0]);
            if(!d[u]){
                d[u] = dis + 1;
                q.push({u , pos_0 - 3});
            }
            swap(u[pos_0 - 3] , u[pos_0]);
        }
        if(pos_0 / 3 < 2){
            swap(u[pos_0 + 3] , u[pos_0]);
            if(!d[u]){
                d[u] = dis + 1;
                q.push({u , pos_0 + 3});
            }
            swap(u[pos_0 + 3] , u[pos_0]);
        }
        if(pos_0 % 3 != 0){
            swap(u[pos_0 - 1] , u[pos_0]);
            if(!d[u]){
                d[u] = dis + 1;
                q.push({u , pos_0 - 1});
            }
            swap(u[pos_0 - 1] , u[pos_0]);
        }
        if(pos_0 % 3 != 2){
            swap(u[pos_0 + 1] , u[pos_0]);
            if(!d[u]){
                d[u] = dis + 1;
                q.push({u , pos_0 + 1});
            }
            swap(u[pos_0 + 1] , u[pos_0]);
        }
    }

}

void inp(){
    for(int i = 0 ; i <= 8 ; i++){
        char x;
        cin >> x;
        s = s + x;
    }
}

void solve(){
    cout << d[s] - 1 << '\n';
    s.clear();
    // cout << d.size() << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    cin >> test_case;
    bfs();
    // btr(0);
    // sort(all(st));
    // cout << st.size() << '\n';
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
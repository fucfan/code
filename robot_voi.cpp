#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int , int>
#define pb push_back
#define BIT(x , i) (((x) >> (i)) & 1)
#define flip(x , i) ((x) ^ (1 << (i)))
#define add(x , y) ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
#define all(c) (c).begin() , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(a))
#define nl cout << '\n'
#define file "test"

using namespace std;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const int LOG = 20;
const int base = 31;
const pii MOVE[] = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};

int n;
char a[4][N];
bool vst[4][N];

void inp()
{
    cin >> n;
    for(int j = 1 ; j <= 3 ; j++){
        for(int i = 1 ; i <= n ; i++){
            cin >> a[j][i];
        }
    }
}

void solve()
{
    int ans = 0;
    int cur = -1;
    for(int i = 1 ; i <= n ; i++){
        if(cur == -1){
            if(a[1][i] == 'S') cur = 0;
            if(a[1][i] == 'T') cur = 1;
        }

        if(a[1][i] == 'S' && cur){
            cur = -1;
            ans++;
        }
        if(a[1][i] == 'T' && !cur){
            cur = -1;
            ans++;
        }
        if(a[1][i] == '#') cur = -1;
    }

    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
//    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

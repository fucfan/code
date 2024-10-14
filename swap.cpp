#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define flip(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "swap"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e2 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

int n , a[N] , pos[N] , val[N] , new_per[N] , b[N]; 

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        int cnt = 0;
        
        for(int j = 1 ; j <= n ; j++){
            b[j] = a[j];
            pos[b[j]] = j;
        }

        // cout << pos[n] << ' ' << i << '\n';

        // for(int k = 1 ; k <= n ; k++){
        //     cout << b[k] << ' ';
        // }
        // nl;

        while(pos[n] > i){
            // cout << pos[n] << ' ' << i << '\n';
            int tmp = b[pos[n] - 1];
            swap(b[pos[n]] , b[pos[n] - 1]);
            swap(pos[n] , pos[tmp]);
            cnt++;
        }

        while(pos[n] < i){
            int tmp = b[pos[n] + 1];
            swap(b[pos[n]] , b[pos[n] + 1]);
            swap(pos[n] , pos[tmp]);
            cnt++;
        }

        for(int j = n - 1 ; j >= 1 ; j--){
            while(pos[j] < i){
                if(j < b[pos[j] + 1]) break;
                int tmp = b[pos[j] + 1];
                swap(b[pos[j]] , b[pos[j] + 1]);
                swap(pos[j] , pos[tmp]);
                cnt++;
            }

            while(pos[j] > i){
                if(j < b[pos[j] - 1]) break;
                int tmp = b[pos[j] - 1];
                swap(b[pos[j]] , b[pos[j] - 1]);
                swap(pos[j] , pos[tmp]);
                cnt++;
            }
        }

        // for(int k = 1 ; k <= n ; k++){
        //     cout << b[k] << ' ';
        // }
        // nl;

        cout << cnt << ' ';
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
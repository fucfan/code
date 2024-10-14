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
#define file "simulation"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct Vector{
    int x , y;

    Vector operator+(Vector b){
        Vector a = *this;
        a.x += b.x;
        a.y += b.y;
        return a;
    }

    void operator+=(Vector b){
        Vector &a = *this;
        a = a + b;
    }
} v[N] , pos;

int cal(Vector a , Vector b){
    int cnt = 0;

    if(a.x > 0){
        if(a.x + b.x <= 0) cnt++;
    }
    if(a.x < 0){
        if(a.x + b.x >= 0) cnt++;
    }
    if(a.y > 0){
        if(a.y + b.y <= 0) cnt++;
    }
    if(a.y < 0){
        if(a.y + b.y >= 0) cnt++;
    }

    return cnt;
}

int n , m , res;

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> v[i].x >> v[i].y;
    }
}

void solve(){
    cin >> m;
    int it = 1;
    for(int i = 1 ; i <= m ; i++){
        char type;
        cin >> type;
        if(type == 'B'){
            it = max(it - 1 , 1);
        }
        if(type == 'F'){
            it = min(it + 1 , n);
        }
        if(type == 'C'){
            int nx , ny;
            cin >> nx >> ny;
            v[it] = {nx , ny};
        }
        if(type == 'Q'){
            pos = {1 , 1};
            res = 0;

            for(int j = 1 ; j <= n ; j++){
                res += cal(pos , v[j]);
                pos += v[j];
            }

            cout << res << '\n';
        }
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
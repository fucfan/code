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
#define file "triple"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
         freopen(file".inp", "r" , stdin);
         freopen(file".out", "w" , stdout);
    }
}

struct Point{
    ll x , y;

    ll dist(Point b){
        return abs(b.x - x) + abs(b.y - y);
    }
} p[N];

int n;
ll d[N];

namespace sub1{
    bool check(){
        return (n <= 300);
    }

    void prepare(){
        mem(d , 0x3f);

        for(int i = 1 ; i <= n ; i++){
            for(int j = i + 1 ; j <= n ; j++){
                d[i] = min(p[i].dist(p[j]) , d[i]);
                d[j] = min(p[i].dist(p[j]) , d[j]);
            }
        }
    }

    void solve(){
        ll ans = 0;

        prepare();

        for(int i = 1 ; i <= n - 2 ; i++){
            for(int j = i + 1 ; j <= n - 1 ; j++){
                for(int k = j + 1 ; k <= n ; k++){
                    if(d[i] == d[j] && d[j] == d[k]){
                        if(p[i].dist(p[j]) == p[j].dist(p[k]) &&
                           p[j].dist(p[k]) == p[k].dist(p[i])){
                            if(p[i].dist(p[j]) == d[i]){
                                ans++;
                            }
                        }
                    }
                }
            }
        }

        cout << ans;
    }
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i].x >> p[i].y;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    if(sub1::check()) return sub1::solve() , 0;
}

/*      UwU      */

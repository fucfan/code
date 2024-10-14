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
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        //freopen(file".inp", "r" , stdin);
        //freopen(file".out", "w" , stdout);
    }
}

int n;
ll cost[N] , suf[N] , x[N];

struct tree{
    int w , d;
} t[N];

struct Line{
    ll a , b;

    bool operator<(Line y){
        return (a < y.a || (a == y.a && a < y.b));
    }

    double intersect(Line y){
        return ((double)(y.b - b) / (a - y.a));
    }

    bool bad(Line l2 , Line l3){
        return intersect(l3) < intersect(l2);
    }

    ll cal(int x){
        return a * x + b;
    }
};

struct CHT{
    vector <Line> line;

    void add_line(Line l3){
        if(line.size() < 2) line.pb(l3);
        else{
            Line l2 = line.back();
            line.pop_back();
            Line l1 = line.back();

            while(l1.bad(l2 , l3) && line.size() >= 2){
                l2 = line.back();
                line.pop_back();
                l1 = line.back();
            }

            if(l1.bad(l2 , l3)){
                line.pb(l3);
            }
            else{
                line.pb(l2);
                line.pb(l3);
            }
        }
    }

    ll search(int x){
        int l = 0;
        int r = line.size() - 1;

        while(l <= r){
            int mid = (l + r) >> 1;

            double pos1 , pos2;

            if(!mid) pos1 = -oo;
            else pos1 = line[mid].intersect(line[mid - 1]);

            if(mid == line.size() - 1 ) pos2 = oo;
            else pos2 = line[mid].intersect(line[mid + 1]);

            if(x > pos2) l = mid + 1;
            if(x < pos1) r = mid - 1;

            if(pos1 <= x && x <= pos2) return line[mid].cal(x);
        }

        return 0;
    }
} line_container;

void prepare(){
    for(int i = n ; i >= 1 ; i--){
        suf[i] = suf[i + 1] + t[i].w;
        x[i] = x[i - 1] + t[i].d;
        cost[i] = cost[i + 1] + t[i].w * x[i];
    }
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> t[i].w >> t[i].d;
    }
}

void solve(){
    prepare();
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
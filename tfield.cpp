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
#define file "test"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N =  1e3 + 5;
const int LOG = 20;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        //freopen(file".inp", "r" , stdin);
        //freopen(file".out", "w" , stdout);
    }
}

int n , k , cnt[N];
vector <pair <double , int>> area;
double pref[N];

struct Polygon{
    int cor;

    struct Point{
        double x , y;

        bool operator<(Point b){
            return x < b.x;
        }

        void print(){
            cout << x << ' ' << y << ' ';
        }
    };

    vector <Point> p;

    double S(Point p1 , Point p2 , Point p3){
        return ((p1.y + p2.y) * (p2.x - p1.x) + (p2.y + p3.y) * (p3.x - p2.x) - (p1.y + p3.y) * (p3.x - p1.x)) / 2;
    }

    double S_convexhull(){
        vector <Point> tmp = p;

        stack <Point> up , down;

        sort(all(tmp));

        for(auto j : tmp){
            if(up.size() < 2) up.push(j);
            else{
                Point p2 = up.top();
                up.pop();
                Point p1 = up.top();
                Point p3 = j;
                while(S(p1 , p2 , p3) < 0 && up.size() >= 2){
                    up.pop();
                    p2 = p1;
                    p1 = up.top();
                }
                if(S(p1 , p2 , p3) < 0) up.push(p3);
                else{
                    up.push(p2);
                    up.push(p3);
                }
            }
        }

        for(auto j : tmp){
            if(down.size() < 2) down.push(j);
            else{
                Point p2 = down.top();
                down.pop();
                Point p1 = down.top();
                Point p3 = j;
                while(S(p1 , p2 , p3) > 0 && down.size() >= 2){
                    down.pop();
                    p2 = p1;
                    p1 = down.top();
                }
                if(S(p1 , p2 , p3) > 0) down.push(p3);
                else{
                    down.push(p2);
                    down.push(p3);
                }
            }
        }

        // cout << up.size() << '\n';
        
        tmp.clear();

        while(up.size()){
            tmp.pb(up.top());
            up.pop();
        }

        reverse(all(tmp));

        double ans = 0;

        for(int i = 0 ; i < tmp.size() - 1 ; i++){
            ans += ((tmp[i + 1].x - tmp[i].x) * (tmp[i].y + tmp[i + 1].y)) / 2;
        }

        // cout << down.size() << '\n';
        
        tmp.clear();

        while(down.size()){
            tmp.pb(down.top());
            down.pop();
        }

        reverse(all(tmp));

        for(int i = 0 ; i < tmp.size() - 1 ; i++){
            ans -= ((tmp[i + 1].x - tmp[i].x) * (tmp[i].y + tmp[i + 1].y)) / 2;
        }

        return ans;
    }
} polygon[N];

void inp(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        int m;
        cin >> m;
        cin >> polygon[i].cor;
        for(int j = 1 ; j <= m ; j++){
            ll x , y;
            cin >> x >> y;
            double a = x + oo;
            double b = y + oo;
            polygon[i].p.pb({a , b});
        }
    }
}

void solve(){
    for(int i = 1 ; i <= n ; i++){
        area.pb({polygon[i].S_convexhull() , polygon[i].cor});
    }

    sort(all(area));

    pref[0] = area[0].fi;

    for(int i = n - 1 ; i >= 1 ; i--){
        area[i].fi -= area[i - 1].fi;
    }

    for(int i = 1 ; i < n ; i++){
        pref[i] = pref[i - 1] + area[i].fi;
    }

    double ans = 0;

    for(int i = 0 ; i < n ; i++){
        int Max = 0;
        for(int j = i ; j < n ; j++){
            cnt[area[j].se]++;
            Max = max(Max , cnt[area[j].se]);

            if(j - i + 1 - Max <= k){
                // cout << i << ' ' << j << ' ' << ans << '\n';
                if(!i) ans = max(ans , pref[j]);
                else ans = max(ans , pref[j] - pref[i - 1]);
            }
        }
        mem(cnt , 0);
    }

    cout << setprecision(1) << fixed << ans;
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
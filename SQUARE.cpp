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
#define file "test"
using namespace std;

const ll oo = 1e18 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

struct Point{
    ll x , y;

    void print(){
        nl;
        cout << x << ' ' << y << '\n';
    }
} p[N];

bool cmp(Point a , Point b){
    return a.x < b.x;
}

bool cmp1(Point a , Point b){
    return a.y < b.y;
}

int n;
ll Max_l[N] , Min_l[N] , Max_r[N] , Min_r[N];

ll quest1(){
    ll res = oo;
    ll l = 1 , r = oo;
    Point point1 = {oo , oo};
    Point point2 = {-oo , -oo};
    for(int i = 1 ; i <= n ; i++){
        point1.x = min(point1.x , p[i].x);
        point1.y = min(point1.y , p[i].y);
        point2.x = max(point2.x , p[i].x);
        point2.y = max(point2.y , p[i].y);
    }
    // point1.print();
    // point2.print();
    while(l <= r){
        ll mid = (l + r) >> 1;
        bool check = 1;
        for(int i = 1 ; i <= n ; i++){
            if((p[i].x > point1.x + mid || p[i].y > point1.y + mid) && 
               (p[i].x < point2.x - mid || p[i].y < point2.y - mid)) check = 0;
        }

        if(check){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }

    return res;
}

ll quest2(){
    sort(p + 1 , p + 1 + n , cmp);

    ll res = oo;

    mem(Max_l , -0x3f);
    mem(Max_r , -0x3f);
    mem(Min_l , 0x3f);
    mem(Min_r , 0x3f);

    for(int i = n ; i >= 1 ; i--){
        Max_r[i] = max(Max_r[i + 1] , p[i].y);
        Min_r[i] = min(Min_r[i + 1] , p[i].y);
    }

    for(int i = 1 ; i < n ; i++){
        Max_l[i] = max(Max_l[i] , p[i].y);
        Max_l[i + 1] = max(Max_l[i + 1] , Max_l[i]);
        Min_l[i] = min(Min_l[i] , p[i].y);
        Min_l[i + 1] = min(Min_l[i + 1] , Min_l[i]);
        res = min(res , max({p[n].x - p[i + 1].x , p[i].x - p[1].x , 1ll , Max_l[i] - Min_l[i] , Max_r[i + 1] - Min_r[i + 1]}));
    }
    // for(int i = 1 ; i <= n ; i++){
    //     cout << Max_l[i] << ' ' << Min_l[i] << '\n';
    // }

    mem(Max_l , -0x3f);
    mem(Max_r , -0x3f);
    mem(Min_l , 0x3f);
    mem(Min_r , 0x3f);

    sort(p + 1 , p + 1 + n , cmp1);

    for(int i = n ; i >= 1 ; i--){
        Max_r[i] = max(Max_r[i + 1] , p[i].x);
        Min_r[i] = min(Min_r[i + 1] , p[i].x);
    }

    for(int i = 1 ; i < n ; i++){
        Max_l[i] = max(Max_l[i] , p[i].x);
        Max_l[i + 1] = max(Max_l[i + 1] , Max_l[i]);
        Min_l[i] = min(Min_l[i] , p[i].x);
        Min_l[i + 1] = min(Min_l[i + 1] , Min_l[i]);
        res = min(res , max({p[n].y - p[i + 1].y , p[i].y - p[1].y , 1ll , Max_l[i] - Min_l[i] , Max_r[i + 1] - Min_r[i + 1]}));
    }

    // for(int i = 1 ; i <= n ; i++){
    //     cout << Max_l[i] << ' ' << Min_l[i] << '\n';
    // }

    return res;
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i].x >> p[i].y;
    }
}

void solve(){
    cout << quest1() << ' ' << quest2() << '\n';
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
    int test_case = 1;
    cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UMU      */
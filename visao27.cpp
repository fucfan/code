#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
float x , y , z , a , b , c;
void inp()
{
    cin >> x >> y >> z >> a >> b >> c;
    if(x != a && y != b && z != c){
        cout << -1;
        exit(0);
    }
    if((x < 1 && y < 1 && z < 1 && x > 0 && y > 0 && z > 0) || (a < 1 && b < 1 && c < 1 && a > 0 && b > 0 && c > 0)){
        cout << -1;
        exit(0);
    }
    cout << setprecision(1) << fixed;
    if(x == a){
        bool check = (y == b && (y == 1 || y == 0)) || (z == c && (z == 1 || z == 0));
        if(x > 0 && x < 1 && !check){
            cout << -1;
            exit(0);
        }
        float s1 = abs(b - y);
        float s2 = abs(c - z);
        double ans = 10 * sqrt((s1 * s1) + (s2 * s2));
        ans = round(ans);
        cout << ans / 10;
        exit(0);
    }
    if(y == b){
        bool check =  (a == x && (a == 1 || a == 0)) || (z == c && (z == 1 || z == 0));
        if(y > 0 && y < 1 && !check){
            cout << -1;
            exit(0);
        }
        float s1 = abs(a - x);
        float s2 = abs(c - z);
        double ans = 10 * sqrt((s1 * s1) + (s2 * s2));
        ans = round(ans);
        cout << ans / 10;
        exit(0);
    }
    if(z == c){
        bool check = (y == b && (y == 1 || y == 0)) || (a == x && (a == 1 || a == 0));
        if(z > 0 && z < 1 && !check){
            cout << -1;
            exit(0);
        }
        float s1 = abs(b - y);
        float s2 = abs(a - x);
        double ans = 10 * sqrt((s1 * s1) + (s2 * s2));
        ans = round(ans);
        cout << ans / 10;
        exit(0);
    }
}

void solve()
{
    
}

void run_with_file()
{
   if(fopen(file".inp","r")){
    //    freopen(file".inp","r", stdin);
    //    freopen(file".out", "w", stdout);
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
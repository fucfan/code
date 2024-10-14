#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
struct shape{
    int x1 , x2 , y1 , y2;
} a[N];
int n , t , r , ans , check1[N] , check2[N];
void inp()
{
    cin >> r >> t;
    for(int g = 1 ; g <= t ; g++){
        cin >> n;
        res = 0;
        ans = 0;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i].x1 >> a[i].x2 
                >> a[i].y1 >> a[i].y2; 
        }
        for(int i = 1 ; i < n ; i++){
            int res = 1;
            check1[a[i].x1] = 1;
            check1[a[i].x2] = 1;
            check2[a[i].y1] = 1;
            check2[a[i].y2] = 1;
            for(int j = i + 1 ; j <= n ; j++){
                if(!a[j].x1 && !a[j])
            }
        }
    }
}

void solve()
{
    
}

void run_with_file()
{
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // run_with_file();
    inp();
    solve();
}

/*      UwU      */
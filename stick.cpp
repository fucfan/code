#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define nl cout << "\n"
#define ___ << " " <<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
#define file "stick"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , a[N];
ll res;

void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
}

void solve()
{
    sort(a + 1 , a + 1 + n);
    ll cnt = 0;
    ll last = 0;
    for(int i = 1 ; i <= n + 1 ; i++){
        if(a[i] != a[i - 1]){
            int pos = lower_bound(a + 1 , a + 1 + n , a[i - 1] * 2) - a;
            // cout << a[i - 1] * 2 << ' ' << pos << ' ' << cnt << ' ' << last << '\n';
            res += (cnt * (cnt - 1) / 2) * (pos - i);
            res += (cnt * (cnt - 1) / 2) * last;
            res += (cnt * (cnt - 1) * (cnt - 2) / 6);
            cnt = 0;
            last = i - 1;
        }
        cnt++;
    }
    cout << res;
}

void run_with_file()
{
    if (fopen(file".inp", "r"))
    {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}

// #include<bits/stdc++.h>

// #define MASK(i) (1 << (i))
// #define BIT(x, i) (((x) >> (i)) & 1)
// #define fi first
// #define se second
// #define ull unsigned long long
// #define ll long long
// #define pii pair<int, int>
// #define mp make_pair
// #define pb push_back
// #define nl cout << "\n"
// #define ___ << " " <<
// #define mem(a, b) memset((a), (b), sizeof((a)))
// #define all(c) (c).begin(), (c).end()
// #define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n"
// #define file "test"
// using namespace std;

// template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
// template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

// const int oo = 1e9 + 7;
// const int mod = 1e9 + 7;
// const int N = 2e6 + 5;  
// const int LOG = 20;

// int n , a[N] , cnt;

// void inp()
// {
//     cin >> n;
//     for(int i = 1 ; i <= n ; i++) cin >> a[i];
// }

// void solve()
// {
//     for(int i = 1 ; i <= n - 2 ; i++){
//         for(int j = i + 1 ; j <= n - 1 ; j++){
//             for(int k = j + 1 ; k <= n ; k++){
//                 int x = max({a[i] , a[j] , a[k]});
//                 int y = min({a[i] , a[j] , a[k]});
//                 int z = x ^ a[i] ^ a[j] ^ a[k] ^ y;
//                 if(z == y && z > x / 2) cnt++;
//                 else if(z == x && z >
//                  y / 2) cnt++;
//             }
//         }
//     }
//     cout << cnt;
// }

// void run_with_file()
// {
//     if (fopen(file".inp", "r"))
//     {
//         freopen(file".inp", "r", stdin);
//         freopen(file".ans", "w", stdout);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     run_with_file();
//     int test_case = 1;
//     //cin >> test_case;
//     while (test_case--)
//     {
//         inp();
//         solve();
//     }
//     Times;
// }
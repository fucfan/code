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
#define file "test"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , q , num_block , block[N];
ll pref[N] , lazy[N] , dif[N] , a[N] , Max;
vector <ll> value[N];

void update(int pos , ll val){
    for(int i = block[pos] + 1 ; i <= num_block ; i++){
        lazy[i] += val - a[pos];
        Max = max(Max , lazy[i]);
    }
    for(int i = pos + 1 ; block[i] == block[pos] ; i++){
        dif[i] -= val - a[pos];
    }

    dif[pos] += val - a[pos];
    a[pos] = val;
    value[block[pos]].clear();

    for(int i = (int)sqrt(n) * (block[pos] - 1) + 1 ; block[i] == block[pos] ; i++){
        value[block[pos]].pb(dif[i]);
    }
    sort(all(value[block[pos]]));
}

int get(){
    int res = -1;
    for(int i = 1 ; i <= num_block ; i++){
        if(*lower_bound(all(value[i]) , lazy[i]) == lazy[i]){
                // cout << i << ' ' << (int)sqrt(n) * (i - 1) + 1 << "gg\n";
            for(int j = (int)sqrt(n) * (i - 1) + 1 ; block[j] == i ; j++){
                if(dif[j] - lazy[i] == 0){
                    res = j;
                    break;
                }
            }
            break;
        }
    }
    return res;
}

void prepare(){
    for(int i = 1 ; i <= n ; i += sqrt(n)){
        num_block++;
        for(int j = i ; j <= min(n , i + (int)sqrt(n) - 1) ; j++){
            // cout << j << ' ' << dif[j] << '\n';
            value[num_block].pb(dif[j]);
            block[j] = num_block;
        }
        sort(all(value[num_block]));
    }
}

void inp()
{
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        dif[i] = a[i] - pref[i - 1];
        // cout << dif[i] << ' ';
        pref[i] = pref[i - 1] + a[i];
    }
    // nl;
    prepare();
    for(int i = 1 ; i <= q ; i++){
        ll p , x;
        cin >> p >> x;
        update(p , x);
    // for(int i = 1 ; i <= n ; i++) cout << dif[i] << ' ';
    // cout<< "gg ";
    // for(int i = 1 ; i <= num_block ; i++) cout << lazy[i] << ' ';
    //  nl;
        cout << get() << '\n';
    }
    // cout << Max << '\n';
}

void solve()
{

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

// int n , q , num_block , block[N];
// ll pref[N] , sum[N] , lazy[N] , dif[N] , a[N];
// vector <ll> value[N];

// void update(int pos , ll val){
//     a[pos] = val;
//     for(int i = pos ; i <= n ; i++) pref[i] = pref[i - 1] + a[i];
// }

// int get(){
//     int res = -1;
//     for(int i = 1 ; i <= n ; i++){
//         if(a[i] - pref[i - 1] == 0){
//             res = i;
//             break;
//         }
//     }
//     return res;
// }

// void inp()
// {
//     cin >> n >> q;
//     for(int i = 1 ; i <= n ; i++){
//         cin >> a[i];
//         dif[i] = a[i] - pref[i - 1];
//         // cout << dif[i] << ' ';
//         pref[i] = pref[i - 1] + a[i];
//     }
//     for(int i = 1 ; i <= q ; i++){
//         ll p , x;
//         cin >> p >> x;
//         update(p , x);
//         // for(int i = 1 ; i <= n ; i++){
//         //     cout << a[i] << ' ';
//         // }
//         cout << get() << '\n';
//     }
// }

// void solve()
// {

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

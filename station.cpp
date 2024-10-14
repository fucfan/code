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
#define file "station"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
int n , a[N] , tree[4 * N];
ll cnt;
void build(int id , int l , int r){
    if(l == r){
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
}
int get1(int id , int l , int r , int u , int v , int x){
    if(u > v) return -1;
    if(l > v || r < u) return -1;
    if(tree[id] < x) return -1;
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int res = get1(id << 1 , l , mid , u , v , x);
    if(res == -1) res = get1(id << 1 | 1 , mid + 1 , r , u , v , x);
    return res;
}
int get2(int id , int l , int r , int u , int v , int x){
    if(u > v) return -1;
    if(l > v || r < u) return -1;
    if(tree[id] < x) return -1;
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int res = get2(id << 1 | 1 , mid + 1 , r , u , v , x);
    if(res == -1) res = get2(id << 1 , l , mid , u , v , x);
    return res;
}
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    build(1 , 1 , n);
}
void solve()
{
    for(int i = 1 ; i <= n ; i++){
        int pos1 = get1(1 , 1 , n , i + 1 , n , a[i]);
        if(pos1 != -1){
            if(a[pos1] == a[i]) cnt--;
            cnt++;
        }
        if(get2(1 , 1 , n , 1 , i - 1 , a[i]) != -1){
            // cout << get2(1 , 1 , n , 1 , i - 1 , a[i]) << ' ' << i << '\n';
            cnt++;
        }
    }
    cout << cnt;
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
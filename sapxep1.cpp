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
#define file "sapxep"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , len[N] , a[N], tree[N] , cnt[N] , num_lis[N];
bool out[N];
vector <int> check[N];
ll dp[N] , k;
void update(int id , int l , int r , int pos , int val){
    if(pos > r || pos < l) return;
    if(l == r){
        tree[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , pos , val);
    update(id << 1 | 1 , mid + 1 , r , pos , val);
    tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
}
int get(int id , int l , int r , int u , int v){
    if(u > r || l > v) return 0;
    if(u <= l && r <= v){
        // cout << l << ' ' << r << ' ' << tree[id] << '\n';
        return tree[id];
    }
    int mid = (l + r) >> 1;
    return max(get(id << 1 , l , mid , u , v) , get(id << 1 | 1 , mid + 1 , r , u , v));
}
void inp()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        // a[i] = n - i + 1;
    }
    int length = 1;
    for(int i = 1 ; i <= n ; i++){
        len[a[i]] = get(1 , 1 , n , 1 , a[i]) + 1;
        // cout << a[i] << '/' << len[a[i]] << ' ';
        length = max(length , len[a[i]]);
        update(1 , 1 , n , a[i] , len[a[i]]);
        check[len[a[i]]].pb(a[i]);
    }
    cnt[length + 1] = 1;
    for(int i = n ; i >= 1 ; i--){
        num_lis[i] += cnt[len[i] + 1];
        cnt[len[i]] += cnt[len[i] + 1];
        // cout << len[a[i]] << ' ' << cnt[len[a[i]]] << ' ' << cnt[len[a[i]] + 1] << '\n';
    }
    // for(int i = 1 ; i <= n ; i++){
    //     cout << num_lis[i] << ' ' << len[i] << '\n';
    // }
    // nl;
    // for(int i = 1 ; i <= length + 1 ; i++){
    //     cout << len[i] << ' ' << cnt[len[i]] << '\n';
    // }
    // nl;
    for(int i = 1 ; i <= length ; i++){
        sort(all(check[i]));
    }
    for(int i = 1 ; i <= length ; i++){
        for(int j = check[i].size() - 1 ; j >= 0 ; j--){
            if(k > num_lis[check[i][j]]){
                k -= num_lis[check[i][j]];
            }
            else{
                out[check[i][j]] = 1;
                break;
            }
        }
    }
    cout << n - length << '\n';
    for(int i = 1 ; i <= n ; i++){
        if(!out[i]) cout << i << '\n';
    }
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
    // cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}

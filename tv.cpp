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
#define file "tv"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , l;
ll ans , a[205][20005];
int bs2(int l , int r , int x , ll env[20005]){
    if(r - l <= 1){
        if(env[r] <= x) return r;
        return l;
    }
    int mid = (l + r) / 2;
    if(x >= env[mid]) return bs2(mid , r , x , env);
    if(x < env[mid]) return bs2(l , mid , x , env);
    return 0;
}
int bs1(int l , int r , int x , ll env[20005]){
    if(r - l <= 1){
        if(env[l] == x) return l;
        if(env[r] <= x) return r;
        return l;
    }
    int mid = (l + r) / 2;
    if(x > env[mid]) return bs1(mid , r , x , env);
    if(x <= env[mid]) return bs1(l , mid , x , env);
    return 0;
}
void inp()
{
    cin >> n >> l;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= l ; j++){
            cin >> a[i][j];
        }
    }
}

void solve()
{
    for(int i = 1 ; i <= n - 1 ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            bool find = false;
            int left = 1;
            int right = l;
            while(left <= right){
                bool check = false;
                int mid = (left + right) / 2;
                int pos1 = bs1(1 , l , a[j][mid] , a[i]);
                int pos2 = bs2(1 , l , a[j][mid] , a[i]);
                // cout << pos1 << ' ' << pos2 << '\n';
                int val = pos2 - pos1 + 1;
                if(a[i][pos2] == a[j][mid]) val++;
                int less = pos1;
                if(a[i][pos1] >= a[j][mid]) less--;
                int more = l - pos2;
                if(pos2 == 1 && a[i][pos2] > a[j][mid]) more++;
                int pos3 = bs1(1 , l , a[j][mid] , a[j]);
                int pos4 = bs2(1 , l , a[j][mid] , a[j]);
                less += pos3 - 1;
                more += l - pos4;
                if(less < more - 1 && less + val >= more - 1) check = true;
                if(less > more - 1 && more + val - 1 >= less) check = true;
                if(less == more - 1) check = true;
                    // cout << a[j][mid] << '\n';
                    // cout << less << ' ' << more << '\n';
                    // cout << pos1 << ' ' << pos2 << '\n';
                    // cout << pos3 << ' ' << pos4 << '\n';
                if(check){
                    // cout << a[j][mid] << '\n';
                    // cout << pos1 << ' ' << pos2 << '\n';
                    // cout << pos3 << ' ' << pos4 << '\n';
                    ans = (ans + ((a[j][mid] + mod) % mod)) % mod;
                    find = true;
                    break;
                }
                else if(less < more) left = mid + 1;
                else right = mid - 1;
            }
            if(find) continue;
            left = 1;
            right = l;
            while(left <= right){
                bool check = false;
                int mid = (left + right) / 2;
                int pos1 = bs1(1 , l , a[i][mid] , a[j]);
                int pos2 = bs2(1 , l , a[i][mid] , a[j]);
                int val = pos2 - pos1 + 1;
                if(a[j][pos2] == a[i][mid]) val++;
                int less = pos1;
                if(a[j][pos1] >= a[i][mid]) less--;
                int more = l - pos2;
                if(pos2 == 1 && a[j][pos2] > a[i][mid]) more++;
                int pos3 = bs1(1 , l , a[i][mid] , a[i]);
                int pos4 = bs2(1 , l , a[i][mid] , a[i]);
                less += pos3 - 1;
                more += l - pos4;
                if(less < more - 1 && less + val >= more - 1) check = true;
                if(less > more - 1 && more + val - 1 >= less) check = true;
                if(less == more - 1) check = true;
                if(check){
                    // cout << a[i][mid] << '\n';
                    // cout << less << ' ' << more << '\n';
                    // cout << pos1 << ' ' << pos2 << '\n';
                    // cout << pos3 << ' ' << pos4 << '\n';
                    ans = (ans + ((a[i][mid] + mod) % mod)) % mod;
                    break;
                }
                else if(less < more) left = mid + 1;
                else right = mid - 1;
            }
        }
    }
    cout << ans;
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}
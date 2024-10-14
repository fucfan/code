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
#define file "phuc"
using namespace std;

template<class T1, class T2> void mini(T1 &a, T2 b) {if (a > b) a = b;}
template<class T1, class T2> void maxi(T1 &a, T2 b) {if (a < b) a = b;}

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;
int n , m , a[N] , rmq[N][LOG + 5] , lg2[N];
struct query{
    int l , r , num;
} q[N];
bool cmp(query a , query b){
    // cout << a.l << ' ' << a.r << ' ' << b.l << ' ' << b.r << '\n';
    if(a.l == b.l) return a.r < b.r;
    if(a.r == b.r) return a.l > b.l;
    // if(a.l == b.r) return false;
    int vala = -1;
    int valb = -1;
    if(a.l < b.l){
        int l = a.l;
        int r = min(a.r , b.l);
        if(a.r >= b.l) r--;
        if(r >= l){
            int length = lg2[r - l + 1];
            vala = max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
        }
        l = max(a.r , b.l);
        r = b.r;
        if(a.r >= b.l) l++;
        if(r >= l){
            int length = lg2[r - l + 1];
            valb = max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
        }
        // cout << vala << ' ' << valb << '\n';
        return vala < valb;
    }
    else{
        int l = b.l;
        int r = min(b.r , a.l);
        if(b.r >= a.l) r--;
        // cout << l << ' ' << r << '\n';
        if(r >= l){
            int length = lg2[r - l + 1];
            // cout << length << '\n';
            valb = max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
        }
        l = max(b.r , a.l);
        r = a.r;
        if(b.r >= a.l) l++;
        // cout << l << ' ' << r << '\n';
        if(r >= l){
            int length = lg2[r - l + 1];
            // cout << length << '\n';
            vala = max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
        }
        // cout << vala << ' ' << valb << '\n';
        return vala < valb; 
    }
    return 0;
}
void prepare(){
    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i <= n ; i++){
            rmq[i][j] = max(rmq[i][j - 1] , rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        while((1 << lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}
void inp()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> rmq[i][0];
    }
    prepare();
    for(int i = 1 ; i <= m ; i++){
        cin >> q[i].l >> q[i].r;
        q[i].num = i;
    }
    sort(q + 1 , q + 1 + m , cmp);
    for(int i = 1 ; i <= m ; i++){
        cout << q[i].num << ' ';
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
    //cin >> test_case;
    while (test_case--)
    {
        inp();
        solve();
    }
    Times;
}
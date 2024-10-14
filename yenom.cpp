#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll , ll>
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
const int N = 2e3 + 5;
const int LOG = 20;

int n , a[N];
ll d[N] , T;
ll ans;

void dijsktra(){
    mem(d , 0x3f);
    d[0] = 0;
    priority_queue <pii , vector<pii> , greater<pii>> q;
    q.push({d[0] , 0});
    while(q.size()){
        int u = q.top().se;
        ll dis = q.top().fi;
        // cout << u << ' ' << dis << '\n';
        q.pop();
        if(dis > d[u]) continue;
        for(int i = 1 ; i <= n ; i++){
            int v = (u + a[i]) % a[1];
            ll w = a[i];
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v] , v});
            }

            v = (u - a[i] + a[1] * a[1]) % a[1];
            if(d[v] > d[u] - a[i] && d[u] >= a[i]){
                d[v] = d[u] - a[i];
                q.push({d[v] , v});
            }
        }
    }

    for(int i = 0 ; i < a[1] ; i++){
        // cout << i << ' ' << d[i] << '\n';
        if(d[i] > T) continue;
        ans += (T - d[i]) / a[1] + 1;
    }

    cout << ans;
}

void inp()
{
    cin >> n >> T;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
}

void solve()
{
    dijsktra();
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
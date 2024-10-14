#include<bits/stdc++.h>

#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<ll, ll>
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
const int N = 1e6 + 5e5 +2;
const int LOG = 20;
int n ;
vector <pair <pii , pii>> event[2];
ll res = 0;

bool cmp(pair<pii , pii> a , pair <pii , pii> b){
    if(a.fi.fi == b.fi.fi) return a.fi.se > b.fi.se;
    return a.fi.fi < b.fi.fi;
}

struct segment_tree{
    pii node[N << 3 | 1];
    ll lazy[N << 3 | 1];

    void down(int id , int l , int r){
        int mid = (l + r) >> 1;

        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];

        if(lazy[id] > 0){
            node[id << 1].fi += node[id << 1].se * lazy[id] + 1ll * (mid - l + 1) * ((lazy[id] - 1) * lazy[id]) / 2;
            node[id << 1].se += lazy[id] * (mid - l + 1);

            node[id << 1 | 1].fi += node[id << 1 | 1].se * lazy[id] + 1ll * (r - mid) * ((lazy[id] - 1) * lazy[id]) / 2;
            node[id << 1 | 1].se += lazy[id] * (r - mid);
        }
        if(lazy[id] < 0){
            lazy[id] *= -1;
            node[id << 1].se -= lazy[id] * (mid - l + 1);
            node[id << 1].fi -= node[id << 1].se * lazy[id] + 1ll * (mid - l + 1) * ((lazy[id] - 1) * lazy[id]) / 2;

            node[id << 1 | 1].se -= lazy[id] * (r - mid);
            node[id << 1 | 1].fi -= node[id << 1 | 1].se * lazy[id] + 1ll * (r - mid) * ((lazy[id] - 1) * lazy[id]) / 2;
        }
        
        // if(lazy[id])cout << l - N << ' ' << r - N << ' ' << node[id << 1].fi << ' ' << node[id << 1].se << ' ' << node[id << 1 | 1].fi << ' ' << node[id << 1 | 1].se << ' ' << lazy[id] << "ff\n";
        lazy[id] = 0;
    }

    void update(int id , int l , int r , int u , int v , int val){
        if(u > r || l > v) return;
        if(u <= l && r <= v){
        // cout << l - N << ' ' << r - N << ' ' << node[id].fi << ' ' << node[id].se << ' ' << lazy[id] << "kk\n";
            // cout << l - N << ' ' << r - N << ' ' << node[id].fi << ' ' << node[id].se << ' ' << lazy[id] << "kk\n";
            if(val > 0){
                node[id].fi += node[id].se;
                node[id].se += r - l + 1;
            }
            else{
                node[id].se -= r - l + 1;
                node[id].fi -= node[id].se;
            }
            // cout << l - N << ' ' << r - N << ' ' << node[id].fi << ' ' << node[id].se << "gg\n";
            lazy[id] += val;
        // cout << u - N << ' ' << v - N << ' ' << l - N << ' ' << r - N << ' ' << node[id].fi << ' ' << node[id].se << ' ' << lazy[id] << "kk\n";
            return;
        }

        int mid = (l + r) >> 1;

        down(id , l , r);

        update(id << 1 , l , mid , u , v , val);
        update(id << 1 | 1 , mid + 1 , r , u , v , val);


        node[id].fi = node[id << 1].fi + node[id << 1 | 1].fi;
        node[id].se = node[id << 1].se + node[id << 1 | 1].se;

        // cout << u - N << ' ' << v - N << ' ' << l - N << ' ' << r - N << ' ' << node[id].fi << ' ' << node[id].se << ' ' << lazy[id] << ' ' << node[id << 1].fi << ' ' << node[id << 1 | 1].fi << "gg\n";
    }
    void check(int id , int l , int r){
        if(l == r){
        // cout << l - N << ' ' << r - N << ' ' << node[id].fi << ' ' << node[id].se << ' ' << lazy[id] << "ff\n";
            return;
        }
        int mid = (l + r) >> 1;

        down(id , l , r);

        check(id << 1 , l , mid);
        check(id << 1 | 1 , mid + 1 , r);

        // if(node[id].fi)cout << l - N << ' ' << r - N << ' ' << node[id].fi << ' ' << node[id].se << ' ' << lazy[id] << "ff\n";
    }
    int get(int id , int l , int r , int u , int v){
        if(u > r || l > v) return 0;
        if(u <= l && r <= v){
            return node[id].fi;
        }
        int mid = (l + r) >> 1;

        down(id , l , r);

        return get(id << 1 , l , mid , u , v)
             + get(id << 1 | 1 , mid + 1 , r , u , v);
    }
} st;

void sol(int type){
    sort(all(event[type]) , cmp);
    for(int g = 0 ; g < event[type].size() ; g++){
        if(g > 0 && event[type][g].fi.fi != event[type][g - 1].fi.fi){
            res += st.node[1].fi;
        }
        st.update(1 , 1 , 2 * N , event[type][g].se.fi + N , event[type][g].se.se + N , event[type][g].fi.se);
        // cout << event[type][g].fi.fi << ' ' << event[type][g].fi.se << ' ' << event[type][g].se.fi << ' ' << event[type][g].se.se << ' ' << st.node[1].fi << ' ' << st.node[1].se << ' ' << res << ' ' << '\n';
    }
    event[type].clear();
}

void inp()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
        int x , y , l , type;
        cin >> x >> y >> l >> type;
        if(type == 0){
            event[(x + y) & 1].pb({{x - y , 1} , {(x + y) / 2 , (x + y) / 2 + l / 2}});
            event[(x + y) & 1].pb({{x - y + 1 , -1} , {(x + y) / 2 , (x + y) / 2 + l / 2}});
            event[(x + y + 1) & 1].pb({{x + 1 - y , 1} , {(x + y + 1) / 2 , (x + y + 1) / 2 + (l + 1) / 2 - 1}});
            event[(x + y + 1) & 1].pb({{x + 2 - y , -1} , {(x + y + 1) / 2 , (x + y + 1) / 2 + (l + 1) / 2 - 1}});
        }
        else{
            event[(x + y) & 1].pb({{x - y , 1} , {(x + y) / 2 , (x + y) / 2 + l / 2}});
            event[(x + y) & 1].pb({{x - y + 1 , -1} , {(x + y) / 2 , (x + y) / 2 + l / 2}});
            event[(x + y - 1) & 1].pb({{x - 1 - y , 1} , {(x + y + 1) / 2 , (x + y + 1) / 2 + (l + 1) / 2 - 1}});
            event[(x + y - 1) & 1].pb({{x - y , -1} , {(x + y + 1) / 2 , (x + y + 1) / 2 + (l + 1) / 2 - 1}});
        }
	}
}

void solve()
{
    sol(0);
    // st.check(1 , 1 , 2 * N);
    // nl;
    sol(1);
    // st.update(1 , 1 , 2 * N , 11 + N , 12 + N , -1);
    // st.check(1 , 1 , 2 * N);
    // nl;
    cout << res << '\n';
    res = 0;
    // mem(st.lazy , 0);
    // mem(st.node , 0);
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
    cin >> test_case;
    while (test_case--) 
    {
        inp();
        solve();
    }
    Times;
}

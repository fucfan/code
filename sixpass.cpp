#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<ll, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define sub(x , y) ((x) - (y) < 0 ? ((x) - (y) + mod) : ((x) - (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;

const ll loo = 1e18 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct pple{
    int dur , pow;
    int id;

    bool operator<(pple b){
        return dur < b.dur;
    }

    bool operator>(pple b){
        if(pow == b.pow){
            return dur > b.dur;
        }
        return pow > b.pow;
    }
} p[N];

int n , m , cur;
vector <pii> pow_of_dur[N];

struct segment_tree{
    pii node[N << 2 | 1];
    ll lazy[N];

    void dơwn(int id){
        node[id << 1] *= 
        node[id << 1 | 1] *= 
    }

    void build(int id , int l , int r){
        if(l == r){
            node[id] = pow_of_dur[l][0];
            node[id].fi *= l;
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1 , l , mid);
        build(id << 1 | 1 , mid + 1 , r);

        node[id] = max(node[id << 1] , node[id << 1 | 1]);
    }

    void update(int id , int l , int r , int pos , pii val){
        if(l == r){
            node[id] = val;
            return;
        }

        int mid = (l + r) >> 1;
        
        update(id << 1 , l , mid , pos);
        update(id << 1 | 1 , mid + 1 , r , pos);

        node[id] = max(node[id << 1] , node[id << 1 | 1]);
    }

    pii get(int id , int l , int r , int u , int v){
        if(u > r || l > v) return {0 , 0};

        if(u <= l && r <= v) return node[id];

        int mid = (l + r) >> 1;

        return max(get(id << 1 , l , mid , u , v) ,
                   get(id << 1 | 1 , mid + 1 , r , u , v));
    }
} st;

bool cmp(pple a , pple b){
    return a.dur > b.dur;
}


void inp(){
    cin >> m >> n;
    cur = m;
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i].pow >> p[i].dur;
        p[i].id = i;
        pow_of_dur[p[i].dur].pb({p[i].pow , p[i].id});
    }
}

void solve(){
    for(int i = 1 ; i <= m ; i++) sort(all(pow_of_dur[i]) , greater<>());
    st.build(1 , 1 , m);
    ll sum_pow = 0;
    for(int i = 1 ; i <= 6 ; i++){
        pii tmp = st.get(1 , 1 , m , 1 , m);
        sum_pow += ;

    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        inp();
        solve();
    }
}

/*      UwU      */
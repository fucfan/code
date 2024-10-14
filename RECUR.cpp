#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) = (x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "recur"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".out", "w" , stdout);
    }
}

struct Query{
    int l , r;
    
    bool operator<(Query b){
        return r < b.r;
    }

    bool operator>(Query b){
        return l < b.l;
    }
} query[N];

int n , q , a[N];
bool check_sub3;
pii rmq[N][LOG + 5];
int lg2[N];

void prepare(){
    for(int i = 1 ; i <= n ; i++){
        rmq[i][0] = {a[i] , i};
    }

    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i + (1 << (j - 1)) <= n ; i++){
            rmq[i][j] = max(rmq[i][j - 1] , rmq[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        while((1 << lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

pii get(int l , int r){
    int length = lg2[r - l + 1];
    return max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
}

ll cal(int l , int r){
    if(l > r) return 0;

    int mid = get(l , r).se;

    return cal(l , mid - 1) + cal(mid + 1 , r) + (r - l + 1);
}

void sub12(){
    prepare();

    for(int i = 1 ; i <= q ; i++){
        int l = query[i].l;
        int r = query[i].r;
        cout << cal(l , r) << ' ';
    }
}

void sub3(){
    for(int i = 1 ; i <= q ; i++){
        ll l = query[i].l;
        ll r = query[i].r;
        // cout << l << ' ' << r << '/';
        cout << ((r - l + 1) + 1) * (r - l + 1) / 2 << ' ';
    }
}

// void sub4(){
//     int num_block , block[N];
//     vector <Query> path[N];

//     sort(query + 1 , query + 1 + q);

//     int tmp = sqrt(n);

//     for(int i = 1 ; i <= q ; i++){
//         if(tmp < query[i].r) num_block++;
//         while(tmp < query[i].r) tmp += sqrt(n);
//         block[i] = num_block;
//         path[num_block].pb(query[i]);
//     }

//     int l = 1 , r = 1;
//     int length_l = 1  , length_r = 1;
//     ll res = 1;

//     for(int i = 1 ; i <= num_block ; i++){
//         sort(all(path[i]) , greater<>());
//         if(i & 1) reverse(all(path[i]));

//         for(auto j : path[i]){
//             if(l > j.l){
//                 while(l > j.l){
//                     l--;
//                     if(a[l] > a[l + 1]) length_l =  
//                 }
//             }
//             else if(r < j.r){

//             }
//         }
//     }
// }

void inp(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= q ; i++) cin >> query[i].l;
    for(int i = 1 ; i <= q ; i++) cin >> query[i].r;
}

void solve(){
    check_sub3 = 1;
    for(int i = 2 ; i < n ; i++){
        if(a[i] - a[i - 1] != a[i + 1] - a[i]) check_sub3 = 0;
    }

    if(check_sub3) sub3();
    else sub12();
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

/*
#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a >> b) & 1)
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define add(x , y) ((x) = (x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

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

struct Query{
    int l , r;
} query[N];

int n , q , a[N];
bool check_sub3;
pii rmq[N][LOG + 5];
int lg2[N];

void prepare(){
    for(int i = 1 ; i <= n ; i++){
        rmq[i][0] = {a[i] , i};
    }

    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i + (1 << (j - 1)) <= n ; i++){
            rmq[i][j] = max(rmq[i][j - 1] , rmq[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        while((1 << lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

pii get(int l , int r){
    int length = lg2[r - l + 1];
    return max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
}

ll cal(int l , int r){
    if(l > r) return 0;

    int mid = get(l , r).se;

    return cal(l , mid - 1) + cal(mid + 1 , r) + (r - l + 1);
}

void sub12(){
    prepare();

    for(int i = 1 ; i <= q ; i++){
        int l = query[i].l;
        int r = query[i].r;
        cout << cal(l , r) << ' ';
    }
}

void sub3(){
    for(int i = 1 ; i <= q ; i++){
        int l = query[i].l;
        int r = query[i].r;
        // cout << l << ' ' << r << '/';
        cout << ((r - l + 1) + 1) * (r - l + 1) / 2 << ' ';
    }
}

void inp(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= q ; i++) cin >> query[i].l;
    for(int i = 1 ; i <= q ; i++) cin >> query[i].r;
}

void solve(){
    check_sub3 = 1;
    for(int i = 2 ; i < n ; i++){
        if(a[i] - a[i - 1] != a[i + 1] - a[i]) check_sub3 = 0;
    }

    if(check_sub3) sub3();
    else sub12();
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
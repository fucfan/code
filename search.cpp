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
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "search"
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

struct segment{
    int l , r;

    bool operator<(segment b){
        return r < b.r;
    }

    bool operator>(segment b){
        return l < b.l;
    }
} seg[N];

int n , m , p , a[N] , b[N] , c[N] , lg2[N] , range[N] , num_block , cnt[N] , sz_n , sz_m;
int rmq[N][LOG + 5];
vector <segment> block[N];

void prepare(){
    for(int i = 1 ; i <= p ; i++){
        rmq[i][0] = 1;

        if(c[i] == *lower_bound(a + 1 , a + 1 + n , c[i])){
            rmq[i][0] = 0;
        }
        if(c[i] == *lower_bound(b + 1 , b + 1 + m , c[i])){
            rmq[i][0] = 2;
        }
    }

    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i + (1 << (j - 1)) <= p ; i++){
            rmq[i][j] = max(rmq[i][j - 1] , rmq[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1 ; i <= p ; i++){
        while((1 << lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

int get_max(int l , int r){
    int length = lg2[r - l + 1];
    return max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
}

void get_range(){

    sort(a + 1 , a + 1 + n);
    sort(b + 1 , b + 1 + m);

    prepare();

    for(int i = 1 ; i <= p ; i++){
        int l = i , r = p;

        while(l <= r){
            int mid = (l + r) >> 1;

            // cout << i << ' ' << mid << ' ' << get_max(i , mid) << '\n';

            bool check = (get_max(i , mid) < 2);

            if(check){
                l = mid + 1;
                range[i] = max(range[i] , mid - i + 1);
            }
            else r = mid - 1;
        }
    }
}

void prepare_mo(){
    for(int i = 1 ; i <= p ; i++){
        seg[i] = {i , i + range[i] - 1};
    }

    sort(seg + 1 , seg + 1 + p);

    int tmp = sqrt(p);

    for(int i = 1 ; i <= p ; i++){
        if(seg[i].r < seg[i].l) continue;
        if(seg[i].r > tmp) num_block++;

        while(seg[i].r > tmp){
            tmp += sqrt(p);
        }

        block[num_block].pb(seg[i]);
    }
}

void inp(){
    cin >> n >> m >> p;

    set <int> tmp;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        tmp.insert(a[i]);
    }

    sz_n = tmp.size();
    tmp.clear();

    for(int i = 1 ; i <= m ; i++) cin >> b[i];
    for(int i = 1 ; i <= p ; i++) cin >> c[i];
}

void solve(){
    int ans = 0;

    get_range();
    prepare_mo();

    int l = 1 , r = 1;
    int tmp = !rmq[1][0];
    cnt[c[1]]++;

    for(int i = 0 ; i <= num_block ; i++){
        sort(all(block[i]) , greater<>());
        if(i & 1) reverse(all(block[i]));

        for(auto j : block[i]){
            // cout << j.l << ' ' << j.r << ' ' << tmp << '\n';
            // for(int i = 1 ; i <= n + m ; i++) cout << cnt[i] << ' ';
            // nl;
            while(j.l < l){
                l--;
                cnt[c[l]]++;
                if(cnt[c[l]] == 1) if(!rmq[l][0]) tmp++;
            }

            while(j.l > l){
                cnt[c[l]]--;
                if(!cnt[c[l]]) if(!rmq[l][0]) tmp--;
                l++;
            }

            while(j.r < r){
                cnt[c[r]]--;
                if(!cnt[c[r]]) if(!rmq[r][0]) tmp--;
                r--;
            }

            while(j.r > r){
                r++;
                cnt[c[r]]++;
                if(cnt[c[r]] == 1) if(!rmq[r][0]) tmp++;
            }

            if(tmp == sz_n){
                ans = max(ans , j.r - j.l + 1);
            }
        }
    }

    cout << ans;
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

/*#include<bits/stdc++.h>
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
#define add(x , y) ((x) + (y) >= mod ? ((x) + (y) - mod) : ((x) + (y)))
#define file "test"
#define Times cerr << "\nTime run: " << clock() / 1000.0 << " ms\n";
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e3 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".ans", "w" , stdout);
    }
}

struct segment{
    int l , r;

    bool operator<(segment b){
        return r < b.r;
    }

    bool operator>(segment b){
        return l < b.l;
    }
} seg[N];

int n , m , p , a[N] , b[N] , c[N] , lg2[N] , range[N] , num_block , cnt[N];
int rmq[N][LOG + 5];
vector <segment> block[N];

void prepare(){
    
    sort(a + 1 , a + 1 + n);
    sort(b + 1 , b + 1 + m);

    for(int i = 1 ; i <= p ; i++){
        rmq[i][0] = 1;

        if(c[i] == *lower_bound(a + 1 , a + 1 + n , c[i])){
            rmq[i][0] = 0;
        }
        if(c[i] == *lower_bound(b + 1 , b + 1 + m , c[i])){
            rmq[i][0] = 2;
        }
    }

    for(int j = 1 ; j <= LOG ; j++){
        for(int i = 1 ; i + (1 << (j - 1)) <= p ; i++){
            rmq[i][j] = max(rmq[i][j - 1] , rmq[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1 ; i <= p ; i++){
        while((1 << lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

int get_max(int l , int r){
    int length = lg2[r - l + 1];
    return max(rmq[l][length] , rmq[r - (1 << length) + 1][length]);
}

void get_range(){

    prepare();

    for(int i = 1 ; i <= p ; i++){
        int l = i , r = p;

        while(l <= r){
            int mid = (l + r) >> 1;

            // cout << i << ' ' << mid << ' ' << get_max(i , mid) << '\n';

            bool check = (get_max(i , mid) < 2);

            if(check){
                l = mid + 1;
                range[i] = max(range[i] , mid - i + 1);
            }
            else r = mid - 1;
        }
    }
}

void prepare_mo(){
    for(int i = 1 ; i <= p ; i++){
        seg[i] = {i , i + range[i] - 1};
    }

    sort(seg + 1 , seg + 1 + p);

    int tmp = sqrt(p);

    for(int i = 1 ; i <= p ; i++){
        if(seg[i].r > tmp) num_block++;

        while(seg[i].r > tmp){
            tmp += sqrt(p);
        }

        block[num_block].pb(seg[i]);
    }
}

void inp(){
    cin >> n >> m >> p;

    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= m ; i++) cin >> b[i];
    for(int i = 1 ; i <= p ; i++) cin >> c[i];
}

void solve(){
    prepare();
    int ans = 0;
    for(int i = 1 ; i <= p ; i++){
        int tmp = 0;
        mem(cnt , 0);
        for(int j = i ; j <= p ; j++){
            cnt[c[j]]++;
            if(cnt[c[j]] == 1 && !rmq[j][0]){
                tmp++;
            }
            if(rmq[j][0] == 2){
                break;
            }
            if(tmp == n) ans = max(ans , j - i + 1);
        }
    }
    cout << ans;
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
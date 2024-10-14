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
#define file "segment"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e3 + 5;
const int LOG = 20;

struct Point{
    ll x , y;
};

struct segment{ 
    Point l , r;
} seg[N];

int n , cnt[N];
bool check[N];
vector <int> touch[N];

ll S(Point p1 , Point p2 , Point p3){
    return (p1.y + p2.y) * (p2.x - p1.x) + (p2.y + p3.y) * (p3.x - p2.x) - (p3.y + p1.y) * (p3.x - p1.x);
}

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> seg[i].l.x >> seg[i].l.y >> seg[i].r.x >> seg[i].r.y;
        if(seg[i].l.x > seg[i].r.x) swap(seg[i].l , seg[i].r);
    }
}

void solve(){
    queue <int> q;
    mem(cnt , 0);
    for(int i = 1 ; i < n ; i++){
        if(check[i]) continue;
        for(int j = i + 1 ; j <= n ; j++){
            if(check[j]) continue;
            if(seg[j].l.x <= seg[i].l.x && seg[i].l.x <= seg[j].r.x){
                if(S(seg[j].l , seg[i].l , seg[j].r) > 0){
                    cnt[i]++;
                    touch[j].pb(i);
                    continue;
                }
            }
            if(seg[j].l.x <= seg[i].r.x && seg[i].r.x <= seg[j].r.x){
                if(S(seg[j].l , seg[i].l , seg[j].r) > 0){
                    cnt[i]++;
                    touch[j].pb(i);
                    continue;
                }
            }
            if(seg[i].l.x <= seg[j].l.x && seg[j].l.x <= seg[i].r.x){
                if(S(seg[i].l , seg[j].l , seg[i].r) > 0){
                    cnt[j]++;
                    touch[i].pb(j);
                    continue;
                }
            }
            if(seg[i].l.x <= seg[j].r.x && seg[j].r.x <= seg[i].r.x){
                if(S(seg[i].l , seg[j].l , seg[i].r) > 0){
                    cnt[j]++;
                    touch[i].pb(j);
                    continue;
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++) if(!cnt[i]){
        q.push(i);
    }

    // return cout << 1, void();

    while(q.size()){
        cout << q.front() << ' ';
        int i = q.front();
        q.pop();
        check[i] = 1;
        for(auto j : touch[i]){
            if(check[j]) continue;
            cnt[j]--;
            if(!cnt[j]){
                q.push(j);
                check[j] = 1;
            }
        }
    }
}

void run_with_file(){
    if(fopen(file".inp","r")){
        freopen(file".inp","r", stdin);
        freopen(file".out", "w", stdout);
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
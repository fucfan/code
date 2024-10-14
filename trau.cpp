#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) (((a) >> (b)) & 1)
#define flip(a , b) ((a) ^ (1ll << (b)))
#define pii pair<int, int>
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
const int N = 1e4 + 5;
const int LOG = 20;
const int base = 31;

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp", "r" , stdin);
        freopen(file".ans", "w" , stdout);
    }
}

struct dishes{
    int time_cook, good;

    void input(){
        cin >> time_cook >> good;
    }
} d[N];

int n, st, en, judge;
int dp[(1 << 15)][1509];

namespace sub5{
    bool check(){
        return (n <= 15);
    }

    int sol(int mask, int st){
        // cout << st << ' ';
        // for(int i = 1; i <= n; i++) cout << BIT(mask, i - 1);
        // nl;
        int cur = st;
        for(int j = 1; j <= n; j++){
            if(BIT(mask, j - 1)) cur += d[j].time_cook;
        }
        if(cur > en) return oo;
        // cout << i << ' ' << mask << '\n';
        if(mask == ((1 << n) - 1)){
            return 0;
        }
        int res = oo;
        if(dp[mask][st] != -1) return dp[mask][st];
        for(int j = 1; j <= n; j++){
            if(BIT(mask, j - 1)) continue;
            // cout << j << ' ' << "gg\n";
            // cout << (cur + d[j].time_cook) * d[j].good << '\n';
            res = min(res, sol(flip(mask, j - 1), st) +
                           abs(judge - (cur + d[j].time_cook)) * d[j].good);
        }

        return dp[mask][st] = res;
    }

    void solve(){
        mem(dp, -1);
        int ans = oo;
        for(int i = st; i <= en; i++){
            // mem(dp, -1);
            int tmp = sol(0, i);
            ans = min(ans, tmp);
            if(tmp == oo) break;
        }
        cout << ans;
    }
}

namespace sub3{
    bool check(){
        return (judge == st);
    }

    bool cmp(dishes a, dishes b){
        return (a.time_cook * a.good + (a.time_cook + b.time_cook) * b.good <
                b.time_cook * b.good + (a.time_cook + b.time_cook) * a.good);
    }

    void solve(){
        sort(d + 1, d + 1 + n, cmp);

        ll res = 0;
        int cur = 0;

        for(int i = 1; i <= n; i++){
            cur += d[i].time_cook;
            res += cur * d[i].good;
        }

        cout << res;
    }
}

namespace sub4{
    bool check(){
        return (judge == en);
    }

    bool cmp(dishes a, dishes b){
        return (a.time_cook * b.good <
                b.time_cook * a.good);
    }

    void solve(){
        sort(d + 1, d + 1 + n, cmp);

        ll res = 0;
        int cur = en;

        for(int i = 1; i <= n; i++){
            res += (en - cur) * d[i].good;
            cur -= d[i].time_cook;
        }

        cout << res;
    }
}

namespace sub6{
    bool check(){
        return (n <= 20);
    }

    bool cmp_rig(dishes a, dishes b){
        return (a.time_cook * a.good + (a.time_cook + b.time_cook) * b.good <
                b.time_cook * b.good + (a.time_cook + b.time_cook) * a.good);
    }

    bool cmp_lef(dishes a, dishes b){
        return (a.time_cook * b.good <
                b.time_cook * a.good);
    }

    void solve(){
        ll res = loo;
        for(int mask = 0; mask < (1 << n); mask++){
            ll val = 0;
            vector <dishes> lef, rig;
            int cnt_lef = 0;
            int cnt_rig = 0;
            int time_rig = en - judge;
            int time_lef = judge - st;

            for(int i = 1; i <= n; i++){
                if(!BIT(mask, i - 1)){
                    lef.pb(d[i]);
                    cnt_lef += d[i].good;
                    time_lef -= d[i].time_cook;
                }
                else{
                    rig.pb(d[i]);
                    cnt_rig += d[i].good;
                    time_rig -= d[i].time_cook;
                }
            }

            sort(all(lef), cmp_lef);
            sort(all(rig), cmp_rig);

            if(time_lef < 0 || (rig.size() && time_rig < 0 && -time_rig > rig[0].time_cook)) continue;

            int cur = 0;
            for(auto j : rig){
                cur += j.time_cook;
                val += cur * j.good;
            }

            cur = judge;
            for(auto j : lef){
                val += (judge - cur) * j.good;
                cur -= j.time_cook;
            }

            if(time_rig < 0){
                val -= abs(time_rig) * cnt_rig;
                val += abs(time_rig) * cnt_lef;
            }

            // for(int i = 1; i <= n; i++){
            //     cout << BIT(mask, i - 1);
            // }
            // cout << ' ' << time_rig << ' ' << val << '\n';

            res = min(res, val);
        }

        cout << res;
    }
}

void inp(){
    cin >> n >> st >> en >> judge;
    for(int i = 1; i <= n; i++)
        d[i].input();
}

void solve(){
    // if(sub3::check()) return sub3::solve();
    // if(sub4::check()) return sub4::solve();
    if(sub5::check()) return sub5::solve();
    // if(sub6::check()) return sub6::solve();
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

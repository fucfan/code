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
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n , k , a[N];
string s , t;
ll ans , pref[N];
queue <int> pos[30][3];
vector <ll> dis;
vector <pii> correct;
void inp()
{
    cin >> n >> k >> s >> t;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
}

void solve()
{
    s = " " + s;
    t = " " + t;
    correct.pb({oo , 0});
    for(int i = 1 ; i <= n ; i++){
        if(s[i] != t[i]){
            int c1 = s[i] - 'a' + 1;
            int c2 = t[i] - 'a' + 1;
            if(pos[c1][2].empty()) pos[c1][1].push(i);
            else{
                pii dis1 = correct.back();
                pii dis2 = {pos[c1][2].front() , i};
                // if(c1 == 'o' - 'a' + 1) cout << dis2.fi << ' ' << dis2.se << "alabama\n";
                // cout << dis1.fi << ' ' << dis1.se << "gg\n";
                pos[c1][2].pop();
                if(dis2.fi > dis2.se) swap(dis2.fi , dis2.se);
                while(dis2.fi <= dis1.fi && dis1.se <= dis2.se){
                    correct.pop_back();
                    if(correct.empty()) break;
                    dis1 = correct.back();
                }
                if(correct.empty()) correct.pb(dis2);
                else if(correct.back().se >= dis2.fi) correct.back().se = max(correct.back().se , dis2.se);
                else correct.pb(dis2);
            }
            if(pos[c2][1].empty()) pos[c2][2].push(i);
            else{
                pii dis1 = correct.back();
                pii dis2 = {pos[c2][1].front() , i};
                pos[c2][1].pop();
                if(dis2.fi > dis2.se) swap(dis2.fi , dis2.se);
                while(dis2.se <= dis1.fi && dis1.se <= dis2.se){
                    correct.pop_back();
                    if(correct.empty()) break;
                    dis1 = correct.back();
                }
                if(correct.empty()) correct.pb(dis2);
                else if(correct.back().se >= dis2.fi) correct.back().se = max(correct.back().se , dis2.se);
                else correct.pb(dis2);
            }
        }
    }
    for(auto j : correct) ans += pref[j.se] - pref[j.fi - 1];
    if(correct.size() <= k){
        cout << ans;
        exit(0);
    }
    for(int i = 1 ; i < correct.size() ; i++){
        dis.pb(pref[correct[i].fi - 1] - pref[correct[i - 1].se]);
    }
    sort(all(dis));
    for(int i = 0 ; i <= correct.size() - k - 1 ; i++){
        ans += dis[i];
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
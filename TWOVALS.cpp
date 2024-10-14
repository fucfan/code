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
#define file "TWOVALS"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int LOG = 20;

int n , a[N] , cnt[N];
vector <int> compress;

void inp(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        compress.pb(a[i]);
    }
    sort(all(compress));
    compress.erase(unique(all(compress)) , compress.end());

    for(int i = 1 ; i <= n ; i++) a[i] = lower_bound(all(compress) , a[i]) - compress.begin() + 1;
}

void solve(){
    int cnt_dif = 0;
    int ans = 0;

    queue <int> q;

    for(int i = 1 ; i <= n ; i++){
        if(!cnt[a[i]]){
            cnt_dif++;
        }
        cnt[a[i]]++;
        q.push(a[i]);
        while(cnt_dif > 2){
            cnt[q.front()]--;
            if(!cnt[q.front()]) cnt_dif--;
            q.pop();
        }
        int sz = q.size();

        ans = max(ans , sz);
    }

    cout << ans;
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
    inp();
    solve();
}

/*      UMU      */
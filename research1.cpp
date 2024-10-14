#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair <ll , ll>
#define all(c) (c).begin() , (c).end()

const int N = 2e5 + 5;
const ll oo = 1e18 + 7;

using namespace std;

int n , h[N] , k , same_pos[N];
vector <pii> del;

ll cal(int l , int r , int val){
    if(l > r) return 0;
    ll res = 0;
    ll Min = oo;
    vector <int> div;
    for(int i = l ; i <= r ; i++){
        if(h[i] - val < Min){
            Min = h[i] - val;
            div.clear();
            div.pb(i);
        }
        else if(h[i] == Min) div.pb(i);
    }
    int last = l;
    for(int i = 0 ; i < div.size() ; i++){
        res += cal(last , div[i] - 1 , Min + val);
        last = div[i] + 1;
    }
    res += cal(last , r , Min + val);
    res += Min;
//    cout << l << ' ' << r << ' ' << Min << ' ' << val << ' ' << res << '\n';
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("research.inp" , "r", stdin);
    freopen("research.out" , "w", stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> h[i];
        same_pos[i] = i;
    }
    for(int j = 1 ; j <= k ; j++){
        for(int i = j ; i <= n ; i++){
            if(h[i] > h[i - 1])
        }
    }
    cout << cal(1 , n , 0);
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair <int , int>

const int N = 2e5 + 5;
using namespace std;

int n;
pii d[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    while(test_case--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> d[i].fi >> d[i].se;
        }
        sort(d + 1 , d + 1 + n);
        int last = 0 , dur = 1000;
        for(int i = 1 ; i <= n ; i++){
            if(d[i].fi - last > dur) break;
            if(dur - d[i].fi + last > (d[i].se - 1) / 2){
                last = d[i].fi;
                dur = (d[i].se - 1) / 2;
            }
        }
        cout << last + dur << '\n';
    }
}

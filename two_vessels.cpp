#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    while(test_case--){
        float a , b , c;
        cin >> a >> b >> c;
        float mid = (a + b) / 2;
        int ans = ceil((max(a , b) - mid) / c);
        cout << ans << '\n';
    }
}

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

string x , y;
vector <int> pos[30];

int main(){
    cin >> x >> y;
    for(int i = 0 ; i < x.size() ; i++){
        pos[x[i] - 'a'].pb(i);
    }
    int ans = 1;
    int st_pos = -1;
    for(int i = 0 ; i < y.size() ; i++){
        int c = y[i] - 'a';
        if(pos[c].empty()){
            cout << -1;
            exit(0);
        }
        auto it = upper_bound(pos[c].begin() , pos[c].end() , st_pos);
        if(it == pos[c].end()){
            ans++;
            st_pos = pos[c][0];
        }
        else st_pos = *it;
    }
    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;

int n;pair <int , int> a[101];     

bool cmp(pair <int , int> a,pair <int , int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}
int main(){
    freopen("XEPTIEN.inp","r",stdin);
    freopen("XEPTIEN.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1,a + n + 1, cmp);
    for(int i = 1;i <= n;i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
}
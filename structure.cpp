#include <bits/stdc++.h>
using namespace std;
pair <int, int> a[100];int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) cout << a[i].first << " " << a[i].second << '\n';
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
struct path{
    int w , u , v;
};
bool cmp(path a , path b){
    return a.w < b.w;
}
int n , s[N] , par[N] , sz[N] , place[N];
vector <path> mst;
path way[N];
ll ans , cost[N];
void make_set(){
    for(int i = 1 ; i <= n ; i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int get(int a){
    if(a == par[a]) return a;
    else return get(par[a]);
}
void unite(int a , int b){
    a = get(a);
    b = get(b);
    if(sz[a] > sz[b]){
        par[b] = a;
        sz[a] += sz[b];
    }
    else{
        par[a] = b;
        sz[b] += sz[a];
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> s[i];
    }
    int d = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int c;
            cin >> c;
            if(c != 0){
                way[d].u = i;
                way[d].v = j;
                way[d].w = c;
                d++;
            }
        }
    }
    make_set();
    sort(way + 1 , way + d , cmp);
    for(int i = 1 ; i <= d ; i++){
        cout << way[i].w << '\n';
    }
    for(int i = 1 ; i <= d ; i++){
        if(get(way[i].u) != get(way[i].v)){
            unite(way[i].u , way[i].v);
            ans += way[i].w;
            cost[way[i].u] += way[i].w;
            cost[way[i].v] += way[i].w;
            mst.push_back(way[i]);
        }
    }
    for(auto i : mst){
        if(i.w > s[i.u] && )
    }
    cout << ans;
}

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
const int N = 6e5 + 5;
int p , q[N] , x[N] , y[N] , MAX , par[N];
void make_set(int v){
    par[v] = v;
}
int find_set(int v){
    if(par[v] == v) return v;
    if(par[v] != v) return find_set(par[v]);
}
void union_set(int a , int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b) par[b] = a;
}
void inp()
{
    cin >> p;
    for(int i = 1 ; i <= p ; i++){
        cin >> x[i] >> y[i] >> q[i];
        MAX = max(MAX , x[i]);
        MAX = max(MAX , y[i]);
    }
}

void solve()
{
    for(int i = 1 ; i <= MAX ; i++){
        make_set(i);
    }
    for(int i = 1 ; i <= p ; i++){
        if(q[i] == 1) union_set(x[i] , y[i]);
        else if(q[i] == 2){
            if(find_set(x[i]) == find_set(y[i])) cout << "1 \n";
            else cout << "0 \n";
        }
    }
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
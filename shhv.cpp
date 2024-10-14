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
ll n , a[N] , d;   
ll pos , f[N];
bool use[N];
ll gt(int k){
    if(f[k] != 0) return f[k];
    ll sum = 1;
    for(int i = 2 ; i <= k ; i++){
        sum = sum * i;
    }
    f[k] = sum;
    return sum;
}
int notuse(int k){
    int s;
    s = 0;
    for(int i = 1 ; i < k ; i++){
        if(!use[i]) s++;
    }
    return s;
}
void inp()
{
    cin >> n;
    d = 2;
    while(cin >> a[d]){
        d++;
    }
    d--;
    swap(n , a[d]);
    swap(a[d] , a[1]);
    d--;
}

void task2(int lengthN , ll position){
    // cout << lengthN << ' ' << position << '\n';
    if(lengthN == -1) return;
    for(int i = 1 ; i <= d ; i++){
        ll p = gt(lengthN - 1);
        if(!use[i] && position > p){
            position -= p;
        }
        else if(!use[i]){
            cout << i << ' ';
            use[i] = true;
            task2(lengthN - 1 , position);
            break;
        }
    }
}

void solve()
{
    for(int i = 1 ; i <= d ; i++){
        pos = pos + gt(d - i) * notuse(a[i]);
        use[a[i]] = true;
    }
    cout << pos + 1 << '\n';
    ll g = gt(d);
    mem(use , 0);
    task2(d , n);
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
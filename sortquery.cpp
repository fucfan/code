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
int q , a[N] , front , rear , pre , stop;
pii qu[N];
void inp()
{
    cin >> q;
    front = rear = 1;
    for(int i = 1 ; i <= q ; i++){
        cin >> qu[i].fi;
        if(qu[i].fi == 1){
            cin >> qu[i].se;
        }
    }
}

void solve()
{
    stop = 1;
    for(int i = 1 ; i <= q ; i++){
        int pos = i;
        bool check = false;
        if(qu[i].fi == 2){
            for(int j = i - 1 ; j >= stop ; j--){
                if(qu[j].fi == 3){
                    pos = j;
                }
            }
            for(int k = stop ; k <= pos - 1 ; k++){
                if(qu[k].fi == 1){
                    a[rear] = qu[k].se;
                    rear++;
                    check = true;
                }
            }
            if(pos != i && check) sort(a + front , a + rear);
            for(int j = pos + 1 ; j <= i - 1 ; j++){
                if(qu[j].fi == 1){
                    a[rear] = qu[j].se;
                    rear++;
                }
            }
            stop = i + 1;
            cout << a[front] << '\n';
            front++;
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
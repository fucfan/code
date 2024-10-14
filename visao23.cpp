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
int n , cnt[N];
void inp()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        string s;
        int a;
        cin >> s >> a;
        cnt[s.size()] += a;
    }
}

void solve()
{
    int sum1 = 0;
    int sum2 = 0;
    int num = 0;
    for(int i = 1 ; i <= 2023 ; i += 2){
        // cout << cnt[i] << '\n';
        if(cnt[i] == 0){
            sum2 = max(sum2 , sum1 + num);
            sum1 = 0;
            num = 0;
        }
        else{
            sum1 += cnt[i];
            num++;
        }
    }
    sum1 = 0;
    num = 0;
    for(int i = 2 ; i <= 2023 ; i += 2){
        if(cnt[i] == 0){
            sum2 = max(sum2 , sum1 + num);
            sum1 = 0;
            num = 0;
        }
        else{
            sum1 += cnt[i];
            num++;
        }
    }
    cout << sum2 + 1;
}

void run_with_file()
{
   if(fopen(file".inp","r")){
    //    freopen(file".inp","r", stdin);
    //    freopen(file".out", "w", stdout);
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
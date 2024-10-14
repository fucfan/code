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
ll n , k , sz , ans , dp[35][35][2][2];
bool b[35];
ll sol(int i , int cnt , bool check , bool check1){
    if(i == sz){
        if(cnt == k){
            if(!cnt && !check1) return 0;
            return 1;
        }
        else if(k == 1 && !check1) return 1;
        return 0;
    }
    if(dp[i][cnt][check][check1] != -1) return dp[i][cnt][check][check1];
    if(cnt > k) return 0;
    ll res = 0;
    if(check){
        for(int j = 0 ; j <= 1 ; j++){
            if(j == 0){
                res = res + sol(i + 1 , cnt + check1 , check , check1);
            }
            if(j == 1){
                res = res + sol(i + 1 , cnt , check , 1);
            }
        }
    }
    else{
        for(int j = 0 ; j <= b[i] ; j++){
            if(j == 0){
                if(j < b[i]){
                    res = res + sol(i + 1 , cnt + check1 , 1 , check1);
                }
                else{
                    res = res + sol( i + 1 , cnt + check1 , check , check1 );
                }
            }
            if(j == 1){
                res = res + sol(i + 1 , cnt , check , 1);
            }
        }
    }
    dp[i][cnt][check][check1] = res;
    return res;
}
void inp()
{
    while(cin >> n >> k){
        stack <int> binary;
        mem(dp , -1);
        while(n != 0){
            binary.push(n % 2);
            n = n / 2;
        }
        sz = 1;
        mem(b , 0);
        while(!binary.empty()){
            b[sz] = binary.top();
            binary.pop();
            sz++;
        }
        cout << sol(1 , 0 , 0 , 0) << '\n';
    }
}

void solve()
{

}

void run_with_file()
{
   //if(fopen(file".inp","r")){
   //    freopen(file".inp","r", stdin);
   //    freopen(file".out", "w", stdout);
   //}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run_with_file();
    inp();
    solve();
}

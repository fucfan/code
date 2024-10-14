#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define getBit(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "P:\\cpp\\phuc"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 100 + 5;
int r , c;
char table[N][N];

void inp()
{
    cin >> r >> c;
    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            cin >> table[i][j];
        }
    }
}

void solve()
{
    
    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c - 2 ; j++){
            if(table[i][j] == '.' && table[i][j + 1] == '.' && table[i][j + 2] == '.'){
                cout << i << ' ' << j;
                exit(0);
            }
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
    cin.tie(0)->sync_with_stdio(false);
    // run_with_file();
    inp();
    solve();
}

/*      UwU      */
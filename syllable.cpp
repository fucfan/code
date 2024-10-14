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
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "syllable"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

string s;
int ans;

void inp(){
    cin >> s;
    for(int j = s.size() - 1 ; j >= 0 ; j--){
        if(s[j] == 'a' || s[j] == 'e' || s[j] == 'u' || s[j] == 'o' || s[j] == 'i'){
            ans++;
        }
        if(s.size() - 3 >= j){
            if(s[j] == 'i' && s[j + 1] == 'o' && s[j + 2] == 'u') ans--;
        }

        if(s.size() - 2 >= j){
            if(s[j] == 'a' && s[j + 1] == 'u') ans--;
            if(s[j] == 'o' && s[j + 1] == 'a') ans--;
            if(s[j] == 'o' && s[j + 1] == 'o') ans--;
        }
    }
}   

void solve(){
    if(s.size() > 2){
        if(s[s.size() - 1] == 'e' && s[s.size() - 2] == 'l' && 
        s[s.size() - 3] != 'a' && s[s.size() - 3] != 'e' && s[s.size() - 3] != 'u' && s[s.size() - 3] != 'o' && s[s.size() - 3] != 'i') ans++;
    }
    if(s.back() == 'e') ans--;

    cout << max(ans , 1);
}

void run_with_file(){
   if(fopen(file".inp","r")){
       freopen(file".inp","r", stdin);
       freopen(file".out", "w", stdout);
   }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    run_with_file();
    inp();
    solve();
}

/*      UMU      */
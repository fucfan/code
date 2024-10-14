#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define BIT(a , b) ((a) & (1 << (b)))
#define turnOn(a , b) ((a) | (1 << (b)))
#define turnOff(a , b) ((a) ^ (1 << (b)))
#define pii pair<int, int>
#define pb push_back
#define nl cout << "\n";
#define __ <<" "<<
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "tbrackets"
using namespace std;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

string s;
int n;
stack <char> st;
ll ans;

void inp(){
    cin >> s;
    n = s.size();
    s = " " + s;
}

void solve(){
    for(int i = 1 ; i < n ; i++){
        for(int j = i ; j <= n ; j++){
            bool check = 1;

            for(int k = i ; k <= j ; k++){
                if(s[k] == ')' || s[k] == ']' || s[k] == '}' || s[k] == '>'){
                    if(st.empty()){
                        check = 0;
                        continue;
                    }
                    if(s[k] == ')' && st.top() != '(') check = 0;
                    if(s[k] == ']' && st.top() != '[') check = 0;
                    if(s[k] == '}' && st.top() != '{') check = 0;
                    if(s[k] == '>' && st.top() != '<') check = 0;

                    if(!check) break;

                    st.pop();
                }
                else st.push(s[k]);
            }

            if(st.size()) check = 0;

            while(st.size()) st.pop();

            ans += check;
        }
    }

    cout << ans;
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
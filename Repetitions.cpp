#include <bits/stdc++.h>
using namespace std;

string s;long t,f;
int main(){
    long i = 0;
    f = 1;
    cin >> s;
    while(i < s.length()){
        if(s[i] == s[i + 1]) f++;
        else f = 1;
        t = max(t,f);
        i++;
    }
    cout << t;
}
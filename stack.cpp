#include <bits/stdc++.h>
using namespace std;
int top,a[10000],n;
bool emt(){
    if(top != 0) return true;
    else return false;
}
void push(int x){
    top++;
    a[top] = x;
}
int main(){
    freopen("stack.inp","r",stdin);
    freopen("stack.out","w",stdout);
    cin >> n;
    while(n != 0){
        push(n % 2);
        n = n / 2;
    }
    while(emt() != false){
        cout << a[top];
        top--;
    }
}
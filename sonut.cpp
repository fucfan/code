#include<bits/stdc++.h>
using namespace std;
long N;
int sum(int k){
    int s = 0;
    while(k > 0){
        s = s + k % 10;
        k = k / 10;
    }
    return s;
}
int main()
{
    cin >> N ;
    while(N >= 10) N = sum(N);
    cout << N;
}
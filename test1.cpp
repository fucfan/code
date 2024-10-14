#include <bits/stdc++.h>

using namespace std;
int n,m,t;
long long s;
int main()
{
    cin>>m>>n>>t;
    while(n>=m)
    {
        s=s+(n/m);
        n=n%m+(n/m);
    }
    cout<<s*t;
}
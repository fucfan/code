#include <bits/stdc++.h>
using namespace std;
long long n;int m,d;
int main(){
	freopen("searchk.inp","r",stdin);
	freopen("searchk.out","w",stdout);
	cin>>n>>m;d=0;
	while(n!=0){
		n=n/m;
		d=d+n;
	}
	cout<<d;
}
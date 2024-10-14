#include <bits/stdc++.h>
using namespace std;
long n,x[1000001],y[1000001],a,b,c,d;
int main(){
	freopen("rect.inp","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cin>>y[i];
	}
	a=x[1];b=y[1];c=x[1];d=y[1];
	for(int i=1;i<=n;i++){
		a=min(a,x[i]);
		b=min(b,y[i]);
		c=max(c,x[i]);
		d=max(d,y[i]);
	}
	cout<<a<<" "<<b<<endl;
	cout<<c<<" "<<d<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
//	freopen("TANGLE1.inp","r",stdin);
//	freopen("TANGLE1.out","w",stdout);
	cin>>a>>b>>c;
	if(a>=b+c||b>=a+c||c>=b+a||a<=0||b<=0||c<=0){
		cout<<"0";
	}
	else{
		float p=a+b+c;float f=p/2;
		float g=f*(f-a)*(f-b)*(f-c);
		cout<<setprecision(2)<<fixed<<p<<endl;
		cout<<setprecision(2)<<fixed<<sqrt(g);
	}
}
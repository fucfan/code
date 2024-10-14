#include <bits/stdc++.h>
using namespace std;
long a,b,c;
int main(){
	freopen("TANGLE2.inp","r",stdin);
	freopen("TANGLE2.out","w",stdout);
	cin>>a>>b>>c;
	if(a>b+c||b>a+c||c>a+b||a<=0||b<=0||c<=0){
		cout<<"0";
	} 	
	else{
		if(a*a>b*b+c*c||b*b>a*a+c*c||c*c>a*a+b*b){
			cout<<"3";
		}
		if(a*a<b*b+c*c||b*b<a*a+c*c||c*c<a*a+b*b){
			cout<<"2";
		}
		if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b){
			cout<<"1";
		}
	}
}
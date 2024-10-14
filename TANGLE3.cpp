#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a>b+c||b>a+c||c>a+b){
		cout<<"0";
	} 	
	else{
		if(a==b&&b==c){
			cout<<"3";
			return 0;
		}
		if(a==b||b==c||c==a){
			cout<<"2";
			return 0;
		}
		if(a!=b&&b!=c&&a!=c){
			cout<<"1";
		}
	}
}
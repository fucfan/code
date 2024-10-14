#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	cin>>a>>b;
	while(a!=0&&b!=0){
		if(a<b) b=b%a;
		else a=a%b;
	}
	cout<<max(a,b);
}
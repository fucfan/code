#include <bits/stdc++.h>
using namespace std;
long xa,xb,ya,yb,xc,yc;double a,b,c;
double ch(long x1,long y1,long x2,long y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	a=ch(xa,ya,xb,yb);
	b=ch(xa,ya,xc,yc);
	c=ch(xc,yc,xb,yb);
	double p=(a+b+c)/2;
	cout<<setprecision(2)<<fixed<<a+b+c<<endl;
	cout<<sqrt(p*(p-a)*(p-b)*(p-c));
}
#include <bits/stdc++.h>
using namespace std;
double a,b;long long s,i,c,d;
int main(){
	cin >> a >> b;
	if(a > round(a)) a = round(a) + 1;
	if(round(a) > a) a = round(a);
	if(b > round(b)) b = round(b);
	if(round(b) > b) b = round(b) - 1;
	c = a;d = b;
//	for(long long i = a;i <= b;i++){
//		s = s + i;
//	}
//	(a + b)*((b - a) + 1)/2;
	s = (d + c)*((d - c) + 1) / 2;
	cout << s;
}
#include <bits/stdc++.h>
using namespace std;
long long a,b,n;
int main(){
	cin >> n;
	a = 1;b = 1;
	for(long long i = 3;i <= n;i++){
		if(a >= b) b = b + a;
		else a = a + b;
	}
	cout << max(a,b);
}
#include <bits/stdc++.h>
using namespace std;
long m,a[31];bool k;
void solve(long m){
	while(m > 1){
		k = false;
		for(int i = 9; i >= 2;i--){
			if(m % i == 0){
				a[i]++;
				k = true;
				m = m / i;
				break;
			}
		}
		if(k == false){
			cout << -1;
			exit(0);
		}
	}
	for(int i = 2; i <= 9;i++){
		if(a[i] != 0){
			for(int j = 1;j <= a[i];j++)
			cout << i;
		}
	}
}
int main(){
	cin >> m;
	if(m == 0) {
		cout << 10;
		exit(0);
	}
	if(m < 10){
		cout << m;
		exit(0);
	}
	solve(m);
}
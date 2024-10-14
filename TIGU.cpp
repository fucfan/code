#include <bits/stdc++.h>
using namespace std;
long m,i;double n;
int main(){
	cin >> n >> m;
	i = 0;
	while(n < m){
		n = n + round(n*10/100);
		i++;
	}
	cout << i;
}
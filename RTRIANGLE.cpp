#include <bits/stdc++.h>
using namespace std;
long long n,s,i;
int main(){
	cin >> n;
	s = 0;i = 1;
	while(s < n){
		s = s + i;
		i++;
	}
	if(s == n) cout << "YES";
	else cout << "NO";
}
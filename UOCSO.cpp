#include <bits/stdc++.h>
using namespace std;
long a,b,m,Cmin,Count;
int uocso(long k){
	int s = 0;
	for(long i = 1;i <= sqrt(k);i++){
		if(k % i == 0){
			if(i * i == k){
				s++;
			}
			else s = s + 2;
		}
	}
	return s;
}
int main(){
	freopen("UOCSO.INP","r",stdin);
	freopen("UOCSO.OUT","w",stdout);
	cin >> a >> b;
//	a = rand() % 30 + 2;
//	b = a + 4;
//	cout << a << " " << b << endl;
	m = 0;Cmin = 0;Count = 0;
	for(long i = a;i <= b;i++){
		if(uocso(i) > Cmin){
			Cmin = uocso(i);
			m = i;
		}
	}
	for(long i = a;i <= b;i++){
		if(uocso(i) == Cmin) Count++;
	}
	cout << m << " " << Cmin << " " << Count;
}
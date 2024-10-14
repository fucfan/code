#include<bits/stdc++.h>
using namespace std;
long L,R,n,chot,a[1001];
void sort(long i,long j,long mid){
 	if(i<j){
 		R=j;L=i;
 		chot=a[mid];
		while(R<=L){
			if(a[R]<chot){
				R++;
			}
			else{
				if(a[R]>=chot&&a[L]<=chot){
					swap(a[R],a[L]);
					if(a[R]==chot) mid=R;
					if(a[L]==a[L]){
						L--;
					}	
				}
				else L--;
			}
		}
		if(L<j) sort(L,j,(L+j)/2);
		R=j;
		if(i<R) sort(i,R,(R+i)/2);
	}
}
int main(){
	cin>>n;
	L=1;R=n;
	for(long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(L,R,(L+R)/2);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}
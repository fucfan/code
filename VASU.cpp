#include<bits/stdc++.h>
using namespace std;
int L,R,n,chot,g,d,a[10001];
void sort(int i,int j,int chot){
 	if(i<j){
 		R=j;L=i;
		while(i<=j){
			if(a[i]<chot){
				i++;
			}
			else{
				if(a[i]>=chot&&a[j]<=chot){
					swap(a[i],a[j]);
					if(a[i]==chot) g=i;
					if(a[i]==a[j]){
						j--;
					}	
				}
				else j--;
			}
		}
		if(L<g-1) sort(L,g-1,a[(L+g-1)/2]);
		R=n;
		if(g+1<R) sort(g+1,R,a[(R+g+1)/2]);
	}
}
int main(){
	n=10000;d=0;
	L=1;R=n;
	for(int i=1;i<=n;i++){
		a[i]=rand()%100;
	}
	sort(L,R,a[(L+R)/2]);
//	for(int i=1;i<=n;i++){
//		if(a[i]-i+1>=0)d=d+a[i]-i+1;
//	}
//	cout<<d;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}
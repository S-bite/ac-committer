#include<bits/stdc++.h>
using namespace std;

bool isok(int n,int m){
  	return n*4>=m;
}

int main(){

  	int n,m;
    cin>>n>>m;
  	for (int i=0;i<=n;i++){
    	int l=0,r=n+1;
      	while (l+1!=r){
        	int med=(l+r)/2;
          	if (isok(n-med-i,m-2*i-3*med)){
            	l=med;
            }else{
            	r=med;
            }
        }
      	if (2*i+l*3+(n-i-l)*4==m){
        	cout<<i<<" "<<l<<" "<<n-i-l<<endl;
          	return 0;
        }
    }
  	cout<<"-1 -1 -1"<<endl;
  	return 0;
}

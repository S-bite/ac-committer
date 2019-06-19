#include<bits/stdc++.h>
using namespace std;
int main(){

  	int n,m;
    cin>>n>>m;
  	for (int i=0;i<=n;i++){
    	for (int j=0;i+j<=n;j++){
    		if (i*2+j*3+(n-i-j)*4==m){
            	cout<<i<<" "<<j<<" "<<(n-i-j)<<endl;
              	return 0;
            }
        }
    }
  	cout<<"-1 -1 -1"<<endl;
  	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
 	int n;
  	cin>>n;
	int ans=0;
  	int pow=1<<(n-1);
  	for (int i=0;i<n;i++){
    	int t;
      	cin>>t;
      	ans+=pow*t;
      	pow/=2;
    }
  	cout<<ans<<endl;
  	return 0;
}
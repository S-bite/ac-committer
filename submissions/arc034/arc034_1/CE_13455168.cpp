#include<bits/stdc++.h>
#define chmax(a,b) a=max(a,b)
using namespace std;
int main(){
	int n;
 	cin>>n;
  	long double ans=-1;
  	for(int i=0;i<n;i++){
    	long double cur=0;
      	long double t;
    	for (j=0;j<4;j++){
	    	cin>>t;
          	cur+=t;
        }
      	cin>>t;
      	cur+=t*110/990.0;
      	chmax(ans,cur);
    }
  	cout<<fixed<<setprecision(18)<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,k;
  cin>>a>>k;
  long long m=2000000000000ll;
  if (k==0){
  	cout<<m-a<<endl;
  }else{
  	long long ans=0;
    while (a<m){
      	cerr<<a<<endl;
    	a+=1+k*a;
      	ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,k,s,t;
  cin>>a>>b>>c>>k>>s>>t;
  int dc=0;
  if(s+t>=k) dc=c*(s+t);
  cout<<(a*s+b*t-dc)<<endl;
  return 0;
}

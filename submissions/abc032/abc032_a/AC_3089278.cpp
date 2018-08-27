#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,n;
	cin>>a>>b>>n;
	int ans=0;
  for (ans=n;ans%a!=0 or ans%b!=0;ans++);
  cout<<ans<<endl;
  return 0;
}

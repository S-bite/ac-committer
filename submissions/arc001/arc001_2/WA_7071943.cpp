#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
  cin>>a>>b;
  int c=abs(a-b);
  int ans=0;
  ans+=c/10;
  c%=10;
  ans+=c/5;
  c%=5;
  ans+=c;
  cout<<ans<<endl;
  return 0;
}
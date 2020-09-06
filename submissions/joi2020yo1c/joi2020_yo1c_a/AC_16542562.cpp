#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,l,r;
  cin>>x>>l>>r;
  int ans=l;
  for (int i=l;i<=r;i++){
    if (abs(x-ans)>abs(x-i)){
    	ans=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}

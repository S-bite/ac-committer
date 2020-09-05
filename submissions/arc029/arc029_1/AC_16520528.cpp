#include<bits/stdc++.h>
using namespace std;
int main(){

  int n;
  cin>>n;
  int a[n];
  int sum=0;
  for(int i=0;i<n;i++){
  	cin>>a[i];
    sum+=a[i];
  }
  int ans=1000000;
  for (int i=0;i<1<<n;i++){
    int x=0;
    for (int j=0;j<n;j++){
      if (((i>>j)&1)==1){
        x+=a[j];
      }
    }
    ans=min(ans,max(x,sum-x));
  }
  cout<<ans<<endl;
  return 0;
}

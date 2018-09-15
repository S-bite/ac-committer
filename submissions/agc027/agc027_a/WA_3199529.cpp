#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  int a[n];
  rep(i,n)cin>>a[i];
  sort(a,a+n);
  int ans=0;
  rep(i,n){
    if(x<a[i]) break;
    x-=a[i];
    ans++;}
    if (x!=0) ans--;
    ans=max(ans,0);
   cout<<ans<<endl;

  return 0;
}

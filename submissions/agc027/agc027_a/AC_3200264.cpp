#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  int a[n];
  rep(i,n)cin>>a[i];
  sort(a,a+n);
  int ans=0,f=2;
  rep(i,n){
  //  if(x<a[i]) break;
  //  tmp=i;
    x-=a[i];
    if (x==0) {f=0;break;}
    if (x<0) {f=1;break;}
    ans++;}
    if (f==0) ans++;
    if (f==2) ans--;

   cout<<ans<<endl;

  return 0;
}

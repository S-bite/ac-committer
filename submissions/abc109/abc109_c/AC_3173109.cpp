#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int gcd(int a,int b){
  if (b>a){
    b^=a;
    a^=b;
    b^=a;
  }
  while (b!=0){
    int c=a%b;
    a=b;
    b=c;
  }
  return a;
}
int main(){
  int n,x,ans=0;
  cin>>n>>x;
  rep(i,n){
    int t;
    cin>>t;
    ans=gcd(abs(t-x),ans);
  }
  cout<<ans<<endl;

  return 0;
}

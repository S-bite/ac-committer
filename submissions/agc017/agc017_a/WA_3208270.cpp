#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;


int main(){
  int n,f,even=0,odd=0;
  cin>>n>>f;
  rep(i,n){
    int t;
    cin>>t;
    if (t%2==0) even++;else odd++;
  }
  if (odd==0) {
    if (f==0) cout<<(1<<n)<<endl;
    else cout<<0<<endl;
  }else{
      cout<<(1ll<<(n-1))<<endl;
  }
  return 0;
}

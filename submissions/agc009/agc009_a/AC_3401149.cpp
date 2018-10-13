#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(long long i=0;i<(ll)(n);i++)
using namespace std;

int main(){
  int n;
  cin>>n;
  ll a[n],b[n];
  rep(i,n) cin>>a[i]>>b[i];
  ll ans=0;
  for(int i=n-1;i>=0;i--){
    if((ans+a[i])%b[i]==0) continue;
    ans+=b[i]-(ans+a[i])%b[i];
  }
  cout<<ans<<endl;
  return 0;
}

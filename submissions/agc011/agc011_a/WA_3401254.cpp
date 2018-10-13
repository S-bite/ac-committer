#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(long long i=0;i<(ll)(n);i++)
using namespace std;

int main(){
  int n,c,k;
  cin>>n>>c>>k;
  int t[n];
  rep(i,n)cin>>t[i];
  sort(t,t+n);
  int ans=1,s=t[0],p=1;
  for(int i=1;i<n;i++){
    if(p>c or t[i]-s>=k){
      ans++;
      s=t[i];
      p=1;
    }else p++;
  }
  cout<<ans<<endl;
  return 0;
}

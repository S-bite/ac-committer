#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
using namespace std;
int main(){
  int n,ans=0;
  cin>>n;
  int s[n];
  rep(i,n)cin>>s[i];
  rep(i,n){
    int t;
    cin>>t;
    ans=max(ans,s[i]*t);
  }
  cout<<ans<<endl;
  return 0;
}

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
  int k,s,ans=0;
  cin>>k>>s;
  rep(i,k+1)rep(j,k+1)if ( s-i-j>=0 and s-i-j<=k) ans++;
  cout<<ans<<endl;

  return 0;
}

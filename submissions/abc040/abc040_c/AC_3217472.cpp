#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n],dp[n];
  dp[0]=0;
  rep(i,n) cin>>a[i];
  dp[1]=abs(a[0]-a[1]);
  for(int i=2;i<n;i++){
    dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
  }
  cout<<dp[n-1]<<endl;
  return 0;
}

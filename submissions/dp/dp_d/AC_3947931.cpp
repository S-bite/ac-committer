#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
int N,W;
cin>>N>>W;
ll dp[N+1][W+1]={};
for(int i=0;i<N;i++){
    int w,v;
    cin>>w>>v;
    for(int j=W-w;j>=0;j--){
        dp[i+1][j+w]=max(dp[i][j+w],dp[i][j]+v);
    }
    for(int j=w-1;j>=0;j--){
        dp[i+1][j]=dp[i][j];
    }
 
   }
   
ll ans=-1;

for(int i=0;i<=W;i++){
    ans=max(ans,dp[N][i]);
}
cout<<ans<<endl;
return 0;
}
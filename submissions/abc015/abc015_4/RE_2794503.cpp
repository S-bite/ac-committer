#include<bits/stdc++.h>
using namespace std;
int main(){
    int W,N,K;
    cin>>W>>N>>K;
    int A[N],B[N];
    for (int i=0;i<N;i++) cin>>A[i]>>B[i];
    vector< vector< vector<int> > > dp(N+1,vector<vector<int> >(W+1,vector<int>(K+1,0)));
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            for(int k=0;k<=K;k++){
                if (A[i]+j>W)continue;
                dp[i+1][j+A[i]][k+1]=max(dp[i][j][k]+B[i],dp[i+1][j+A[i]][k+1]);
                dp[i+1][j][k]=max(dp[i][j][k],dp[i+1][j][k]);

              //  if(dp[i][j][k]+B[i]>dp[i+1][j+A[i]][k+1]){
              //    cout<<i<<","<<j<<","<<k<<","<<dp[i][j][k]<<","<<A[i]<<","<<B[i]<<endl;
                //}
            }
        }}

    int ans=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<W+1;j++){
            for(int k=0;k<K+1;k++){
              ans=max(ans,dp[i][j][k]);
            //  cout<<i<<","<<j<<","<<k<<","<<dp[i][j][k]<<endl;
            }
        }
    }
    cout<<ans<<endl;
  }

  /*

  10
  5 4
  9 10
  3 7
  3 1
  2 6
  4 5
  */

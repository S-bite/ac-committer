#include<bits/stdc++.h>
using namespace std;
int main(){
    int W,N,K;
    cin>>W>>N>>K;
    int A[N],B[N];
    for (int i=0;i<N;i++) cin>>A[i]>>B[i];
    int dp[N+1][W+1][K+1]={};
    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;j++){
            for(int k=1;k<=K;k++){
                if ((j-A[i-1])<0){
                  dp[i][j][k]=dp[i-1][j][k];
                }
                else{
                  dp[i][j][k]=max(dp[i-1][j-A[i-1]][k-1]+B[i-1],dp[i-1][j][k]);
                }
              }
            }
          }

    cout<<dp[N][W][K]<<endl;
  }

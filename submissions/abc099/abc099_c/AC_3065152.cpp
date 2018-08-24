#include<bits/stdc++.h>
using namespace std;
#define INF 1<<20+1

int main(){
  int N;
  cin>>N;
  int dp[N+1]={};
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  dp[3]=3;
  dp[4]=4;
  dp[5]=5;

  if (N<=5){cout<<dp[N]<<endl;return 0;}
  int c=6;
  while (c!=N+1){
    dp[c]=INF;
    int i=1;
    while(round(pow(6,i))<=c){
      dp[c]=min(dp[c],dp[c-(int)round(pow(6,i))]+1);
      i++;
    }
    i=1;
    while(round(pow(9,i))<=c){
      dp[c]=min(dp[c],dp[c-(int)round(pow(9,i))]+1);//dp[i]+dp[c-i]);
      i++;//min(max(i-i%9,i-i%6),i-1);
    }

    c++;
  }
  cout<<dp[N]<<endl;
  return 0;
}

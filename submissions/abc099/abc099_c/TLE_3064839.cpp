#include<bits/stdc++.h>
using namespace std;
#define INF 1<<20+1;
int f(int n){
  int base=(n%2==0)?6:9;
  int ret=-1;
  int c=1;
  //cout<<n<<endl;
  while (round(pow(base,c))<=n){
    //  cout<<round(pow(base,c))<<endl;
     if(round(pow(base,c))==n){ret=1;break;}
     c++;
   }
   //cout<<"ret:"<<ret<<endl;
   return ret;
  }
int main(){
  int N;
  cin>>N;
  int dp[N+1]={};
  dp[1]=1;
  dp[2]=2;
  if (N<=2){cout<<N<<endl;return 0;}
  int c=3;
  while (c!=N+1){
    if (f(c)!=-1){dp[c]=1;c++;continue;}
    int i=1;
    //int j=c-i;
    dp[c]=INF;
    while(i<=c/2){
      dp[c]=min(dp[c],dp[i]+dp[c-i]);
      i++;
      //j--;
    }
    c++;
  }
  cout<<dp[N]<<endl;
  return 0;
}

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
int n;
cin>>n;
ll dp[n+1][3]={};
rep(i,n){
    int a,b,c;
    cin>>a>>b>>c;
    dp[i+1][0]=max(dp[i][1]+a,dp[i][2]+a );
    dp[i+1][1]=max(dp[i][0]+b,dp[i][2]+b );
    dp[i+1][2]=max(dp[i][1]+c,dp[i][2]+c );



   }
cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
return 0;

}
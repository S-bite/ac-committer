#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
int n,k;
cin>>n>>k;
int h[n];
rep(i,n) cin>>h[i];

int dp[n];
dp[0]=0;
for(int i=1;i<n;i++){
    dp[i]=1<<15;
    for(int j=i-1;j>=max(i-k,0);j--)dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]));
}
cout<<dp[n-1]<<endl;
return 0;

}
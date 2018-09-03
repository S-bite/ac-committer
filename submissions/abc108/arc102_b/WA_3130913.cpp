#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  long long l;
  cin>>l;
  int n=floor(log2(l));
  //long long dp[n]={};
  string ans="";
  int m=0;
  rep(i,n){
        ans+=to_string(i+1)+" "+to_string(i+2)+" 0"+"\n";
        m++;
        ans+=to_string(i+1)+" "+to_string(i+2)+" "+to_string(1<<(n-i-1))+"\n";
        m++;
  }

  long long cmax=(1<<n);
  l-=cmax;
  int cn;
  while (l>=1){
  cn=n-floor(log2(l))+1;
  ans+="1 "+to_string(cn)+" "+to_string(cmax)+"\n";
  m++;
  cmax+=(1<<cn);
  l-=(1<<cn);

}
  cout<<n+1<<" "<<m<<endl<<ans;
  return 0;
}

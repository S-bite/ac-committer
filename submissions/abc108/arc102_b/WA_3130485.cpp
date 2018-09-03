#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  long long l;

  cin>>l;
  int n=ceil(log2(l+1));
  //long long dp[n]={};
  string ans="";
  int m=0;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      if (i==0){
        ans+=to_string(i+1)+" "+to_string(j+1)+" 0"+"\n";
        m++;
    }
        ans+=to_string(i+1)+" "+to_string(j+1)+" "+to_string(1<<(n-i-2))+"\n";
        m++;
    }
  }

  int t=n;
  l-=(1<<(t-1))-1;
  while (l>1){
  //  cout<<l<<endl;
  ans+="1 "+to_string((int)ceil(log2(l))+1)+" "+to_string((1<<(t-1))-1)+"\n";
  m++;
  l-=1<<t;
  t=ceil(log2(l));

  }
  cout<<n<<" "<<m<<endl<<ans;
  return 0;
}

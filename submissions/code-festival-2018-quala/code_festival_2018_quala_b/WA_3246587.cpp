#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;


int main(){
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  int l[m],r[m];
  bool chk[n]={};
  rep(i,m){
    cin>>l[i]>>r[i];
  }

  rep(i,m){
    for(int j=l[i];j<=r[i];j++)
    {
chk[j-1]=true;
    //  cout<<j<<endl;
    }
  }
  int ans=0;
  rep(i,n) {
    cout<<chk[i]<<endl;
    if (chk[i]) ans+=a;else ans+=b;
  }
  cout<<ans<<endl;

  return 0;
}

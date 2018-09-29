#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for (ll i=0;i<(ll)(n);i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  int x[n],y[n];
  rep(i,n)cin>>x[i]>>y[i];
  rep(i,n-1){
    if(abs(x[i]+y[i])%2!=abs(x[i+1]+y[i+1])%2){
      cout<<"-1"<<endl;
      return 0;
    }
  }
  if ((x[0]+y[0])%2==0){
    cout<<20<<endl;
    rep(i,20)cout<<1<<((i!=19)?" ":"")<<endl;
    rep(i,n){
      string s="";
      rep(k,abs(x[i]))s+=(x[i]<0)?"L":"R";
      rep(k,abs(y[i]))s+=(y[i]<0)?"D":"U";
      rep(k,(20-abs(x[i])-abs(y[i]))/2)s+="UD";
      cout<<s<<endl;
    }
  }else{
    cout<<21<<endl;
    rep(i,21)cout<<1<<((i!=20)?" ":"")<<endl;
    rep(i,n){
      string s="";
      rep(k,abs(x[i]))s+=(x[i]<0)?"L":"R";
      rep(k,abs(y[i]))s+=(y[i]<0)?"D":"U";
      rep(k,(21-abs(x[i])-abs(y[i]))/2)s+="RL";
      cout<<s<<endl;
    }
  }
  return 0;
}

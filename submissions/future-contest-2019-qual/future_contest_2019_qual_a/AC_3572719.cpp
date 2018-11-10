#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int n,m,l;
  cin>>n>>m>>l;
  string s;
  rep(i,n)cin>>s;
  rep(i,m){
    string s="";
    rep(j,m){
      if (i==0 or i==m-1 or j==0 or j==m-1) s+="#";
      else s+="T";
    }
    cout<<s<<endl;
  }
  return 0;
}

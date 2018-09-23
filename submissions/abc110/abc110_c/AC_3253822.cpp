#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
string rp(string s,char t,char r){
  string ret="";
  rep(i,s.size()){
    if(s[i]==t) ret+=r;
    else ret+=s[i];
  }
  return ret;
}

int main(){
  string base="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string s,t;
  cin>>s>>t;
  int cnt=0;
  rep(i,s.size()){
    if ((int)s[i]-'a'>=0) {
      s=rp(s,s[i],base[cnt]);
      cnt++;
    }
  }
  cnt=0;
  rep(i,t.size()){
    if ((int)t[i]-'a'>=0) {
      t=rp(t,t[i],base[cnt]);
      cnt++;
    }
  }
  if(s==t) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}

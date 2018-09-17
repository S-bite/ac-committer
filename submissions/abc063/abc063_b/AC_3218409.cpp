#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  bool chk[26];
  rep(i,26) chk[i]=false;
  string s;
  cin>>s;
  rep(i,s.size()){
    if(chk[(int)s[i]-'a']) {cout<<"no"<<endl; return 0;}
    else chk[(int)s[i]-'a'] =true;
  }
  cout<<"yes"<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int w;
  cin>>w;
  string ans="";
  for(int i=0;i*w<s.size();i++){
    ans+=s[i*w];
  }
  cout <<ans<<endl;
}

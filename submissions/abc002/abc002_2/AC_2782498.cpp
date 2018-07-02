#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  string ans="";
  for (int i=0;i<s.size();i++){
    if(s[i]!='a' and s[i]!='i' and s[i]!='u' and s[i]!='e' and s[i]!='o') ans+=s[i];
  }
  cout<<ans<<endl;
}

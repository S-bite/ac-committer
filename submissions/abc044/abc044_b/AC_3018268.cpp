#include<bits/stdc++.h>
using namespace std;
int main(){
  int b[27]={};
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    b[(int)s[i]-'a']++;//=!b[(int)s[i]-'a'];
  }
  string ans="Yes";
  for(int i=0;i<27;i++){
    if(b[i]%2==1) ans="No";
  }
  cout<<ans<<endl;
  return 0;
}

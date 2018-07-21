#include <bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  int c[26]={};
  if(a.size()!=b.size()){cout<<"No"<<endl;return 0;}
  for(int i=0;i<a.size();i++){
    c[(int)a[i]-'a']++;
    c[(int)b[i]-'a']--;
  }
  for(int i=0;i<26;i++){
    if(c[i]!=0){cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
  return 0;
}

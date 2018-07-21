#include <bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  if(a==b){cout<<"Yes"<<endl;return 0;}
  for(int i=0;i<a.size();i++){
    string t=a.substr(a.size()-1,1);
    a.pop_back();
    a=t+a;
    if(a==b){cout<<"Yes"<<endl;return 0;}
  }
  cout<<"No"<<endl;
  return 0;
}

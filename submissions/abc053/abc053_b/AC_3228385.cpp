#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  string s;
  cin>>s;
  int b=-1,e;
  rep(i,s.size()){
    if (s[i]=='A' and b==-1) b=i;
    if (s[i]=='Z') e=i;
  }
  cout<<(e-b+1)<<endl;
  return 0;
}

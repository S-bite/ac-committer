#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  string s,ans;
  cin>>s;
  rep(i,s.size()){
    if (s[i]=='0') ans+="0";
    if (s[i]=='1') ans+="1";
    if (s[i]=='B' and ans.size()!=0) ans.pop_back();

  }
  cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int ans=0,now=0;
  for(int i=0;i<n;i++){
    if(s[i]=='I')now++;else now--;
    ans=max(ans,now);
  }
  cout<<ans<<endl;
}

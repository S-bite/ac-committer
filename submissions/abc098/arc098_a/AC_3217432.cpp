#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int w_right=0,e_right=0;
  rep(i,n)if (s[i]=='W') w_right++;else e_right++;
  int ans=n;
  int w_left=0,e_left=0;
  rep(i,n){
    ans=(s[i]=='W')?min(ans,w_left+e_right):min(ans,w_left+e_right-1);
    if (s[i]=='W') {w_right--;w_left++;}
    else{e_right--;e_left++;}
  }
  cout<<ans<<endl;
  return 0;
}

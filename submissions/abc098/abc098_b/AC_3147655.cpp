#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
int f(int a[26],int b[26]){
  int ret=0;
  rep(i,26) if(a[i]!=0 and b[i]!=0) ret++;
  return ret;
}
int main(){
  int n;
  string s;
  cin>>n>>s;
  int h[26]={},t[26]={};
  rep(i,s.size()) t[(int)s[i]-'a']++;
  int ans=0;
  rep(i,s.size()){
    t[(int)s[i]-'a']--;
    h[(int)s[i]-'a']++;
    ans=max(ans,f(h,t));
  }
  cout<<ans<<endl;
  return 0;
}

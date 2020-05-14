#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,l;
  cin>>n>>l;
  string s;
  cin>>s;
  int ans=0;
  int cur=1;
  for (int i=0;i<n;i++){
    if(s[i]=='+'){
      cur++;
    }else{
      cur--;
    }
    if (cur>l){
      cur=1;
      ans++;
    }
  }
  cout<<ans<<endl;
}

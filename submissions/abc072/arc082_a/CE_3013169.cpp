#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  map<int,int>m;
  for(int i=0;i<N;i++){
    int t;
    cin>>t;
    m[t]++;
    m[t+1]++;
    m[t-1]++;
  }

  int ans=-1;
  for(const auto &[_,v]:m)ans=max(ans,v);
  cout<<ans<<endl;
}

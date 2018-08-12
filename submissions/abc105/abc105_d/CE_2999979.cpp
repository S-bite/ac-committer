#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
map<int,int> m;
  int tmp=0;
  for(int i=1;i<N+1;i++){
    int t;
    cin>>t;
    m[(tmp+t)%M]++;
    tmp=(tmp+t)%M;
  }
  long long ans=0;
  for (auto& [key, v]:m)if(key==0)ans+=v*(v-1)/2+v;else ans+=v*(v-1)/2;
  cout<<ans<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int df(int s,int p,map<int,vector<int> >a, int d,int N){
//  cout<<s<<","<<p<<","<<((1<<(N))-1)<<d<<endl;
  if (d==N-1) return (s==(1<<(N))-1)?1:0;
  int ret=0;
  for(auto itr = a[p].begin(); itr != a[p].end(); ++itr) {
    ret+=df(s^(1<<(*itr-1)),*itr,a,d+1,N);
  }
  return ret;
}
int main(){
  int N,M;
  cin>>N>>M;
  map<int,vector<int> >a;
  for(int i=0;i<M;i++){
    int t,s;
    cin>>t>>s;
    a[t].push_back(s);
    a[s].push_back(t);
  }
  cout<<df(1,1,a,0,N)<<endl;
  return 0;
}

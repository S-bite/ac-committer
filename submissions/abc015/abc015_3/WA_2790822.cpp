#include<bits/stdc++.h>
#define vec vector<int>
#define vec2d vector<vector<int> >

using namespace std;

bool s(vec2d T,int N,int K,int c,int d){
  if (d==N-1) return (c==0);
  for(int i=0;i<K;i++){
    if(s(T,N,K,c xor T[d][i],d+1)) return true;
  }
  return false;
}
int main(){
  int N,K;
  cin>>N>>K;
  vec2d T(N,vec(K,0));
  for(int i=0;i<N;i++)for(int j=0;j<K;j++)cin>>T[i][j];
  cout<<(s(T,N,K,0,0)?"Found":"Nothing")<<endl;
}

#include<bits/stdc++.h>
using namespace std;

long long int bfs(int x[],int nc,int np,int c,int A,int N){
  if(c==N) {
    if(nc!=0 && np%nc && np/nc==A) return 1;
    else return 0;
  }

  long long ret=0;
  //cout<<x<<",<<"<<nc<<","<<np<<","<<c<<endl;
  ret+=bfs(x,nc+1,np+x[c],c+1,A,N);
  ret+=bfs(x,nc,np,c+1,A,N);
  return ret;
}
int main(){
  int N,A;
  cin>>N>>A;

  int x[N];

  for(int i=0;i<N;i++){
    cin>>x[i];
  }
  cout<<bfs(x,0,0,0,A,N)<<endl;
  return 0;
}

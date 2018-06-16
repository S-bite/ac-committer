#include <bits/stdc++.h>
using namespace std;

long long int s(int N, int M, int fx,int fy,int fz,long long int x[],long long int y[],long long int z[]){
  long long int a[N];
  for (int i=0; i<N; i++){
    a[i]=(long long int)fx*x[i]+(long long int)fy*y[i]+(long long int)fz*z[i];
  }
  sort(a,a+N,greater<long long int>());
  long long int res;
  res=0;
  for (int i=0; i<M;i++){
    res+=a[i];
  }
  return res;

}

int main(){
  int N,M;
  cin>>N>>M;
  long long int x[N],y[N],z[N];
  for (int i=0; i<N;i++){
    cin>>x[i]>>y[i]>>z[i];
  }
  cout<<max({
    s(N,M,1,1,1,x,y,z),
    s(N,M,1,1,-1,x,y,z),
    s(N,M,1,-1,1,x,y,z),
    s(N,M,1,-1,-1,x,y,z),
    s(N,M,-1,1,1,x,y,z),
    s(N,M,-1,1,-1,x,y,z),
    s(N,M,-1,-1,1,x,y,z),
    s(N,M,-1,-1,-1,x,y,z)}
  )<<endl;

}

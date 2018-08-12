#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  int A[N+1];
  A[0]=0;
  int tmp=0;
  for(int i=1;i<N+1;i++){
    int t;
    cin>>t;
    A[i]=(tmp+t)%M;
    tmp=(tmp+t)%M;
  }
  long long ans=0;
  for(int i=0;i<N;i++) for(int j=i+1;j<N+1;j++) if((A[j]-A[i])%M==0) ans++;
  cout<<ans<<endl;
  return 0;
}

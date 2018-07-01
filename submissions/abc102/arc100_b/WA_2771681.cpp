#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int A[N];
  long long int s=0;
  for (int i=0;i<N;i++){
    long long int t;
    cin>>t;
    A[i]=t;
    s+=t;
    }
  long long int K=s/4;
  long long int D[4]={0,0,0,0};
  int j=0;
  for(int i=0;i<N;i++){
      if((abs(K-(D[j]+A[i]))<abs(K-D[j]) or D[j]==0)and(N-i)>3-j ){D[j]+=A[i];}
      else {j++;D[j]+=A[i];}
  }
  sort(D,D+4);
  cout<<abs(D[0]-D[3])<<endl;
}

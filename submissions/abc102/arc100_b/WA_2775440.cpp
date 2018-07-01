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
  long long int _s=s;
  long long int K=s/4;
  long long int D[4]={0,0,0,0};
  int j=0;
  for(int i=0;i<N;i++){
      if((abs(K-(D[j]+A[i]))<abs(K-D[j])  or D[j]==0)and((N-i)>(3-j))){D[j]+=A[i];}
      else {j++;D[j]+=A[i];
          s-=D[j-1];
          K=s/(4-j);
      }
  }
  s=_s;
  long long int r_D[4]={0,0,0,0};
  j=0;
  for(int i=N-1;i>=0;i--){
      if((abs(K-(r_D[j]+A[i]))<abs(K-r_D[j])  or r_D[j]==0)and(i+1>(3-j))){r_D[j]+=A[i];}
      else {j++;r_D[j]+=A[i];
        s-=r_D[j-1];
        K=s/(4-j);}
  }


  sort(D,D+4);

  sort(r_D,r_D+4);
  cout<<min({abs(D[0]-D[3]),abs(r_D[0]-r_D[3])})<<endl;
}

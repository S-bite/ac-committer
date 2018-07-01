#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int A[N];
  for (int i=0;i<N;i++){
    long long int t;
    cin>>t;
    A[i]=t-(i+1);
    }
  sort(A,A+N);
  long long int K=A[(N)/2];
  long long int ans=0;
  for(int i=0;i<N;i++){
    ans+=abs(A[i]-K);
  }
  cout<<ans<<endl;
}

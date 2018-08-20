#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  unsigned long long A,B;
  cin>>A>>B;
  for(int i=1;i<N;i++){
    //cout<<A<<","<<B<<endl;

  unsigned  long long t,s;
    cin>>t>>s;
    long long c=max((A+t-1)/t,(B+s-1)/s);
    A=t*max(c,(long long)1);
    B=s*max(c,(long long)1);
  }
  cout<<(unsigned long long)(A+B)<<endl;
  //cout<<(unsigned long long)1000000000000000000<<endl;
  return 0;
}

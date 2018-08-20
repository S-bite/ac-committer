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
    int c=max((A+t-1)/t,(B+s-1)/s);
    A=t*max(c,1);
    B=s*max(c,1);
  }
  cout<<(A+B)<<endl;
  return 0;
}

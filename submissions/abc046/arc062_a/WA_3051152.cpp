#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long A,B;
  cin>>A>>B;
  for(int i=1;i<N;i++){
    long long t,s;
    cin>>t>>s;

    while(true) {
      if(t>=A and s>=B) break;
      t+=t;
      s+=s;
    //  cout<<A<<endl;
    }
    A=t;
    B=s;
  //  cout<<A<<","<<B<<endl;
  }
  cout<<(A+B)<<endl;
  return 0;
}

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
    int c=1;
    while(true) {
      //cout<<t<<","<<s<<endl;
      if(t*c>=A and s*c>=B) break;
      c++;
    }
    A=t*c;
    B=s*c;
  //  cout<<A<<","<<B<<endl;
  }
  cout<<(A+B)<<endl;
  return 0;
}

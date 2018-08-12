#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  if (N==0) {cout<<"0"<<endl; return 0;}
  string base="";
while(N){
//  cout<<(N%-2)<<","<<N<<endl;
    if(abs(N%-2)==1){base+="1";}
    else{base+="0";}
    N-=abs(N%-2);
    N/=-2;
  }
    reverse(base.begin(),base.end());
    cout<<base<<endl;
  return 0;
}

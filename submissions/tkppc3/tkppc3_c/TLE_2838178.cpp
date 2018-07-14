#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,P;
  cin>>N>>P;
  int a[N];
  bool f=false;
  for(int i=0;i<N;i++) cin>>a[i];
  for(int i=0;i<N;i++){
    int r=1;
    for(int j=0;j<N-i;j++){
    //  cout<<r<<","<<i<<","<<j<<endl;
      r*=a[i+j];
      if (r>P) break;
      if (r==P) {f=true;break;}
    }
    if(f) break;
  }
  if(f)cout<<"Yay!"<<endl; else cout<<":("<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int index,biggest=0;
  for(int i=0;i<N;i++){
    int t;
    cin>>t;
    if(abs(t)>abs(biggest)){biggest=t;index=i;}
  }
  index++;//convert to 1-started
  cout<<2*N-1<<endl;
  for(int i=1;i<N+1;i++)cout<<index<<" "<<i<<endl;
  if (biggest>0){
    for(int i=1;i<N;i++)cout<<i<<" "<<i+1<<endl;
  }else{
    for(int i=N;i>=2;i--)cout<<i<<" "<<i-1<<endl;
  }
  return 0;
}

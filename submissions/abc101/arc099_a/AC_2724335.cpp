#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  int index=0;
  for (int i=0;i<N;i++){
  int tmp;
  cin>>tmp;
  if(tmp==1){
    index=i;
    break;
  }}
  int lr=index;
  int rr=N-index-1;
  int ans=0;
  if (N==K) ans=1;
  else ans=lr/(K-1)+rr/(K-1)+((rr%(K-1)+lr%(K-1)-1)/(K-1)+1);
  cout<<ans<<endl;
  }

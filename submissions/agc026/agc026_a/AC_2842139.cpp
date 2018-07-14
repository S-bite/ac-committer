#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int ans=0,cnt=0,t=-1;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a!=t){
      ans+=cnt/2;
      t=a;
      cnt=1;
    }
    else cnt++;
  }
  ans+=cnt/2;
  cout<<ans<<endl;
}

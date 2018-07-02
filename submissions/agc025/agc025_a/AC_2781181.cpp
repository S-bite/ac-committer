#include <bits/stdc++.h>
using namespace std;
int f(int n){
  int res=0;
  while(n){
    res+=n%10;
    n/=10;
  }
  return res;
}

int main(){
  int N;
  int ans=65536;

  cin>>N;
  for (int i=1;i<N/2+1;i++){
    if (ans>(f(i)+f(N-i))){
      ans=(f(i)+f(N-i));
    }
  }
  cout<<ans<<endl;
}

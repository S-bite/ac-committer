#include <bits/stdc++.h>
using namespace std;
int f(int a){
  int k=1;
  while (true){
    if (a%(int)powf(2,k)!=0) break;
    k++;
  }
  return k-1;
}

int main(){
  int N,ans;
  ans=0;
  cin>>N;
  for (int i=0;i<N;i++){
    int a;
    cin>>a;
    ans+=f(a);
  }
  cout<<ans<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int s(int a){
  int res=0;
  while (a){
    res+=a%10;
    a/=10;
  }
  return res;
}
int main(){
  int K;
  cin>>K;
  if (K<10){
    for (int i=0;i<K;i++){
      cout<<i+1<<endl;
    }

  }
  else{
    for (int i=0;i<9;i++){
      cout<<i+1<<endl;
    }
      K-=9;
      for (int i=0;i<K;i++){
        cout<<(long long int)(i+1)*10+9<<endl;
      }

  }
}

#include<bits/stdc++.h>
using namespace std;
int myPow(int x, int p) {
  if (p == 0) return 1;
  if (p == 1) return x;
  return x * myPow(x, p-1);
}
int main(){
  int N,K;
  cin>>N>>K;
  if (N==1) cout<<K<<endl;
  else cout<<(K*myPow(K-1,N-1) )<<endl;
  return 0;
}

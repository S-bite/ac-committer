#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int N;
  cin>>N;
  long long int s=0;
  long long int d=1;
  while(N){
    s+=N%10;
    N/=10;
  }
  if(N%s==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  }

#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int N;
  cin>>N;
  int tmp=N;
  int s=0;
  while(tmp){
    s+=tmp%10;
    tmp/=10;
  }
  if(N%s==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  }

#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
int m=N/7;
if (m*7==N){ cout<<"Yes"<<endl;return 0;}

while (m>=0){
  if((N-m*7)%4==0){cout<<"Yes"<<endl;return 0;}
  m--;
}
  cout<<"No"<<endl;
  return 0;
}

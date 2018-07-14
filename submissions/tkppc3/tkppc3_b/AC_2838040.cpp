#include<bits/stdc++.h>
using namespace std;
int main(){
  int m3=0,m11=0,m2=0;
  bool f=true;
  char c;
  while(cin>>c){
    int i=(int)c-'0';
    m3=(m3+i)%3;
    if(f) m11+=i; else m11-=i;
    f^=1;
    m2=i%2;
  }
  if(m2==0 and m3==0)cout<<"yES"<<endl;else cout<<"nO"<<endl;
  if(m11%11==0)cout<<"yES"<<endl;else cout<<"nO"<<endl;
}

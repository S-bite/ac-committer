#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
int a,b;
cin>>a>>b;
if (a>0) {
  cout<<"Positive"<<endl;
  return 0;
}
if (a<=0 and b>=0){
  cout<<"Zero"<<endl;
  return 0;
}
if((b-a)%2==1){
  cout<<"Positive"<<endl;
}else{
  cout<<"Negative"<<endl;
}

return 0;
}

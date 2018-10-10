#include<bits/stdc++.h>
using namespace std;
int main (){
  int x,y;
  cin>>x>>y;
  int ans;
  if (x>=0 and y>=0){
    if(y>x) ans=(y-x);
    else ans=(x-y+2);
  }
  if (x<0 and y>=0) ans=abs(abs(x)-abs(y))+1;
  if (x<0 and y<=0) {
    if(y>x) ans=abs(x)-abs(y);
    else ans=abs(y)-abs(x)+2;
  }
  if(x>=0 and y<=0)ans=abs(abs(x)-abs(y))+1;
  cout<<ans<<endl;
  return 0;
}

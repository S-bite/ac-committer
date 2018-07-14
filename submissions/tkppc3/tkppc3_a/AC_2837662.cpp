#include<bits/stdc++.h>
using namespace std;
int main(){
  char c,d;
  int a,b;
  cin>>c>>a>>d>>b;
  if(c=='W')a=-a;
  if(d=='W')b=-b;
  cout<<abs(a-b)/15<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int rest=a+b+c-max({a,b,c});
  cout<<rest+max({a,b,c})*powf(2,k)<<endl;
}

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int f(int x,int y){
  return floor(pow(floor(pow(x,1.0/y)),y));
}
int main(){
  int x;
  cin>>x;

  cout<<max({f(x,2),f(x,3),f(x,5),f(x,7)})<<endl;
}

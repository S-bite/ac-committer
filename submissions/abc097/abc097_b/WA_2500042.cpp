#include<bits/stdc++.h>
#include<math.h>
using namespace std;
double f(int x,int y){
  //cout<<floor(pow(x,1.0/y))<<endl;
  return pow(floor(pow(x,1.0/y)),y);
}
int main(){
  int x;
  cin>>x;
  cout<<max({f(x,2),f(x,3),f(x,4),f(x,5),f(x,6),f(x,7),f(x,8),f(x,9),f(x,10)})<<endl;
}

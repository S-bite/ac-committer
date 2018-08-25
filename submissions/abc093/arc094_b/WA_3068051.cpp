#include<bits/stdc++.h>
using namespace std;
int doublling(long long x,long long y){
  int ret=0;
  long long t=x*y-1;
  if ((x==1) && (floor(t/(x))!=floor(t/(x+1)))) ret++;
  else if (floor(t/(x))!=floor(t/(x-1)) && (floor(t/(x))!=floor(t/(x+1)))) ret++;
//  cout<<"x:"<<x<<",y:"<<y<<",ret:"<<ret<<endl;
  return ret;
}
int check(long long x,long long y){
  if ( floor((x*y-1)/floor(sqrt((x*y-1))))==floor(sqrt((x*y-1)))) return 1;
  else return 0;
}
int main(){
  int Q;
  cin>>Q;
  for (int i=0;i<Q;i++){
    long long x,y;
    cin>>x>>y;
  //  cout<<(isusebothside(x,y)?"t":"f")<<endl;
    cout<<setprecision(20)<<2*(floor(sqrt(x*y-1)))-check(x,y)-doublling(x,y)-doublling(y,x)<<endl;
  }
  return 0;
}

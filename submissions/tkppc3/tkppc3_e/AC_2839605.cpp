#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
cin>>N;
double av=(double)(N+1)/2;
double ans=0.0;
double p=1.0;
for(int i=N;i>0;i--){
//  cout<<av<<","<<i<<","<<N<<","<<p<<endl;
  ans+=av*p;
//  cout<<ans<<endl;
  p*=((double)(i-1)/N);
}

cout<<fixed<<setprecision(14)<<ans<<endl;
}

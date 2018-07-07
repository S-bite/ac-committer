#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int n,m,d;
  cin>>n>>m>>d;
  cout<<fixed<<setprecision(10)<<(double)((double)(m-1)*(n-d+1)/(n*n))<<endl;
}

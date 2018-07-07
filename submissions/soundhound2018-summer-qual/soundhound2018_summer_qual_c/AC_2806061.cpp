#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int n,m,d;
  cin>>n>>m>>d;
  if (d==0)cout<<fixed<<setprecision(10)<<(double)((double)(m-1)*(n-d)/(n*n))<<endl;
    else cout<<fixed<<setprecision(10)<<(double)((double)(m-1)*2*(n-d)/(n*n))<<endl;
}

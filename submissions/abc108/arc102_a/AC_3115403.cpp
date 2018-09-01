#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,k;
  cin>>n>>k;
  long long ans=(n/k)*(n/k)*(n/k);
  //cout<<ans<<endl;
  if (k%2==0) ans+=(n/(k/2)-n/k)*(n/(k/2)-n/k)*(n/(k/2)-n/k);
  cout<<ans<<endl;
  return 0;
}

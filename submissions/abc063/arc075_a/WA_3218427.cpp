#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n],sum=0;
  rep(i,n){
    int t;
    cin>>t;
    sum+=t;
    a[i]=t;
  }
  sort(a,a+n);
  rep(i,n) {
    if (sum%10!=0){
      cout<<sum<<endl;
      return 0;
    }
    if (a[i]%10!=0)sum-=a[i];
  }
  cout<<sum<<endl;
  return 0;
}

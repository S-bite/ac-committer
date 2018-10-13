#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(long long i=0;i<(ll)(n);i++)
using namespace std;

int main(){
  int n,odd=0;
  cin>>n;
  rep(i,n){
      int t;
      cin>>t;
      if(t%2==1) odd++;
  }
  if(odd%2==0)cout<<"YES"<<endl;else cout<<"NO"<<endl;
  return 0;
}

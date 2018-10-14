#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(long long i=0;i<(ll)(n);i++)
#define fir first
#define sec second

using namespace std;
int main(){
  int n;
  cin>>n;
  rep(i,n){
    rep(j,n){
      if ((j==n-1 and i%2==1) or (i%2==0 and j%==0 ) or (i%2==1 and j%4==2))cout<<"x";
      else cout<<".";
    }
    cout<<endl;
}
  return 0;
}

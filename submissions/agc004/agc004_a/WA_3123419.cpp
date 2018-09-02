#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  cout<<min({abs(a*b*(c/2)-a*b*((c+1)/2)),abs(b*c*(a/2)-b*c*((a+1)/2)),abs(c*a*(b/2)-c*a*((b+1)/2))})<<endl;
  return 0;
}

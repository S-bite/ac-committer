#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
using namespace std;


int main(){
  int n,m;
  cin>>n>>m;
  int x[n+1],y[m+1];
  cin>>x[0]>>y[0];
  rep(i,n)cin>>x[i+1];
  rep(i,m)cin>>y[i+1];
  sort(x,x+n+1,greater<int>());
  sort(y,y+m+1);
  if (x[0]<y[0]) cout<<"No War"<<endl;
  else cout<<"War"<<endl;
  return 0;
}

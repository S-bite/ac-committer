#include <bits/stdc++.h>
using namespace std;
int main(){
	int g[13]={-1,1,3,1,2,1,2,1,1,2,1,2,1};
  	int a,b;
  cin>>a>>b;
  if(g[a]==g[b]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
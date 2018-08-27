#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
	int ans=0;
  rep(i,3){
  int s,p;
    cin>>s>>p;
  	ans+=s/10*p;
  }
  cout<<ans<<endl;
  return 0;
}

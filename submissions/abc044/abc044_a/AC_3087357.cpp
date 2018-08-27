#include<bits/stdc++.h>
using namespace std;
int main(){
  	int n,k,x,y;
  cin>>n>>k>>x>>y;
	if(n<=k) cout<<(n*x)<<endl;
  else cout<<(k*x)+y*(n-k)<<endl;
    return 0;
}

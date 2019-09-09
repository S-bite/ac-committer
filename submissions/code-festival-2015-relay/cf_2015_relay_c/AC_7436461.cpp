#include<bits/stdc++.h>
using namespace std;
int main(){

  string pi="3141592653589793238462643383279502884";
  int n;
  cin>>n;
  for (int i=0;i<pi.size();i++){
  	if  (pi[i]-'0'==n){
    	cout<<i<<endl;
      	return 0;
    }
  }
}

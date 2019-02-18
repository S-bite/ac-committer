#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
	string s="";
   	for(int j=2;j<=6;j++){
    	if (i%j==0)s+=('a'-2+j);
    }
    if (s=="") s=to_string(i);
  	cout<<s<<endl;
  }
  return 0;
}

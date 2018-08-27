#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	int n;
  cin>>s>>n;
//	for(n=1;n<26;n++)
	cout<<s[(n-1)/5]<<s[(n+4)%5]<<endl;
  return 0;
}

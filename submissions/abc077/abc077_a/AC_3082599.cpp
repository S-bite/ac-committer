#include<bits/stdc++.h>
using namespace std;
int main(){
  string s1,s2;
  cin>>s1>>s2;
	if(s1[0]==s2[2] and s1[1]==s2[1] and s1[2]==s2[0]) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main(){
	string s1,s2;
  cin>>s1>>s2;
  rep(i,min(s1.size(),s2.size())) cout<<s1[i]<<s2[i];
	if (s1.size()>s2.size()) cout<<s1[s1.size()-1]<<endl;
	else if (s1.size()<s2.size()) cout<<s2[s2.size()-1]<<endl;
	else cout<<endl;
  return 0;
}

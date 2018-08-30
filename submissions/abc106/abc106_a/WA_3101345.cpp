#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
int main(){
  	string s;
  	int k;
  	cin>>s>>k;
  	rep(i,min((int)s.size(),k)) if (s[i]!='1') {cout<<s[i]<<endl;return 0;}
	cout<<"1"<<endl;
  return 0;
}
